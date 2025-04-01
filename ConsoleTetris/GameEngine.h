#pragma once

#include "RenderBoard.h"
#include "PlayBoard.h"
#include "Mino.h"

class CGameEngine
{
public:
	CGameEngine();
	~CGameEngine();

private:
	CRenderBoard RenderBoard = {};
	inline static CPlayBoard* PlayBoard = nullptr;
	CMino Mino = {};

private:
	void Render(const CImage& _Image);
	void Draw();
	void Input();
	void GameReset();

public:
	void MainLoop();

	inline static CPlayBoard* GetPlayBoard()
	{
		return PlayBoard;
	}
};

