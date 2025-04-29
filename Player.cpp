#include "Player.h"
#include "DxLib.h"
#include "Ball.h"
#include <vector>

Player::Player(int screenWidth) :
	SCREEN_WIDTH(screenWidth)
{

}


void Player::Init()
{
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
	if (ball.isActive)
	{
		return; // すでに弾が発射されている場合は何もしない
	}
	else
	{
		ball.x = this->x + WIDTH/2; // プレイヤーの中心から弾を発射
		ball.y = this->y;
		ball.isActive = true;
	}
}


void Player::Move(char buf[])
{
	//入力情報をもとに移動する
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
	if (x + WIDTH > SCREEN_WIDTH) x = SCREEN_WIDTH - WIDTH;
}

void Player::PlayerDraw()
{
	DrawBox(x, y, x + WIDTH, y + HEIGHT, GetColor(255, 255, 255), TRUE);
}