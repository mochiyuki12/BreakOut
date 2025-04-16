#include "CollisionDetection.h"
#include "Block.h"
#include "Ball.h"
#include <vector>

void CollisionDetection::CheckCollision(Ball& ball, std::vector<Block>& blocks, Player& player)
{
	if (!ball.isActive)
	{
		return; // 弾が発射されていない場合は何もしない
	}
	BallBlockCollision(ball, blocks); // 弾とブロックの衝突判定
	PlayerBallCollision(ball, player); // プレイヤーと弾の衝突判定
}

void CollisionDetection::BallBlockCollision(Ball& ball, std::vector<Block>& blocks)
{

	for (std::size_t i = 0; i < blocks.size(); i++)
	{
		if (!blocks[i].isActive)
		{
			continue; // ブロックが非アクティブな場合はスキップ
		}

		bool collideX = (ball.x >= blocks[i].xPosition && ball.x <= blocks[i].xPosition + blocks[i].GetWidth());
		bool collideY = (ball.y >= blocks[i].yPosition && ball.y <= blocks[i].yPosition + blocks[i].GetHeight());

		if (collideX && collideY)
		{
			blocks[i].isActive = false; // ブロックを非アクティブにする

			if (fabs(ball.velocityY) > fabs(ball.velocityX))
			{
				ball.velocityX = -ball.velocityX; // x方向の反転
			}
			else
			{
				ball.velocityY = -ball.velocityY; // y方向の反転
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
		ball.velocityY = -ball.velocityY; // y方向の反転
	}
}
