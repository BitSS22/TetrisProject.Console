#include "pch.h"
#include <stdio.h>
#include <Windows.h>
#include "GameEngine.h"
#include "RenderBoard.h"

CGameEngine::CGameEngine()
{
}

CGameEngine::~CGameEngine()
{
}

void CGameEngine::Render(const CImage& _Image)
{
	for (unsigned int y = 0; y < _Image.GetImageSize().Y; ++y)
	{
		for (unsigned int x = 0; x < _Image.GetImageSize().X; ++x)
		{
			putwchar(static_cast<wchar_t>(_Image.GetPixel({ x, y })));
		}
		putwchar(L'\n');
	}
}

void CGameEngine::MainLoop()
{
	while (true)
	{
		// Board Reset
		RenderBoard.FillFixel();

		// Draw
		PlayBoard.Draw(RenderBoard, true);

		// Render
		Render(RenderBoard);

		Sleep(1000);

		// Clear
		system("cls");
	}
}
