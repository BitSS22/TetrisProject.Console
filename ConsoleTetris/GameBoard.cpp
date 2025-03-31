#include "GameBoard.h"

std::vector<std::vector<RenderData>> GameBoard::Board = {};

GameBoard::GameBoard(unsigned int _SizeX, unsigned int _SizeY)
{
	Board.resize(_SizeY);

	for (size_t i = 0; i < _SizeY; ++i)
	{
		Board[i].resize(_SizeX, RenderData::None);
	}
}

GameBoard::~GameBoard()
{
}
