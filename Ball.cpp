#include "DxLib.h"
#include "Ball.h"


Ball::Ball(int screenWidth, int screenHeight) :
	SCREEN_WIDTH(screenWidth),
	SCREEN_HEIGHT(screenHeight)
{
	
}

void Ball::Init()
{
	// 弾の初期化
	x = 0.0f;
	y = 0.0f;
	velocityX = 2.0f; // x方向の速度
	velocityY = -2.0f; // y方向の速度
	isActive = false; // 初期状態では非アクティブ
}


bool Ball::IsOutOfBounds() const
{
	if (y > SCREEN_HEIGHT)
	{
		return true; // 画面外
	}
	return false; // 画面内
}

void Ball::UpdateBall()
{
	// ボールが画面の下に出たら非アクティブにする
    if (y <= 0)
    {
        isActive = false;
        return;
    }

	//弾の移動
	x += velocityX;
	y += velocityY;

	//画面の左右の端に当たったら反転
    if (x - RADIUS <= 0 || x + RADIUS >= SCREEN_WIDTH)
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