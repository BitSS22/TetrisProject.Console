#include "pch.h"
#include "GameEngine.h"
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Korean");

	CGameEngine Engine = {};
	Engine.MainLoop();

	return 0;
}