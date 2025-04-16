#include "Block.h"

#include "DxLib.h"

int Block::GetWidth() const
{
	return BLOCK_WIDTH;
}

int Block::GetHeight() const
{
	return BLOCK_HEIGHT;
}

void Block::DrawBlock() const
{
	if (!isActive)
	{
		return;
	}

	DrawBox(xPosition, yPosition, xPosition + BLOCK_WIDTH, yPosition + BLOCK_HEIGHT, GetColor(0, 255, 0), TRUE);
}