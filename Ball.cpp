#include "DxLib.h"
#include "Ball.h"

Ball::Ball(int _x, int _y)
{
    x = _x;
    y = _y;
    radius = _radius;
	vectorX = 3;
	vectorY = 3;
    flag = true;
}

void Ball::UpdateBall()
{
    if (y <= 0)
    {
        flag = false;
        return;
    }

    if (x - radius <= 0 || x + radius >= 640) vectorX = -vectorX;
    if (y - radius <= 0) vectorY = -vectorY;


    y -= 2;
    DrawCircleAA(x, y, radius, 32, GetColor(255, 0, 0), TRUE);
}