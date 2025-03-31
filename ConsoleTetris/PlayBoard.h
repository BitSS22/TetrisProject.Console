#pragma once
#include "Image.h"

class CPlayBoard : public CImage
{
public:
	CPlayBoard();
	~CPlayBoard();

private:
	std::vector<std::vector<EBlockColor>> PlayBoard = {};

private:
	void DrawField();

public:
	void Draw(CImage& Dest, bool _NonePixelDraw = false) override;

};

