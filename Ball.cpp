#include "DxLib.h"
#include "Ball.h"

void Ball::Init()
{
	// �e�̏�����
	x = 0;
	y = 0;
	velocityX = 2; // x�����̑��x
	velocityY = -2; // y�����̑��x
	isActive = false; // ������Ԃł͔�A�N�e�B�u
}

bool Ball::IsOutOfBounds() const
{
	// �e����ʊO�ɏo�����ǂ����𔻒�
	if (y > 480)
	{
		return true; // ��ʊO
	}
	return false; // ��ʓ�
}

void Ball::UpdateBall()
{
    if (y <= 0)
    {
        isActive = false;
        return;
    }

	//�e�̈ړ�
	x += velocityX;
	y += velocityY;

	//��ʂ̍��E�̒[�ɓ��������甽�]
    if (x - RADIUS <= 0 || x + RADIUS >= 640)
    {
        velocityX = -velocityX;
    }
	//��ʂ̏�ɓ��������甽�]
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