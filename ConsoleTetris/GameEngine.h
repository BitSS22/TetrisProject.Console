#pragma once

class CImage;

class CGameEngine
{
private:
	CGameEngine() {}

private:
	static void Render(const CImage& _Image, UInt2 _LeftTop);

public:
	static void MainLoop();

};

