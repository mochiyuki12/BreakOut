#include "Block.h"

#include "DxLib.h"

void Block::DrawBlock() const
{
	if (!isActive)
	{
		return;
	}

	DrawBox(xPosition, yPosition, xPosition + BLOCK_WIDTH, yPosition + BLOCK_HEIGHT, GetColor(0, 255, 0), TRUE);
}