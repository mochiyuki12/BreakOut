#include "BlockHandler.h"
#include "Block.h"

/// <summary>
/// ブロックの位置を設定し、アクティブ状態にする。
/// </summary>
void BlockHandler::Init()
{
	// Initialize blocks
	for (int i = 0; i < BLOCK_COUNT; ++i)
	{
		Block block;
		block.isActive = true;
		block.xPosition = OFFSET_X + (i % BLOCKS_PER_ROW) * (block.GetWidth() + SPACING);
		block.yPosition = OFFSET_Y + (i / BLOCKS_PER_ROW) * (block.GetHeight() + SPACING);
		_blocks.push_back(block);
	}
}

void BlockHandler::UpdateBlocks()
{
	// Update blocks
	for (auto& block : _blocks)
	{
		if (block.isActive)
		{
			block.DrawBlock();
		}
	}
}
