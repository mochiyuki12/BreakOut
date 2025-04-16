#pragma once

#include "Ball.h"
#include <vector>

class Player
{
public:
    int x = 290;
    int y = 400;
    const int WIDTH = 60;
    const int HEIGHT = 20;
	void Init();
    void PlayerUpdate(char buf[]);
    void Shoot(Ball& ball);

private:
    const int SPEED = 5;
    void Move(char buf[]);
    void PlayerDraw();
};