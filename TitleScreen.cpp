#include "TitleScreen.h"

int TitleScreen::Title(char buf[])
{
	// タイトル画面の処理
	DrawString(100, 110, "BreakOut", GetColor(255, 255, 255));
	DrawString(100, 130, "Press Enter to Start", GetColor(255, 255, 255));
	DrawString(100, 150, "Press Escape to Quit", GetColor(255, 255, 255));
	if (buf[KEY_INPUT_RETURN])
	{
		return 1; // ゲームスタート
	}
	else if (buf[KEY_INPUT_ESCAPE])
	{
		return -1; // ゲーム終了
	}
	return 0;
}