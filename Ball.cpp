#include "DxLib.h"
#include "Ball.h"

void Ball::Init()
{
	// 弾の初期化
	x = 0;
	y = 0;
	velocityX = 2; // x方向の速度
	velocityY = -2; // y方向の速度
	isActive = false; // 初期状態では非アクティブ
}

bool Ball::IsOutOfBounds() const
{
	// 弾が画面外に出たかどうかを判定
	if (y > 480)
	{
		return true; // 画面外
	}
	return false; // 画面内
}

void Ball::UpdateBall()
{
    if (y <= 0)
    {
        isActive = false;
        return;
    }

	//弾の移動
	x += velocityX;
	y += velocityY;

	//画面の左右の端に当たったら反転
    if (x - RADIUS <= 0 || x + RADIUS >= 640)
    {
        velocityX = -velocityX;
    }
	//画面の上に当たったら反転
    if (y - RADIUS <= 0) 
    {
        velocityY = -velocityY; 
    }

    DrawBall();
    
}

void Ball::DrawBall()
{
	DrawCircleAA(x, y, RADIUS, 32, GetColor(255, 0, 0), TRUE);
}