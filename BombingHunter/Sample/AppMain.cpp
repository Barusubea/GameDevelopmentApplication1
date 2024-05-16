#include"DxLib.h"
#include "Utility/InputControl.h"
#include "Scene/Scene.h"

//��������v���O�������J�n����
int WINAPI WinMain(_In_ HINSTANCE hinstance, _In_opt_ HINSTANCE hPrevinstance, _In_
	LPSTR ipCmdLine, _In_ int nShowCmd)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//Dx���C�u�����̏���������
	if (DxLib_Init() == -1)
	{
		//�ُ��ʒm
		return -1;
	}

	//���[�J���ϐ���`
	Scene* scene = new Scene();			//�V�[�����
	int result = 0;						//�I����ԏ��

	//�`���𗠉�ʂ���n�߂�悤�Ɏw�肷��
	SetDrawScreen(DX_SCREEN_BACK);

	try
	{
		//�V�[���̏�����
		scene->Initialize();

		//���C�����[�v�i�E�B���h�E�ُ̈픭�� or ESC�L�[�������ꂽ��A���[�v�I��)
		while (ProcessMessage() != -1 && CheckHitKey(KEY_INPUT_ESCAPE) != TRUE)
		{
			//���͍X�V����
			InputControl::Update();

			//�V�[���X�V����
			scene->Update();

			//��ʂ̏�����
			ClearDrawScreen();

			//�V�[���̕`�揈��
			scene->Draw();

			//����ʂ̓��e��\��ʂɔ��f����
			ScreenFlip();

		}

	}
	catch (const char* error_log)
	{
		//�G���[����Log.txt�ɏo�͂���
		OutputDebugString(error_log);
		//�ُ펖�ԂɕύX����
		result = -1;

	}

	//�V�[�����̍폜����
	if (scene != nullptr)
	{
		scene->Finalize();
		delete scene;
		scene = nullptr;

	}

	//Dx���C�u�����̏I��������
	DxLib_End();

	//�I����Ԃ�ʒm
	return result;
}