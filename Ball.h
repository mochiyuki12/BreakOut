#pragma once
#ifndef UTILS_H
#define UTILS_H

class Ball
{
public:
	int x = 0;
	int y = 0;
	int velocityX = 2;
	int velocityY = -2;
	void Init();
	bool IsOutOfBounds() const;
	bool isActive = false;
	void UpdateBall();

private:
	const int RADIUS = 5;
	void DrawBall();
};

#endif