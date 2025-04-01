#pragma once
#include "Image.h"

class CPlayBoard : public CImage
{
public:
	CPlayBoard();
	~CPlayBoard();

private:
	std::vector<std::vector<Pixel>> PlayBoard = {};
	UInt2 PlayBoardSize = Const::PlayBoardSize;

private:
	void DrawField();

public:
	inline Pixel GetPlayBoardPixel(UInt2 _Index)
	{
		return PlayBoard[_Index.Y][_Index.X];
	}
	inline void SetPlayBoardPixel(UInt2 _Index, Pixel _Pixel)
	{
		PlayBoard[_Index.Y][_Index.X] = _Pixel;
	}
	inline UInt2 GetPlayBoardSize() const
	{
		return PlayBoardSize;
	}
	void Draw(CImage& Dest, bool _NonePixelDraw = false) override;

};

