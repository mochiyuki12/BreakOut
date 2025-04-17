#include "DxLib.h"
#include "Ball.h"
#include "Player.h"
#include "BlockHandler.h"
#include "CollisionDetection.h"
#include "TitleScreen.h"
#include "GameOverScreen.h"
#include "GameClearScreen.h"
#include <vector>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

Player _player = {};
Ball _ball;
BlockHandler _blockHandler = {};
CollisionDetection _collisionDetection = {};
TitleScreen _titleScreen = {};
GameOverScreen _gameOverScreen = {};
GameClearScreen _gameClearScreen = {};

void GameInit()
{
	// �Q�[���̏���������
	_player.Init();
	_blockHandler.Init();
	_ball.Init();
}

int GameMain(char buf[])
{
	_player.PlayerUpdate(buf);
	_ball.UpdateBall();
	_blockHandler.UpdateBlocks();
	_collisionDetection.CheckCollision(_ball, _blockHandler._blocks, _player);

	if (buf[KEY_INPUT_SPACE] == 1)
	{
		_player.Shoot(_ball);
	}

	if (_ball.IsOutOfBounds())
	{
		return 2; // �Q�[���I�[�o�[
	}

	if (_blockHandler.IsAllBlocksCleared())
	{
		return 3; // �Q�[���N���A
	}

	if (buf[KEY_INPUT_ESCAPE])
	{
		return -1; // �Q�[���I��
	}
	return 1;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	char input[256];
	char gameMode = 0;

	ChangeWindowMode(TRUE);
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	SetMainWindowText("�u���b�N����");
	SetWindowSizeChangeEnableFlag(FALSE);
	//�`��𗠂ɂ���
	//���ɕ`�悵����AScreenFlip()���ĂԂ��ƂŁA���ɕ`�悵�����̂�\�ɏo�����Ƃ��ł���
	SetDrawScreen(DX_SCREEN_BACK);


	if (DxLib_Init() == -1)
	{
		return -1;
	}

	GameInit();

	while (ProcessMessage() == 0 && gameMode != -1)
	{
		// ��ʂ����œh��Ԃ�
		DrawBoxAA(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, GetColor(0, 0, 0), TRUE);

		GetHitKeyStateAll(input);

		switch (gameMode)
		{
		case 0: // �^�C�g�����
			gameMode = _titleScreen.Title(input);
			break;
		case 1: // �Q�[�����
			gameMode = GameMain(input);
			break;
		case 2: // �Q�[���I�[�o�[���
			GameInit();
			gameMode = _gameOverScreen.GameOver(input);
			break;
		case 3: // �Q�[���N���A���
			GameInit();
			gameMode = _gameClearScreen.GameClear(input);
			break;
		default:
			break;
		}

		//��ʗ��ɏ�����Ă�����̂�\�ɂ���
		ScreenFlip();
	}

	DxLib_End();

	return 0;
}