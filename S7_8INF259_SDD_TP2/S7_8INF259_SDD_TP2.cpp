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
	string expression = "(3*4/2)/((8/2)-(6/3))";
	std::vector<char> vect(expression.begin(), expression.end());
	Prefix p = Prefix(expression);
	p.transformerEnPrefixe(p.GetPile(), p.GetTableau());
	
	cout << p.valider_expression(vect) << endl;
	cout << p.prefixe(vect) << endl;	
	cout << p.evaluer_expression(p.GetPile(), p.GetTableau());
		
	std::cout << "fin programme" << endl;
}