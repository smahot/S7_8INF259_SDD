#include <iostream>
#include "prefix.h"
#include <vector>
#include <windows.h>
using namespace std;

int main()
{
	//SetConsoleOutputCP(CP_UTF8);

	//string expression = "(5+8)/(2-3)";
	//string expression = "5+(8/2)*3";
	string expression = "((8/2)-(6/3))/(3*4/2)";
	std::vector<char> vect(expression.begin(), expression.end());
	Prefix p = Prefix(expression);
	p.transformerEnPrefixe(p.GetPile(), p.GetTableau());
	
	cout << p.valider_expression(vect) << endl;
	cout << p.prefixe(vect) << endl;	
		
	std::cout << "fin programme" << endl;
}