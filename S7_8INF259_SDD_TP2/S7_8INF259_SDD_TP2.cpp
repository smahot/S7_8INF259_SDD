#include <iostream>
#include "prefix.h"
#include <vector>
#include <windows.h>
using namespace std;


int main()
{
	//SetConsoleOutputCP(CP_UTF8);

	string expression = "5+(10/2)*3";
	std::vector<char> vect(expression.begin(), expression.end());
	Prefix p = Prefix(expression);

	cout << p.prefixe(vect) << endl;



	std::cout << "fin programme" << endl;
}