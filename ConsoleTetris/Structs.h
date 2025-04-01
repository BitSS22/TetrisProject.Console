#pragma once

struct Pixel
{
public:
	Pixel() {}
	Pixel(EShape _Shape, EColorType _Color)
		: Shape(_Shape)
		, Color(_Color)	{}
	~Pixel() {}

public:
	EShape Shape = EShape::NONE;
	EColorType Color = EColorType::GRAY;

};

struct UInt2
{
public:
	UInt2() {}
	UInt2(int _X, int _Y)
		: X(_X)
		, Y(_Y) {}
	UInt2(unsigned int _X, unsigned int _Y)
		: X(_X)
		, Y(_Y) {}

public:
	unsigned int X = 0;
	unsigned int Y = 0;

// Operator
public:
	UInt2 operator+ (UInt2 _Other)
	{
		return UInt2(X + _Other.X, Y + _Other.Y);
	}

};