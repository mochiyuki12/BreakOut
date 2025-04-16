#pragma once
#include "Ball.h"
#include "Block.h"
#include "Player.h"
#include <vector>	

class CollisionDetection
{
public:
	void CheckCollision(Ball& ball, std::vector<Block>& blocks, Player& player);

private:
	void BallBlockCollision(Ball& ball, std::vector<Block>& blocks);
	void PlayerBallCollision(Ball& ball, Player& player);
};