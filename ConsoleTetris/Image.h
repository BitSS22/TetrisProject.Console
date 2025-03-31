#pragma once
#include <vector>

class CImage
{
public:
	CImage();
	~CImage();

private:
	std::vector<std::vector<EPixel>> Image = {};
	UInt2 Size = {};
	UInt2 LeftTop = {};

public:
	inline EPixel GetPixel(UInt2 _Pixel) const
	{
		return Image[_Pixel.Y][_Pixel.X];
	}
	inline void SetPixel(UInt2 _Pixel, EPixel _wch)
	{
		Image[_Pixel.Y][_Pixel.X] = _wch;
	}
	UInt2 GetSize() const
	{
		return Size;
	}
	void SetLeftTop(UInt2 _LeftTop)
	{
		LeftTop = _LeftTop;
	}
	UInt2 GetLeftTop()
	{
		return LeftTop;
	}

public:
	void SetSize(UInt2 _Size, EPixel _Fill = EPixel::NONE);
	void FillImage(EPixel _Fill = EPixel::NONE);
	void Draw(CImage& Dest, bool _NonePixelDraw = false);

};

