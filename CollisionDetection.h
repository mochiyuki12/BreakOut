#pragma once
#include "Ball.h"
#include "Block.h"
#include "Player.h"
#include <vector>	

class CollisionDetection
{
public:
	/// <summary>
	/// �{�[�����Փ˂��������肵�A�������s��
	/// </summary>
	/// <param name="ball"></param>
	/// <param name="blocks">�u���b�N�̔z��</param>
	/// <param name="player"></param>
	void HandleCollisions(Ball& ball, std::vector<Block>& blocks, Player& player);

private:
	/// <summary>
	/// �{�[���ƃu���b�N�̏Փ˂𔻒肵�A�������s��
	/// </summary>
	/// <param name="ball"></param>
	/// <param name="blocks"></param>
	void BallBlockCollision(Ball& ball, std::vector<Block>& blocks);

	/// <summary>
	/// �{�[���ƃv���C���[�̏Փ˂𔻒肵�A�������s��
	/// </summary>
	/// <param name="ball"></param>
	/// <param name="player"></param>
	void PlayerBallCollision(Ball& ball, Player& player);
};