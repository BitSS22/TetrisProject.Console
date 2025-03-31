#pragma once
#include <vector>

class CImage
{
public:
	CImage();
	~CImage();

private:
	std::vector<std::vector<wchar_t>> Image = {};
	UInt2 Size = {};

public:
	inline wchar_t GetPixel(const UInt2& _Pixel) const
	{
		return Image[_Pixel.Y][_Pixel.X];
	}

	inline void SetPixel(const UInt2& _Pixel, wchar_t _wch)
	{
		Image[_Pixel.Y][_Pixel.X] = _wch;
	}

	UInt2 GetSize() const
	{
		return Size;
	}

public:
	void SetImage(UInt2 _Size, wchar_t _Fill = L'0');
	void Draw(CImage& Dest, UInt2 _LeftTop);

};

