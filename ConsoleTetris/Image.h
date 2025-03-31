#pragma once
#include <vector>

class CImage
{
public:
	CImage();
	virtual ~CImage();

private:
	std::vector<std::vector<ERenderPixel>> Image = {};
	UInt2 Size = {};
	UInt2 LeftTop = {};

public:
	inline ERenderPixel GetPixel(UInt2 _PixelLocation) const
	{
		return Image[_PixelLocation.Y][_PixelLocation.X];
	}
	inline void SetPixel(UInt2 _PixelDest, ERenderPixel _PixelType)
	{
		Image[_PixelDest.Y][_PixelDest.X] = _PixelType;
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
	void SetSize(UInt2 _Size, ERenderPixel _PixelType = ERenderPixel::NONE);
	void FillFixel(ERenderPixel _PixelType = ERenderPixel::NONE);
	virtual void Draw(CImage& Dest, bool _NonePixelDraw = false);

};

