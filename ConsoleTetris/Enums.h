#pragma once

enum class EShape : wchar_t
{
	NONE = L'бр',
	BLOCK = L'бс',
	OUTLINE = L'в╦',
	DEBUG = L'D',
	END

};

enum class EColorType
{
	SKY,
	BLUE,
	ORANGE,
	YELLOW,
	GREEN,
	PURPLE,
	RED,
	GRAY,
	END
};

enum class EMinoType
{
	I,
	J,
	L,
	O,
	S,
	T,
	Z,
	END
};

enum class ERotateType
{
	NONE,
	RIGHT,
	FLIP,
	LEFT,
	END
};

ERotateType& operator++ (ERotateType& _Rotate);
ERotateType& operator-- (ERotateType& _Rotate);

enum class ESRSBlockType
{
	I,
	O,
	ELSE,
	END
};