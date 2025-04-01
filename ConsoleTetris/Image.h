#pragma once
#include <vector>

class CImage
{
public:
	CImage();
	virtual ~CImage();

private:
	std::vector<std::vector<Pixel>> Image = {};
	UInt2 Size = {};
	UInt2 LeftTop = {};

public:
	inline Pixel GetPixel(UInt2 _PixelLocation) const
	{
		return Image[_PixelLocation.Y][_PixelLocation.X];
	}
	inline void SetPixel(UInt2 _PixelDest, Pixel _Pixel)
	{
		Image[_PixelDest.Y][_PixelDest.X] = _Pixel;
	}
	UInt2 GetImageSize() const
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
	void SetImageSize(UInt2 _Size, Pixel _Pixel = Pixel());
	void FillFixel(Pixel _Pixel = Pixel());
	virtual void Draw(CImage& Dest, bool _NonePixelDraw = false);

};

