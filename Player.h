#pragma once

#include "Ball.h"
#include <vector>

class Player
{
public:
	Player(int screenWidth);
	int x = 290;
	int y = 400;
	const int WIDTH = 60;
	const int HEIGHT = 20;

	/// <summary>
	/// プレイヤーの初期化処理
	/// </summary>
	void Init();

	/// <summary>
/// プレイヤーの更新処理
/// </summary>
/// <param name="buf">入力情報を入れてください</param>
	void PlayerUpdate(char buf[]);

	/// <summary>
/// 弾を発射する処理
/// </summary>
/// <param name="ball"></param>
	void Shoot(Ball& ball);

private:
	const int SCREEN_WIDTH;
	const int SPEED = 5;

	/// <summary>
/// プレイヤーの移動処理
/// </summary>
/// <param name="buf"></param>
	void Move(char buf[]);

	/// <summary>
	/// プレイヤーの描画処理
/// </summary>
	void PlayerDraw();
};