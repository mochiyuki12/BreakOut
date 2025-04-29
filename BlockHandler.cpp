#include "BlockHandler.h"
#include "Block.h"

/// <summary>
/// �u���b�N�̈ʒu��ݒ肵�A�A�N�e�B�u��Ԃɂ���B
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

/// <summary>
/// �u���b�N�̕`����X�V����B	
/// </summary>
void BlockHandler::UpdateBlocks()
{
	
	for (auto& block : _blocks)
	{
		if (block.isActive)
		{
			block.DrawBlock();
		}
	}
}

/// <summary>
/// �u���b�N���S�ăN���A���ꂽ���m�F����B
/// </summary>
/// <returns></returns>
bool BlockHandler::IsAllBlocksCleared()
{
	for (const auto& block : _blocks)
	{
		if (block.isActive)
		{
			return false;
		}
	}
	return true;
}
