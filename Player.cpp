#include "Player.h"
#include "DxLib.h"
#include "Ball.h"
#include <vector>

void Player::Init()
{
	// プレイヤーの初期化処理
	x = 290; // 初期位置
	y = 400; // 初期位置
}

void Player::PlayerUpdate(char buf[])
{
	Move(buf);
	PlayerDraw();
}
void Player::Shoot(Ball& ball)
{
	// 弾を発射する処理
	if (ball.isActive)
	{
		return; // すでに弾が発射されている場合は何もしない
	}
	else
	{
		ball.x = this->x + 30; // プレイヤーの中心から弾を発射
		ball.y = this->y;
		ball.isActive = true;
	}
}

void Player::Move(char buf[])
{
	if (buf[KEY_INPUT_RIGHT] == 1)
	{
		x += SPEED;
	}
	if (buf[KEY_INPUT_LEFT] == 1)
	{
		x -= SPEED;
	}

	// プレイヤーの移動範囲を制限
	if (x < 0) x = 0;
	if (x + WIDTH > 640) x = 640 - WIDTH;
}

void Player::PlayerDraw()
{
	DrawBox(x, y, x + WIDTH, y + HEIGHT, GetColor(255, 255, 255), TRUE);
}