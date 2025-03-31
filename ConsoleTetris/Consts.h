#pragma once

namespace Const
{
	static inline const UInt2 RenderSize = { 40, 30 };
	
	static inline const unsigned int PlayBoardOutline = 1;
	static inline const wchar_t PlayBoardOutlinePixel = L'q';
	static inline const UInt2 PlayBoardImageLeftTop = { 3, 3 };

	static inline const UInt2 PlayBoardImageSize = { 10 + PlayBoardOutline * 2, 20 + PlayBoardOutline * 2 };
	static inline const UInt2 PlayBoardSize = { 10, 30 };
	
}