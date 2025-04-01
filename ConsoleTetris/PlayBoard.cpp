#include "pch.h"
#include "PlayBoard.h"

CPlayBoard::CPlayBoard()
{
	SetImageSize(Const::PlayBoardImageSize);
	SetLeftTop(Const::PlayBoardImageLeftTop);

	PlayBoard.resize(PlayBoardSize.Y);

	for (unsigned int i = 0; i < PlayBoardSize.Y; ++i)
	{
		PlayBoard[i].resize(PlayBoardSize.X, Pixel());
	}
}

CPlayBoard::~CPlayBoard()
{
}

void CPlayBoard::DrawField()
{
	FillFixel(Pixel(EShape::OUTLINE, EColorType::GRAY));

	for (unsigned int y = Const::PlayBoardOutline; y < GetImageSize().Y - Const::PlayBoardOutline; ++y)
	{
		for (unsigned int x = Const::PlayBoardOutline; x < GetImageSize().X - Const::PlayBoardOutline; ++x)
		{
			// DEBUG
			SetPixel(UInt2(x, y), Pixel(EShape::NONE, EColorType::GRAY));
		}
	}
}

void CPlayBoard::Draw(CImage& Dest, bool _NonePixelDraw)
{
	DrawField();
	CImage::Draw(Dest, _NonePixelDraw);
}

