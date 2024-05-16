#include"DxLib.h"
#include "Utility/InputControl.h"
#include "Scene/Scene.h"

//ここからプログラムを開始する
int WINAPI WinMain(_In_ HINSTANCE hinstance, _In_opt_ HINSTANCE hPrevinstance, _In_
	LPSTR ipCmdLine, _In_ int nShowCmd)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//Dxライブラリの初期化処理
	if (DxLib_Init() == -1)
	{
		//異常を通知
		return -1;
	}

	//ローカル変数定義
	Scene* scene = new Scene();			//シーン情報
	int result = 0;						//終了状態情報

	//描画先を裏画面から始めるように指定する
	SetDrawScreen(DX_SCREEN_BACK);

	try
	{
		//シーンの初期化
		scene->Initialize();

		//メインループ（ウィンドウの異常発生 or ESCキーが押されたら、ループ終了)
		while (ProcessMessage() != -1 && CheckHitKey(KEY_INPUT_ESCAPE) != TRUE)
		{
			//入力更新処理
			InputControl::Update();

			//シーン更新処理
			scene->Update();

			//画面の初期化
			ClearDrawScreen();

			//シーンの描画処理
			scene->Draw();

			//裏画面の内容を表画面に反映する
			ScreenFlip();

		}

	}
	catch (const char* error_log)
	{
		//エラー情報をLog.txtに出力する
		OutputDebugString(error_log);
		//異常事態に変更する
		result = -1;

	}

	//シーン情報の削除する
	if (scene != nullptr)
	{
		scene->Finalize();
		delete scene;
		scene = nullptr;

	}

	//Dxライブラリの終了時処理
	DxLib_End();

	//終了状態を通知
	return result;
}