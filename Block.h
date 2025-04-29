#pragma once

class Block
{
public:
	bool isActive = false;
	int xPosition = 0;
	int yPosition = 0;
	inline int GetWidth() const { return BLOCK_WIDTH;};
	inline int GetHeight() const {return BLOCK_HEIGHT;};

	/// <summary>
	/// アクティブなブロックを描画する。
	/// </summary>
	void DrawBlock() const;

private:
	const int BLOCK_WIDTH = 60;
	const int BLOCK_HEIGHT = 20;
};