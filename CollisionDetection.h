#pragma once
#include "Ball.h"
#include "Block.h"
#include "Player.h"
#include <vector>	

class CollisionDetection
{
public:
	/// <summary>
	/// ボールが衝突したか判定し、処理を行う
	/// </summary>
	/// <param name="ball"></param>
	/// <param name="blocks">ブロックの配列</param>
	/// <param name="player"></param>
	void HandleCollisions(Ball& ball, std::vector<Block>& blocks, Player& player);

private:
	/// <summary>
	/// ボールとブロックの衝突を判定し、処理を行う
	/// </summary>
	/// <param name="ball"></param>
	/// <param name="blocks"></param>
	void BallBlockCollision(Ball& ball, std::vector<Block>& blocks);

	/// <summary>
	/// ボールとプレイヤーの衝突を判定し、処理を行う
	/// </summary>
	/// <param name="ball"></param>
	/// <param name="player"></param>
	void PlayerBallCollision(Ball& ball, Player& player);
};