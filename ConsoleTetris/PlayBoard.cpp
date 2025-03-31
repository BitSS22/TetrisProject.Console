#include "pch.h"
#include "PlayBoard.h"

CPlayBoard::CPlayBoard()
{
	SetSize(Const::PlayBoardImageSize);
	SetLeftTop(Const::PlayBoardImageLeftTop);

	PlayBoard.resize(Const::PlayBoardSize.Y);

	for (unsigned int i = 0; i < Const::PlayBoardSize.Y; ++i)
	{
		PlayBoard[i].resize(Const::PlayBoardSize.X, EBlockColor::NONE);
	}
}

CPlayBoard::~CPlayBoard()
{
}

void CPlayBoard::DrawField()
{
	FillFixel(ERenderPixel::OUTLINE);

	for (unsigned int y = Const::PlayBoardOutline; y < GetImageSize().Y - Const::PlayBoardOutline; ++y)
	{
		for (unsigned int x = Const::PlayBoardOutline; x < GetImageSize().X - Const::PlayBoardOutline; ++x)
		{
			// DEBUG
			SetPixel(UInt2(x, y), ERenderPixel::DEBUG);
		}
	}
}

void CPlayBoard::Draw(CImage& Dest, bool _NonePixelDraw)
{
	DrawField();
	CImage::Draw(Dest, _NonePixelDraw);
}

