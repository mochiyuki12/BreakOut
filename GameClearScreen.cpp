#include "GameClearScreen.h"
#include "GameMode.h"
#include "DxLib.h"

GameMode GameClearScreen::GameClear(char buf[])
{
	DrawString(100, 130, "Game Clear", GetColor(0, 255, 0));
	DrawString(100, 150, "Press Enter to Restart", GetColor(255, 255, 255));
	DrawString(100, 170, "Press Space to Title", GetColor(255, 255, 255));
	DrawString(100, 190, "Press Escape to Quit", GetColor(255, 255, 255));
	if (buf[KEY_INPUT_RETURN])
	{
		return SCREEN_GAME; // ゲームを再スタート
	}
	else if (buf[KEY_INPUT_SPACE])
	{
		return SCREEN_TITLE; // タイトルに戻る
	}
	else if (buf[KEY_INPUT_ESCAPE])
	{
		return SCREEN_EXIT; // ゲーム終了
	}
	return SCREEN_GAMECLEAR; // ゲームクリア状態を維持
}