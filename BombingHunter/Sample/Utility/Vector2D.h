#pragma once

//2次元ベクトル用クラス
class Vector2D
{
public:
	float x;	//x成分
	float y;	//y成分

public:

	//コンストラクタ
	Vector2D();

	/*
	* コンストラクタ
	* 説明
	*	引数の値を使用してx成分とy成分を初期化する
	* 引数
	*	float scalar x成分、y成分初期化用のデータ
	*/
	Vector2D(float scalar);

	/*
	* コンストラクタ
	*/
	Vector2D(float mx, float my);

	//デストラクタ
	~Vector2D();

public:
	//演算子オーバーロード
	Vector2D& operator=(const Vector2D& location);

	const Vector2D operator+(const Vector2D& location) const;
	Vector2D& operator+=(const Vector2D& location);

	const Vector2D operator-(const Vector2D& location) const;
	Vector2D& operator-=(const Vector2D& location);

	const Vector2D operator*(const float& scalar) const;
	const Vector2D operator*(const Vector2D& location) const;
	Vector2D& operator*=(const float& scalar);
	Vector2D& operator*=(const Vector2D& location);

	const Vector2D operator/(const float& scalar) const;
	const Vector2D operator/(const Vector2D& location) const;
	Vector2D& operator/=(const float& scalar);
	Vector2D& operator/=(const Vector2D& location);

	/*
	* 整数型データに変換
	* 説明
	*
	*/
	void ToInt(int* x, int* y) const;
};
