#include "pch.h"
#include <stdio.h>
#include <Windows.h>
#include "GameEngine.h"
#include "RenderBoard.h"

CGameEngine::CGameEngine()
{
	Board.SetSize(Const::RenderSize);
}

CGameEngine::~CGameEngine()
{
}

void CGameEngine::Render(const CImage& _Image)
{
	for (unsigned int y = 0; y < _Image.GetSize().Y; ++y)
	{
		for (unsigned int x = 0; x < _Image.GetSize().X; ++x)
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
		Board.FillImage();

		// Draw

		// Render
		Render(Board);

		Sleep(1000);

		// Clear
		system("cls");
	}
}
