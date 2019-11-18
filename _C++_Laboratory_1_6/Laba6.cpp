#include "Laba6.h"
#include "MD5.h"

void Zadacha8()
{
	cout << "Imput your expression: " << endl;
	char* expr = new char[256];
	char* expr_temp = new char[256];
	cin.getline(expr, 256);
	for (int i = 0, g = 0; i < Strlength(expr); i++)
	{
		if (expr[i] != ' ')
			expr_temp[g++] = expr[i];
	}
	expr = expr_temp;
	for (int i = 0; expr[i] > 0; i++) if (!isdigit(expr[i]) && expr[i] != '+' && expr[i] != '-' && expr[i] != '/' && expr[i] != '*' && expr[i] != '(' && expr[i] != ')')
	{
		cout << "Incorrect Input!" << endl;
		return;
	}
	Areph expression(expr);
	int result = expression.Expression();
	cout << result << endl;
}

void Zadacha14()
{
	ofstream fo;
	fo.open("file");
	fo << "sldfnsdfdn222222222222222222";
	fo.close();

	ifstream t("file");
	string str;

	t.seekg(0, ios::end);
	str.reserve(t.tellg());
	t.seekg(0, ios::beg);

	str.assign((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());

	cout << "md5 of your file: \t" << md5(str) << endl;
}


int Areph::Number()
{
	int result = get() - '0';
	while (peek() >= '0' && peek() <= '9')
	{
		result = 10 * result + get() - '0';
	}
	return result;
}

int Areph::Factor()
{
	if (peek() >= '0' && peek() <= '9')
		return Number();
	else if (peek() == '(')
	{
		get(); // '('
		int result = Expression();
		get(); // ')'
		return result;
	}
	else if (peek() == '-')
	{
		get();
		return -Factor();
	}
	return 0; // error
}

int Areph::Term()
{
	int result = Factor();
	while (peek() == '*' || peek() == '/')
		if (get() == '*')
			result *= Factor();
		else
			result /= Factor();
	return result;
}

int Areph::Expression()
{
	int result = Term();
	while (peek() == '+' || peek() == '-')
		if (get() == '+')
			result += Term();
		else
			result -= Term();
	return result;
}

int Strlength(char* str)
{
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}
