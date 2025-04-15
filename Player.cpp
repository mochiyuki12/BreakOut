#include "Player.h"

#include "DxLib.h"

#include <vector>


void Player::Move(char buf[])
{
	if (buf[KEY_INPUT_RIGHT] == 1)
	{
		x += velocity;
	}
	if (buf[KEY_INPUT_LEFT] == 1)
	{
		x -= velocity;
	}

	if (x < 0) x = 0;
	if (x + _width > 640) x = 640 - _width;
	DrawBox(x, y,x + _width, y + _height, GetColor(255, 255, 255), TRUE);
}