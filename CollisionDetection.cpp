#include "CollisionDetection.h"
#include "Block.h"
#include "Ball.h"
#include <vector>

void CollisionDetection::CheckCollision(Ball& ball, std::vector<Block>& blocks, Player& player)
{
	if (!ball.isActive)
	{
		return; // �e�����˂���Ă��Ȃ��ꍇ�͉������Ȃ�
	}
	BallBlockCollision(ball, blocks); // �e�ƃu���b�N�̏Փ˔���
	PlayerBallCollision(ball, player); // �v���C���[�ƒe�̏Փ˔���
}

void CollisionDetection::BallBlockCollision(Ball& ball, std::vector<Block>& blocks)
{

	for (std::size_t i = 0; i < blocks.size(); i++)
	{
		if (!blocks[i].isActive)
		{
			continue; // �u���b�N����A�N�e�B�u�ȏꍇ�̓X�L�b�v
		}

		bool collideX = (ball.x >= blocks[i].xPosition && ball.x <= blocks[i].xPosition + blocks[i].GetWidth());
		bool collideY = (ball.y >= blocks[i].yPosition && ball.y <= blocks[i].yPosition + blocks[i].GetHeight());

		if (collideX && collideY)
		{
			blocks[i].isActive = false; // �u���b�N���A�N�e�B�u�ɂ���

			if (fabs(ball.velocityY) > fabs(ball.velocityX))
			{
				ball.velocityX = -ball.velocityX; // x�����̔��]
			}
			else
			{
				ball.velocityY = -ball.velocityY; // y�����̔��]
			}
		}
	}
}

void CollisionDetection::PlayerBallCollision(Ball& ball, Player& player)
{
	bool collideX = (ball.x >= player.x && ball.x <= player.x + player.WIDTH);
	bool collideY = (ball.y >= player.y && ball.y <= player.y + player.HEIGHT);

	if (collideX && collideY)
	{
		ball.velocityY = -ball.velocityY; // y�����̔��]
	}
}
