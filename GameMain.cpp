#include "DxLib.h"
#include "Ball.h"
#include "Player.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480


typedef struct
{
	int x;
	int y;
	bool isActive;
} Block;

Player _player = {};
Block _block = {};
Ball _ball(0, 0);

void GameInit()
{
	// �Q�[���̏���������
	_player.x = 290;
	_player.y = 400;
	_player.velocity = 5;
	
	_block.x = 290;
	_block.y = 100;
	_block.isActive = true;
}

int Title(char buf[])
{
	// �^�C�g����ʂ̏���
	DrawString(100, 130, "Press Enter to Start", GetColor(255, 255, 255));
	if (buf[KEY_INPUT_RETURN])
	{
		return 1; // �Q�[���X�^�[�g
	}

	return 0;
}

void Shoot()
{
	// �e�𔭎˂��鏈��
	if (_ball.flag)
	{
		return; // ���łɒe�����˂���Ă���ꍇ�͉������Ȃ�
	}
	else
	{
		_ball.x = _player.x + 30; // �v���C���[�̒��S����e�𔭎�
		_ball.y = _player.y;
		_ball.radius = 5;
		_ball.flag = true;
	}

}



void DrawBlock()
{
	// �u���b�N��`�悷�鏈��
	if (!_block.isActive)
	{
		return;
	}
	DrawBox(_block.x, _block.y, _block.x + 60, _block.y + 20, GetColor(0, 255, 0), TRUE);
}

void CollisionCheck()
{
	if (_ball.flag == true)
	{
		if (_ball.x >= _block.x && _ball.x <= _block.x + 60 &&
			_ball.y >= _block.y && _ball.y <= _block.y + 20)
		{
			_block.isActive = false; // �u���b�N���A�N�e�B�u�ɂ���
			DrawString(100, 130, "Hit!", GetColor(255, 255, 255));
		}
	}
}

int GameMain(char buf[])
{
	//�Q�[���̃��C�����[�v
	DrawString(100, 100, "playering", GetColor(255, 255, 255));
	if (buf[KEY_INPUT_RIGHT] == 1)
	{
		_player.x += _player.velocity;

	}
	if (buf[KEY_INPUT_LEFT] == 1)
	{
		_player.x -= _player.velocity;
	}

	

	_ball.UpdateBall();
	DrawBlock();
	CollisionCheck();

	if (buf[KEY_INPUT_SPACE] == 1)
	{
		Shoot();
	}

	if (buf[KEY_INPUT_ESCAPE])
	{
		return -1; // �Q�[���I��
	}
	return 1;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	char buffer[256];
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

		GetHitKeyStateAll(buffer);

		switch (gameMode)
		{
		case 0: // �^�C�g�����
			gameMode = Title(buffer);
			break;
		case 1: // �Q�[�����
			gameMode = GameMain(buffer);
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