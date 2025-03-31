#include "pch.h"
#include "Image.h"

CImage::CImage()
{
}

CImage::~CImage()
{
}

void CImage::SetSize(UInt2 _Size, EPixel _Fill)
{
	Size = _Size;
	Image.resize(Size.Y);

	for (unsigned int i = 0; i < Size.Y; ++i)
	{
		Image[i].resize(Size.X, _Fill);
	}
}

void CImage::FillImage(EPixel _Fill)
{
	for (unsigned int y = 0; y < Image.size(); ++y)
	{
		for (unsigned int x = 0; x < Image[y].size(); ++x)
		{
			SetPixel(UInt2(y, x), _Fill);
		}
	}
}

void CImage::Draw(CImage& Dest, bool _NonePixelDraw)
{
	for (unsigned int y = 0; y < Size.Y; ++y)
	{
		for (unsigned int x = 0; x < Size.X; ++x)
		{
			if (_NonePixelDraw == false && GetPixel({ y, x }) == EPixel::NONE)
				continue;
			else
				Dest.SetPixel(UInt2(LeftTop.Y + y, LeftTop.X + x), GetPixel({ y, x }));
		}
	}
}
