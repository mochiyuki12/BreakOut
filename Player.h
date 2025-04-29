#pragma once

#include "Ball.h"
#include <vector>

class Player
{
public:
	Player(int screenWidth);
	int x = 290;
	int y = 400;
	const int WIDTH = 60;
	const int HEIGHT = 20;

	/// <summary>
	/// �v���C���[�̏���������
	/// </summary>
	void Init();

	/// <summary>
/// �v���C���[�̍X�V����
/// </summary>
/// <param name="buf">���͏������Ă�������</param>
	void PlayerUpdate(char buf[]);

	/// <summary>
/// �e�𔭎˂��鏈��
/// </summary>
/// <param name="ball"></param>
	void Shoot(Ball& ball);

private:
	const int SCREEN_WIDTH;
	const int SPEED = 5;

	/// <summary>
/// �v���C���[�̈ړ�����
/// </summary>
/// <param name="buf"></param>
	void Move(char buf[]);

	/// <summary>
	/// �v���C���[�̕`�揈��
/// </summary>
	void PlayerDraw();
};