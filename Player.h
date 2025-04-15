#pragma once

#include "Ball.h"
#include <vector>

class Player
{
public:
    int x;
    int y;
    int velocity;

    void Move(char buf[]);

    void Shoot();


private:
	int _width = 60;
	int _height = 20;
	
};