#include "DxLib.h"
#include "Ball.h"
#include "Player.h"
#include "BlockHandler.h"
#include "CollisionDetection.h"
#include <vector>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

Player _player = {};
Ball _ball;
BlockHandler _blockHandler = {};
CollisionDetection _collisionDetection = {};

void GameInit()
{
	// ゲームの初期化処理
	_player.Init();
	_blockHandler.Init();
	_ball.Init();
}

int Title(char buf[])
{
	// タイトル画面の処理
	DrawString(100, 130, "Press Enter to Start", GetColor(255, 255, 255));
	if (buf[KEY_INPUT_RETURN])
	{
		return 1; // ゲームスタート
	}
	return 0;
}

int GameMain(char buf[])
{
	_player.PlayerUpdate(buf);
	_ball.UpdateBall();
	_blockHandler.UpdateBlocks();
	_collisionDetection.CheckCollision(_ball, _blockHandler._blocks, _player);

	if (_ball.IsOutOfBounds())
	{
		return 2; // ゲームオーバー
	}

	if (buf[KEY_INPUT_SPACE] == 1)
	{
		_player.Shoot(_ball);
	}

	if (buf[KEY_INPUT_ESCAPE])
	{
		return -1; // ゲーム終了
	}
	return 1;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	char input[256];
	char gameMode = 0;

	ChangeWindowMode(TRUE);
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	SetMainWindowText("ブロック崩し");
	SetWindowSizeChangeEnableFlag(FALSE);
	//描画を裏にする
	//裏に描画した後、ScreenFlip()を呼ぶことで、裏に描画したものを表に出すことができる
	SetDrawScreen(DX_SCREEN_BACK);


	if (DxLib_Init() == -1)
	{
		return -1;
	}

	GameInit();

	while (ProcessMessage() == 0 && gameMode != -1)
	{
		// 画面を黒で塗りつぶす
		DrawBoxAA(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, GetColor(0, 0, 0), TRUE);

		GetHitKeyStateAll(input);

		switch (gameMode)
		{
		case 0: // タイトル画面
			gameMode = Title(input);
			break;
		case 1: // ゲーム画面
			gameMode = GameMain(input);
			break;
		case 2: // ゲームオーバー画面
			DrawString(100, 130, "Game Over", GetColor(255, 0, 0));
			DrawString(100, 150, "Press Enter to Restart", GetColor(255, 255, 255));
			if (input[KEY_INPUT_RETURN])
			{
				GameInit();
				gameMode = 1; // ゲームを再スタート
			}
			if (input[KEY_INPUT_ESCAPE])
			{
				gameMode = -1; // ゲーム終了
			}
			break;
		default:
			break;
		}

		//画面裏に書かれているものを表にする
		ScreenFlip();
	}

	DxLib_End();

	return 0;
}