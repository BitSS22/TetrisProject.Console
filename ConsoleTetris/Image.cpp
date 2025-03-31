#include "pch.h"
#include "Image.h"

CImage::CImage()
{
}

CImage::~CImage()
{
}

void CImage::SetImage(UInt2 _Size, wchar_t _Fill)
{
	Size = _Size;
	Image.resize(Size.Y);

	for (unsigned int i = 0; i < Size.Y; ++i)
	{
		Image[i].resize(Size.X, _Fill);
	}
}

void CImage::Draw(CImage& Dest, UInt2 _LeftTop)
{

}
