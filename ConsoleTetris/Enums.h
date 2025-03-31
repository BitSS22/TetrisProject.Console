#pragma once

enum class ERenderPixel : wchar_t
{
	NONE = L'0',
	OUTLINE = L'q',
	DEBUG = L'D',
	END
};

enum class EBlockColor
{
	SKY,
	BLUE,
	ORANGE,
	YELLOW,
	GREEN,
	PURPLE,
	RED,
	Gray,
	NONE,
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