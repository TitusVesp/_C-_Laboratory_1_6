#pragma once
#include <iostream>
#include <fstream>

using namespace std;
void Zadacha8();
int Strlength(char* str);

class Areph
{
private:
	char* expressionToParse;
	char peek()
	{
		return *expressionToParse;
	}

	char get()
	{
		return *expressionToParse++;
	}

	int Number();
	int Factor();
	int Term();
public:
	Areph(char *str)
	{
		expressionToParse = str;
	}

	int Expression();
};


void Zadacha14();
