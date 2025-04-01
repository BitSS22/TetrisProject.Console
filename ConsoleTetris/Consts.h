#pragma once

namespace Const
{
	static inline const UInt2 RenderSize = { 40, 30 };
	
	static inline const unsigned int PlayBoardOutline = 1;
	static inline const wchar_t PlayBoardOutlinePixel = L'q';
	static inline const UInt2 PlayBoardImageLeftTop = { 3, 3 };

	static inline const UInt2 PlayBoardImageSize = { 10 + PlayBoardOutline * 2, 20 + PlayBoardOutline * 2 };
	static inline const UInt2 PlayBoardSize = { 10, 30 };

	static inline const UInt2 OnlyRenderMinoImageSize = { 4, 2 };
	static inline const UInt2 MinoImageSize = { 5, 5 };

	static inline const unsigned int SRSCount = 5;
}

class RotateOffsetValue
{
private:
	static const UInt2 OffsetList[static_cast<int>(ESRSBlockType::END)][static_cast<int>(ERotateType::END)][Const::SRSCount];

public:
	static UInt2 GetRotateOffset(ESRSBlockType _RotateOffsetType, ERotateType _Rotate, unsigned int _RotateOffsetCount)
	{
		return OffsetList[static_cast<int>(_RotateOffsetType)][static_cast<int>(_Rotate)][_RotateOffsetCount];
	}
};