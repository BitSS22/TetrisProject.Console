#pragma once

#include "RenderBoard.h"

class CGameEngine
{
public:
	CGameEngine();
	~CGameEngine();

private:
	CRenderBoard Board = {};

private:
	void Render(const CImage& _Image);

public:
	void MainLoop();

};

