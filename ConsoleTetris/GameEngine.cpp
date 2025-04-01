#include "pch.h"
#include <iostream>
#include <Windows.h>
#include "GameEngine.h"
#include "RenderBoard.h"

CGameEngine::CGameEngine()
{
	PlayBoard = new CPlayBoard();
}

CGameEngine::~CGameEngine()
{
	delete PlayBoard;
}

void CGameEngine::Render(const CImage& _Image)
{
	for (unsigned int y = 0; y < _Image.GetImageSize().Y; ++y)
	{
		for (unsigned int x = 0; x < _Image.GetImageSize().X; ++x)
		{
			wprintf_s(L"%c", static_cast<wchar_t>(_Image.GetPixel({ x, y }).Shape));
			//putwchar(static_cast<wchar_t>(_Image.GetPixel({ x, y }).Shape));
		}
		wprintf_s(L"\n");
		//putwchar(L'\n');
	}
}

void CGameEngine::Draw()
{
	// Board Reset
	RenderBoard.FillFixel();

	// Draw Shape
	PlayBoard->Draw(RenderBoard, true);
	Mino.Draw(RenderBoard);
}

void CGameEngine::Input()
{
	Mino.Rotate(true);
}

void CGameEngine::GameReset()
{
}

void CGameEngine::MainLoop()
{
	GameReset();

	while (true)
	{
		// Input
		Input();

		// Render
		Draw();
		Render(RenderBoard);

		// Debug Wait
		Sleep(1000);
		

		// Clear
		system("cls");
	}
}
