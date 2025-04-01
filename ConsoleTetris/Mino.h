#pragma once
#include "Image.h"

class CMino : public CImage
{
public:
	CMino();
	~CMino();

private:
	EMinoType MinoType = EMinoType::END;
	EColorType ColorType = EColorType::END;
	ERotateType RotateType = ERotateType::END;
	UInt2 BlockSize = {};

private:
	void SetBlockSize(UInt2 _Size)
	{
		BlockSize = _Size;
	}
	void SetColorType(EColorType _ColorType)
	{
		ColorType = _ColorType;
	}
	bool PlayBoardCollisionCheck();

public:
	void SetMino(EMinoType _MinoType);
	void Draw(CImage& Dest, bool _NonePixelDraw = false) override;
	void Rotate(bool _Right);
	
};

