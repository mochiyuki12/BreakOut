#include "DxLib.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

typedef struct
{
	int x;
	int y;
	int radius;
	bool flag;
} Bullet;

typedef struct
{
	int x;
	int y;
	int velocity;
	Bullet bullet;
} Character;

typedef struct
{
	int x;
	int y;
	bool isActive;
} Block;

Character _player = {};
Block _block = {};

void GameInit()
{
	// ゲームの初期化処理
	_player.x = 290;
	_player.y = 400;
	_player.velocity = 5;

	_block.x = 290;
	_block.y = 100;
	_block.isActive = true;
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

void Shoot()
{
	// 弾を発射する処理
	if (_player.bullet.flag)
	{
		return; // すでに弾が発射されている場合は何もしない
	}
	else
	{
		_player.bullet.x = _player.x + 30; // プレイヤーの中心から弾を発射
		_player.bullet.y = _player.y;
		_player.bullet.radius = 5;
		_player.bullet.flag = true;
	}

}

void UpdateBullets()
{
	if (!_player.bullet.flag)
	{
		return;
	}

	if (_player.bullet.y <= 0)
	{
		_player.bullet.flag = false;
		return;
	}

	_player.bullet.y -= 2; // 弾の移動速度
	DrawCircleAA(_player.bullet.x, _player.bullet.y, _player.bullet.radius, 32, GetColor(255, 0, 0), TRUE);
}

void DrawBlock()
{
	// ブロックを描画する処理
	if (!_block.isActive)
	{
		return;
	}
	DrawBox(_block.x, _block.y, _block.x + 60, _block.y + 20, GetColor(0, 255, 0), TRUE);
}

void CollisionCheck()
{
	if (_player.bullet.flag == true)
	{
		if (_player.bullet.x >= _block.x && _player.bullet.x <= _block.x + 60 &&
			_player.bullet.y >= _block.y && _player.bullet.y <= _block.y + 20)
		{
			_block.isActive = false; // ブロックを非アクティブにする
			DrawString(100, 130, "Hit!", GetColor(255, 255, 255));
		}
	}
}

int GameMain(char buf[])
{
	//ゲームのメインループ
	DrawString(100, 100, "playering", GetColor(255, 255, 255));
	if (buf[KEY_INPUT_RIGHT] == 1)
	{
		_player.x += _player.velocity;

	}
	if (buf[KEY_INPUT_LEFT] == 1)
	{
		_player.x -= _player.velocity;
	}

	DrawBox(_player.x, _player.y, _player.x + 60, _player.y + 20, GetColor(255, 255, 255), TRUE);

	UpdateBullets();
	DrawBlock();
	CollisionCheck();

	if (buf[KEY_INPUT_SPACE] == 1)
	{
		Shoot();
	}

	if (buf[KEY_INPUT_ESCAPE])
	{
		return -1; // ゲーム終了
	}
	return 1;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	char buffer[256];
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

		GetHitKeyStateAll(buffer);

		switch (gameMode)
		{
		case 0: // タイトル画面
			gameMode = Title(buffer);
			break;
		case 1: // ゲーム画面
			gameMode = GameMain(buffer);
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