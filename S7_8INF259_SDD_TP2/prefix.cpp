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
			if (*i == listeCaracteresAutorises[j]) caractereEstValide = true;
		}
	}
	return caractereEstValide;
}

bool Prefix::valider_expression(vector<char> tableau)
{
	bool result = false;
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
	return result;
}

