#pragma once
#ifndef UTILS_H
#define UTILS_H

class Ball
{
public:
	Ball(int screenWidth, int screenHeight);
	float x = 0.0f;
	float y = 0.0f;
	float velocityX = 2.0f;
	float velocityY = -2.0f;
	bool isActive = false;
	inline float GetRadius() const { return RADIUS; }

	/// <summary>
	/// �{�[���̏���������
	/// </summary>
	void Init();

	/// <summary>
	/// �{�[������ʂ̉��ɍs���������肷��
	/// </summary>
	/// <returns></returns>
	bool IsOutOfBounds() const;

	/// <summary>
	/// �{�[���̍X�V����
	/// </summary>
	void UpdateBall();


private:
	const int SCREEN_WIDTH;
	const int SCREEN_HEIGHT;
	const float RADIUS = 5.0f;
	/// <summary>
	/// �{�[���̕`�揈��
	/// </summary>
	void DrawBall();
};

#endif