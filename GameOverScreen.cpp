#include "GameOverScreen.h"
#include "GameMode.h"

GameMode GameOverScreen::GameOver(char buf[])
{
	DrawString(100, 130, "Game Over", GetColor(255, 0, 0));
	DrawString(100, 150, "Press Enter to Restart", GetColor(255, 255, 255));
	DrawString(100, 170, "Press Space to Title", GetColor(255, 255, 255));
	DrawString(100, 190, "Press Escape to Quit", GetColor(255, 255, 255));
	if (buf[KEY_INPUT_RETURN])
	{
		return SCREEN_GAME; // �Q�[�����ăX�^�[�g
	}
	else if (buf[KEY_INPUT_SPACE])
	{
		return SCREEN_TITLE; // �^�C�g���ɖ߂�
	}
	else if (buf[KEY_INPUT_ESCAPE])
	{
		return SCREEN_EXIT; // �Q�[���I��
	}

	return SCREEN_GAMEOVER; // �Q�[���I�[�o�[��Ԃ��ێ�
}