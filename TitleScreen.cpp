#include "TitleScreen.h"

int TitleScreen::Title(char buf[])
{
	// �^�C�g����ʂ̏���
	DrawString(100, 110, "BreakOut", GetColor(255, 255, 255));
	DrawString(100, 130, "Press Enter to Start", GetColor(255, 255, 255));
	DrawString(100, 150, "Press Escape to Quit", GetColor(255, 255, 255));
	if (buf[KEY_INPUT_RETURN])
	{
		return 1; // �Q�[���X�^�[�g
	}
	else if (buf[KEY_INPUT_ESCAPE])
	{
		return -1; // �Q�[���I��
	}
	return 0;
}