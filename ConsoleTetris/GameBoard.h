#pragma once
#include <vector>
#include "Enums.h"

class GameBoard
{
public:
	GameBoard(unsigned int _SizeX, unsigned int _SizeY);
	~GameBoard();

private:
	static std::vector<std::vector<RenderData>> Board;

public:
	static const std::vector<std::vector<RenderData>>& GetBoard()
	{
		return Board;
	}

};

