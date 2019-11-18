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
		lab6.AddMenuItem("Задача 8, 8 Варiант: ", Zadacha8);
		lab6.AddMenuItem("Задача 14, 8 Варiант: ", Zadacha14);
	}
	void Show_Lab()
	{
		lab6.ShowMenu();
	}
};