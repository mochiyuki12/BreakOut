#include "GameClearScreen.h"

int GameClearScreen::GameClear(char buf[])
{
	DrawString(100, 130, "Game Clear", GetColor(0, 255, 0));
	DrawString(100, 150, "Press Enter to Restart", GetColor(255, 255, 255));
	DrawString(100, 170, "Press Space to Title", GetColor(255, 255, 255));
	DrawString(100, 190, "Press Escape to Quit", GetColor(255, 255, 255));
	if (buf[KEY_INPUT_RETURN])
	{
		return 1; // ゲームを再スタート
	}
	else if (buf[KEY_INPUT_SPACE])
	{
		return 0; // タイトルに戻る
	}
	else if (buf[KEY_INPUT_ESCAPE])
	{
		return -1; // ゲーム終了
	}
	return 3; // ゲームクリア状態を維持
}