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
	/// ボールの初期化処理
	/// </summary>
	void Init();

	/// <summary>
	/// ボールが画面の下に行ったか判定する
	/// </summary>
	/// <returns></returns>
	bool IsOutOfBounds() const;

	/// <summary>
	/// ボールの更新処理
	/// </summary>
	void UpdateBall();


private:
	const int SCREEN_WIDTH;
	const int SCREEN_HEIGHT;
	const float RADIUS = 5.0f;
	/// <summary>
	/// ボールの描画処理
	/// </summary>
	void DrawBall();
};

#endif