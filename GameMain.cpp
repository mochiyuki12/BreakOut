#include "DxLib.h"
#include "Ball.h"
#include "Player.h"
#include "BlockHandler.h"
#include "CollisionDetection.h"
#include "TitleScreen.h"
#include "GameOverScreen.h"
#include "GameClearScreen.h"
#include "GameMode.h"
#include <vector>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

Player _player = {WINDOW_WIDTH};
Ball _ball = {WINDOW_WIDTH,WINDOW_HEIGHT};
BlockHandler _blockHandler = {};
CollisionDetection _collisionDetection = {};
TitleScreen _titleScreen = {};
GameOverScreen _gameOverScreen = {};
GameClearScreen _gameClearScreen = {};

void GameInit()
{
	// ゲームの初期化処理
	_player.Init();
	_blockHandler.Init();
	_ball.Init();
}

GameMode GameMain(char buf[])
{
	_player.PlayerUpdate(buf);
	_ball.UpdateBall();
	_blockHandler.UpdateBlocks();
	_collisionDetection.HandleCollisions(_ball, _blockHandler._blocks, _player);

	if (buf[KEY_INPUT_SPACE] == 1)
	{
		_player.Shoot(_ball);
	}

	if (_ball.IsOutOfBounds())
	{
		return SCREEN_GAMEOVER; // ゲームオーバー
	}

	if (_blockHandler.IsAllBlocksCleared())
	{
		return SCREEN_GAMECLEAR; // ゲームクリア
	}

	if (buf[KEY_INPUT_ESCAPE])
	{
		return SCREEN_EXIT; // ゲーム終了
	}
	return SCREEN_GAME;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	char input[256];
	GameMode gameMode = SCREEN_TITLE;

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

	while (ProcessMessage() == 0 && gameMode != SCREEN_EXIT)
	{
		// 画面を黒で塗りつぶす
		DrawBoxAA(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, GetColor(0, 0, 0), TRUE);

		GetHitKeyStateAll(input);

		switch (gameMode)
		{
		case SCREEN_TITLE: // タイトル画面
			gameMode = _titleScreen.Title(input);
			break;
		case SCREEN_GAME: // ゲーム画面
			gameMode = GameMain(input);
			break;
		case SCREEN_GAMEOVER: // ゲームオーバー画面
			GameInit();
			gameMode = _gameOverScreen.GameOver(input);
			break;
		case SCREEN_GAMECLEAR: // ゲームクリア画面
			GameInit();
			gameMode = _gameClearScreen.GameClear(input);
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