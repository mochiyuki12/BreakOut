#pragma once
#ifndef UTILS_H
#define UTILS_H

class Ball
{
public:
	int x;
	int y;
	int radius;
	bool flag;
	Ball(int _x, int _y);
	void UpdateBall();

private:
	int vectorX;
	int vectorY;
	int _radius = 5;
};

#endif