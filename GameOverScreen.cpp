#include "GameOverScreen.h"

int GameOverScreen::GameOver(char buf[])
{
	DrawString(100, 130, "Game Over", GetColor(255, 0, 0));
	DrawString(100, 150, "Press Enter to Restart", GetColor(255, 255, 255));
	DrawString(100, 170, "Press Space to Title", GetColor(255, 255, 255));
	DrawString(100, 190, "Press Escape to Quit", GetColor(255, 255, 255));
	if (buf[KEY_INPUT_RETURN])
	{
		return 1; // �Q�[�����ăX�^�[�g
	}
	else if (buf[KEY_INPUT_SPACE])
	{
		return 0; // �^�C�g���ɖ߂�
	}
	else if (buf[KEY_INPUT_ESCAPE])
	{
		return -1; // �Q�[���I��
	}

	return 2; // �Q�[���I�[�o�[��Ԃ��ێ�
}