#pragma once

#include "RenderBoard.h"
#include "PlayBoard.h"

class CGameEngine
{
public:
	CGameEngine();
	~CGameEngine();

private:
	CRenderBoard RenderBoard = {};
	CPlayBoard PlayBoard = {};


private:
	void Render(const CImage& _Image);

public:
	void MainLoop();

};

