#pragma once

struct UInt2
{
public:
	UInt2() {}
	UInt2(int _X, int _Y)
		: X(_X)
		, Y(_Y) {}
	UInt2(unsigned int _X, unsigned int _Y)
		: X(_X)
		, Y(_Y) {
	}

public:
	unsigned int X = 0;
	unsigned int Y = 0;

};