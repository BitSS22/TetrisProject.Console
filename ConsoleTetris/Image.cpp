#include "pch.h"
#include "Image.h"

CImage::CImage()
{
}

CImage::~CImage()
{
}

void CImage::SetSize(UInt2 _Size, ERenderPixel _PixelType)
{
	Size = _Size;
	Image.resize(Size.Y);

	for (unsigned int i = 0; i < Size.Y; ++i)
	{
		Image[i].resize(Size.X, _PixelType);
	}
}

void CImage::FillFixel(ERenderPixel _PixelType)
{
	for (unsigned int y = 0; y < Image.size(); ++y)
	{
		for (unsigned int x = 0; x < Image[y].size(); ++x)
		{
			SetPixel(UInt2(x, y), _PixelType);
		}
	}
}

void CImage::Draw(CImage& Dest, bool _NonePixelDraw)
{
	for (unsigned int y = 0; y < Size.Y; ++y)
	{
		for (unsigned int x = 0; x < Size.X; ++x)
		{
			if (_NonePixelDraw == false && GetPixel({ x, y }) == ERenderPixel::NONE)
				continue;
			else
				Dest.SetPixel(UInt2(GetLeftTop().X + x, GetLeftTop().Y + y), GetPixel({x, y}));
		}
	}
}
