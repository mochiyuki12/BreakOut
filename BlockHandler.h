#pragma once
#include <vector>
#include "Block.h"
#define BLOCK_COUNT 15

class BlockHandler
{
public:
	void Init();
	void UpdateBlocks();
	std::vector<Block> _blocks;

private:
	const int BLOCKS_PER_ROW = 5;
	const int OFFSET_X = 150;
	const int OFFSET_Y = 70;
	const int SPACING = 10;
};
