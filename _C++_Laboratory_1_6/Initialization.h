#pragma once
#include "OOP_Menu.h"
#include "Laba6.h"

class Init
{
private:
	Menu lab6;
public:

	Init()
	{
		lab6.AddMenuItem("������ 8, 8 ���i���: ", Zadacha8);
		lab6.AddMenuItem("������ 14, 8 ���i���: ", Zadacha14);
	}
	void Show_Lab()
	{
		lab6.ShowMenu();
	}
};