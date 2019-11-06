#include <iostream>
#include "prefix.h"
#include <vector>
#include <windows.h>
using namespace std;

int main()
{
	//SetConsoleOutputCP(CP_UTF8);

	cout << "TP2 de Structures de donnees" << endl;
	cout << "Fait par :" << endl << "- Steve MAHOT" << endl << "- Nieves RODRIGUEZ ALVAR" << endl;

	string expression;
	cout << "Entrez une expression infixe. " << endl
		 << "Les divisions doivent etre entieres, les nombres ne sont pas pris en charge et ne mettez pas d'espaces." << endl
		 << "Exemple: (3*4/2)/((8/2)-(6/3))" << endl;

	cin >> expression;
	//expression = (3*4/2)/((8/2)-(6/3));

	//création de l'objet prefix
	Prefix p = Prefix(expression);

	//conversion en préfixe
	bool valide1 = p.prefixe(p.GetTableau());
	bool valide2 = p.valider_expression(p.GetTableau());

	cout << "Expression avec des caracteres valides ? '0123456789+-/*%()' 0:Vrai, 1:Faux : " << valide1 << endl;
	cout << "Expression valide ? (Autant de '(' que de ')' 0:Vrai, 1:Faux               : " << valide2 << endl;

	if (valide1 && valide2)
	{
		cout << "Expression prefixe                                                         : ";
		p.transformerEnPrefixe(p.GetPile(), p.GetTableau());
		cout << "Calcul de l'expression prefixe (division d'int sans reste)                 : "
			 << p.evaluer_expression(p.GetPile(), p.GetTableau()) << endl;
	}
	else
	{
		cout << "Expression non valide, relancez le programme." << endl;
	}
		
	std::cout << "Fin du programme" << endl;
	system("pause");
}