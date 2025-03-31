#include "pch.h"
#include <stdio.h>
#include <Windows.h>
#include "GameEngine.h"
#include "Image.h"

void CGameEngine::Render(const CImage& _Image, UInt2 _LeftTop)
{
	for (unsigned int y = 0; y < _Image.GetSize().Y; ++y)
	{
		for (unsigned int x = 0; x < _Image.GetSize().X; ++x)
		{
			putwchar(_Image.GetPixel({ x, y }));
		}
		putwchar(L'\n');
	}
	
}

void CGameEngine::MainLoop()
{
	CImage Image = {};

	while (true)
	{
		Image.SetImage(Const::RenderSize);

		Render(Image, {0, 0});

		Sleep(1000);
		system("cls");
	}
}
