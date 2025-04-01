#include "pch.h"
#include "Mino.h"
#include "GameEngine.h"

CMino::CMino()
{
	SetImageSize(Const::MinoImageSize);
	BlockSize = UInt2(5, 5);
	SetMino(EMinoType::J);
}

CMino::~CMino()
{
}

bool CMino::PlayBoardCollisionCheck()
{
	CPlayBoard& PlayBoard = *CGameEngine::GetPlayBoard();

	for (unsigned int y = 0; y < BlockSize.Y; ++y)
	{
		if (PlayBoard.GetPlayBoardSize().Y >= y + GetLeftTop().Y)
			return true;

		for (unsigned int x = 0; x < BlockSize.X; ++x)
		{
			if (GetPixel({ x, y }).Shape == EShape::NONE)
				continue;
			else if (PlayBoard.GetPlayBoardSize().X >= x + GetLeftTop().X)
				return true;
			else if (PlayBoard.GetPixel(UInt2(GetLeftTop().X + x, GetLeftTop().Y + y)).Shape != EShape::NONE)
				return true;
		}
	}

	return false;
}

void CMino::SetMino(EMinoType _MinoType)
{
	FillFixel();

	switch (_MinoType)
	{
	case EMinoType::I:
		SetBlockSize({ 5, 5 });
		SetPixel({ 1, 2 }, Pixel(EShape::BLOCK, EColorType::SKY));
		SetPixel({ 2, 2 }, Pixel(EShape::BLOCK, EColorType::SKY));
		SetPixel({ 3, 2 }, Pixel(EShape::BLOCK, EColorType::SKY));
		SetPixel({ 4, 2 }, Pixel(EShape::BLOCK, EColorType::SKY));
		return;
	case EMinoType::J:
		SetBlockSize({ 3, 3 });
		SetPixel({ 0, 0 }, Pixel(EShape::BLOCK, EColorType::BLUE));
		SetPixel({ 0, 1 }, Pixel(EShape::BLOCK, EColorType::BLUE));
		SetPixel({ 1, 1 }, Pixel(EShape::BLOCK, EColorType::BLUE));
		SetPixel({ 2, 1 }, Pixel(EShape::BLOCK, EColorType::BLUE));
		return;
	case EMinoType::L:
		SetBlockSize({ 3, 3 });
		SetPixel({ 2, 0 }, Pixel(EShape::BLOCK, EColorType::ORANGE));
		SetPixel({ 0, 1 }, Pixel(EShape::BLOCK, EColorType::ORANGE));
		SetPixel({ 1, 1 }, Pixel(EShape::BLOCK, EColorType::ORANGE));
		SetPixel({ 2, 1 }, Pixel(EShape::BLOCK, EColorType::ORANGE));
		return;
	case EMinoType::O:
		SetBlockSize({ 3, 3 });
		SetPixel({ 1, 0 }, Pixel(EShape::BLOCK, EColorType::YELLOW));
		SetPixel({ 2, 0 }, Pixel(EShape::BLOCK, EColorType::YELLOW));
		SetPixel({ 1, 1 }, Pixel(EShape::BLOCK, EColorType::YELLOW));
		SetPixel({ 2, 1 }, Pixel(EShape::BLOCK, EColorType::YELLOW));
		return;
	case EMinoType::S:
		SetBlockSize({ 3, 3 });
		SetPixel({ 1, 0 }, Pixel(EShape::BLOCK, EColorType::GREEN));
		SetPixel({ 2, 0 }, Pixel(EShape::BLOCK, EColorType::GREEN));
		SetPixel({ 1, 1 }, Pixel(EShape::BLOCK, EColorType::GREEN));
		SetPixel({ 0, 1 }, Pixel(EShape::BLOCK, EColorType::GREEN));
		return;
	case EMinoType::T:
		SetBlockSize({ 3, 3 });
		SetPixel({ 1, 0 }, Pixel(EShape::BLOCK, EColorType::PURPLE));
		SetPixel({ 0, 1 }, Pixel(EShape::BLOCK, EColorType::PURPLE));
		SetPixel({ 1, 1 }, Pixel(EShape::BLOCK, EColorType::PURPLE));
		SetPixel({ 2, 1 }, Pixel(EShape::BLOCK, EColorType::PURPLE));
		return;
	case EMinoType::Z:
		SetBlockSize({ 3, 3 });
		SetPixel({ 0, 0 }, Pixel(EShape::BLOCK, EColorType::RED));
		SetPixel({ 1, 0 }, Pixel(EShape::BLOCK, EColorType::RED));
		SetPixel({ 1, 1 }, Pixel(EShape::BLOCK, EColorType::RED));
		SetPixel({ 2, 1 }, Pixel(EShape::BLOCK, EColorType::RED));
		return;
	}

	assert(nullptr);
}

void CMino::Draw(CImage& Dest, bool _NonePixelDraw)
{
	for (unsigned int y = 0; y < BlockSize.Y; ++y)
	{
		for (unsigned int x = 0; x < BlockSize.X; ++x)
		{
			if (_NonePixelDraw == false && GetPixel({ x, y }).Shape == EShape::NONE)
				continue;
			else
				Dest.SetPixel(UInt2(GetLeftTop().X + x, GetLeftTop().Y + y), GetPixel({ x, y }));
		}
	}
}

void CMino::Rotate(bool _Right)
{
	ERotateType NewRotateType = RotateType;

	if (_Right)
		++NewRotateType;
	else
		--NewRotateType;

	static CMino NewRotateImage = CMino();
	NewRotateImage.SetBlockSize(BlockSize);
	NewRotateImage.FillFixel();

	int OffsetX = static_cast<int>(BlockSize.X) / 2;
	int OffsetY = static_cast<int>(BlockSize.Y) / 2;

	if (_Right)
	{
		for (int y = -OffsetY; y < static_cast<int>(BlockSize.Y) - OffsetY; ++y)
		{
			for (int x = -OffsetX; x < static_cast<int>(BlockSize.X) - OffsetX; ++x)
			{
				NewRotateImage.SetPixel(UInt2(x + OffsetX, y + OffsetY), GetPixel(UInt2({ y + OffsetX, -x + OffsetY })));
			}
		}
	}
	else
	{
		for (int y = -OffsetY; y < static_cast<int>(BlockSize.Y) - OffsetY; ++y)
		{
			for (int x = -OffsetX; x < static_cast<int>(BlockSize.X) - OffsetX; ++x)
			{
				NewRotateImage.SetPixel(UInt2(x + OffsetX, y + OffsetY), GetPixel(UInt2({ -y + OffsetX, x + OffsetY })));
			}
		}
	}

	NewRotateImage.Draw(*this, true);
}
