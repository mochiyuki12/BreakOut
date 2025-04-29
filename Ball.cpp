#include "DxLib.h"
#include "Ball.h"


Ball::Ball(int screenWidth, int screenHeight) :
	SCREEN_WIDTH(screenWidth),
	SCREEN_HEIGHT(screenHeight)
{
	
}

void Ball::Init()
{
	// �e�̏�����
	x = 0.0f;
	y = 0.0f;
	velocityX = 2.0f; // x�����̑��x
	velocityY = -2.0f; // y�����̑��x
	isActive = false; // ������Ԃł͔�A�N�e�B�u
}


bool Ball::IsOutOfBounds() const
{
	if (y > SCREEN_HEIGHT)
	{
		return true; // ��ʊO
	}
	return false; // ��ʓ�
}

void Ball::UpdateBall()
{
	// �{�[������ʂ̉��ɏo�����A�N�e�B�u�ɂ���
    if (y <= 0)
    {
        isActive = false;
        return;
    }

	//�e�̈ړ�
	x += velocityX;
	y += velocityY;

	//��ʂ̍��E�̒[�ɓ��������甽�]
    if (x - RADIUS <= 0 || x + RADIUS >= SCREEN_WIDTH)
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