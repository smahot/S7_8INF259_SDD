#include "prefix.h"

Prefix::Prefix(string str)
{
	std::vector<char> tableau(str.begin(), str.end());
	std::stack<char> pile;
}

Prefix::~Prefix()
{

}
bool Prefix::prefixe(vector<char> tableau)
{
	bool result = true;
	char listeCaracteresAutorises[] = "0123456789+-/*()";
	bool caractereEstValide = true;

	for (vector<char>::iterator i = tableau.begin(); i != tableau.end() && caractereEstValide; i++)
	{
		caractereEstValide = false;
		for (int j = 0; j < sizeof(listeCaracteresAutorises) / sizeof(char) && !caractereEstValide; j++)
		{
			if ((*i) == listeCaracteresAutorises[j]) caractereEstValide = true;
		}
	}
	return caractereEstValide;
}

bool Prefix::valider_expression(vector<char> tableau)
{
	bool result = false;
	int nbParenthesesOuvrantes = 0;
	int nbParenthesesFermantes = 0;

	for (vector<char>::iterator i = tableau.begin(); i != tableau.end(); i++)
	{
		if ((*i) == '(') nbParenthesesOuvrantes++;
		else if ((*i) == ')') nbParenthesesFermantes++;
	}
	if (nbParenthesesOuvrantes == nbParenthesesFermantes) result = true;
	return result;
}

void Prefix::transformerEnNombres(vector <char> tableau)
{

}

void Prefix::transformerEnPrefixe(stack<char> Pile, vector<char> tableau)
{

}

int Prefix::evaluer_expression(stack<char> Pile, vector<char> tableau)
{
	int result = 0;
	stack<int> nombres;
	for (vector<char>::iterator i = tableau.end(); i != tableau.begin(); i--)
	{
		
		if (*i == '/')
		{
			int b = nombres.top();
			nombres.pop();
			int a = nombres.top();
			nombres.pop();
			nombres.push(a / b);
		}
		else if (*i == '*')
		{
			int b = nombres.top();
			nombres.pop();
			int a = nombres.top();
			nombres.pop();
			nombres.push(a * b);
		}
		else if (*i == '+')
		{
			int b = nombres.top();
			nombres.pop();
			int a = nombres.top();
			nombres.pop();
			nombres.push(a + b);
		}
		else if (*i == '-')
		{
			int b = nombres.top();
			nombres.pop();
			int a = nombres.top();
			nombres.pop();
			nombres.push(a - b);
		}
		else if (*i == '%')
		{
			int b = nombres.top();
			nombres.pop();
			int a = nombres.top();
			nombres.pop();
			nombres.push(a % b);
		}
		else // est un chiffre
		{
			int a = (*i) - '0';
			nombres.push(a);
		}
		
	}
	result = nombres.top();
	return result;
}


stack<char> Prefix::GetPile()
{
	return this->pile;
}

vector<char> Prefix::GetTableau()
{
	return tableau;
}

