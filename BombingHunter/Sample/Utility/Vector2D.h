#pragma once

//2�����x�N�g���p�N���X
class Vector2D
{
public:
	float x;	//x����
	float y;	//y����

public:

	//�R���X�g���N�^
	Vector2D();

	/*
	* �R���X�g���N�^
	* ����
	*	�����̒l���g�p����x������y����������������
	* ����
	*	float scalar x�����Ay�����������p�̃f�[�^
	*/
	Vector2D(float scalar);

	/*
	* �R���X�g���N�^
	*/
	Vector2D(float mx, float my);

	//�f�X�g���N�^
	~Vector2D();

public:
	//���Z�q�I�[�o�[���[�h
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
	* �����^�f�[�^�ɕϊ�
	* ����
	*
	*/
	void ToInt(int* x, int* y) const;
};
