#include "Player.h"
#include "DxLib.h"
#include "Ball.h"
#include <vector>

void Player::Init()
{
	// �v���C���[�̏���������
	x = 290; // �����ʒu
	y = 400; // �����ʒu
}

void Player::PlayerUpdate(char buf[])
{
	Move(buf);
	PlayerDraw();
}
void Player::Shoot(Ball& ball)
{
	// �e�𔭎˂��鏈��
	if (ball.isActive)
	{
		return; // ���łɒe�����˂���Ă���ꍇ�͉������Ȃ�
	}
	else
	{
		ball.x = this->x + 30; // �v���C���[�̒��S����e�𔭎�
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

	// �v���C���[�̈ړ��͈͂𐧌�
	if (x < 0) x = 0;
	if (x + WIDTH > 640) x = 640 - WIDTH;
}

void Player::PlayerDraw()
{
	DrawBox(x, y, x + WIDTH, y + HEIGHT, GetColor(255, 255, 255), TRUE);
}