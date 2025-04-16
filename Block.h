#pragma once

class Block
{
public:
	bool isActive = false;
	int xPosition = 0;
	int yPosition = 0;
	int GetWidth() const;
	int GetHeight() const;
	void DrawBlock() const;

private:
	const int BLOCK_WIDTH = 60;
	const int BLOCK_HEIGHT = 20;
};