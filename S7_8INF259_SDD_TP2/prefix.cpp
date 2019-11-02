#include "prefix.h"

Prefix::Prefix(string str)
{
	this->tableau = vector<char>(str.begin(), str.end());
	this->pile = stack<char>();
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

void Prefix::transformerEnPrefixe(stack<char> pile, vector<char> tableau)
{
	stack<string> operandes;
	stack<char> operateurs;

	for (vector<char>::iterator i = tableau.begin(); i != tableau.end(); i++)
	{
		if ('0' <= *i && *i <= '9')
		{
			operandes.push(string(1,*i));
		}
		else // c'est un opérateur
		{
			if (*i == '(' || operateurs.empty() || prioriteOperateur(*i) > prioriteOperateur(operateurs.top()))
			{
				operateurs.push(*i);
			}
			else
			{
				if (*i == ')')
				{
					while (operateurs.top() != '(')
					{
						char op = operateurs.top();
						operateurs.pop();
						string opR = operandes.top();
						operandes.pop();
						string opL = operandes.top();
						operandes.pop();

						string newOp = op + opL + opR;
						operandes.push(newOp);
					}
					operateurs.pop();
				}
				else
				{
					if (prioriteOperateur(*i) <= prioriteOperateur(operateurs.top()))
					{
						while (!operateurs.empty() && prioriteOperateur(*i) <= prioriteOperateur(operateurs.top()))
						{
							char op = operateurs.top();
							operateurs.pop();
							string opR = operandes.top();
							operandes.pop();
							string opL = operandes.top();
							operandes.pop();

							string newOp = op + opL + opR;
							operandes.push(newOp);
						}
						operateurs.push(*i);
					}
				}
			}
		}
	}

	while (!operateurs.empty())
	{
		char op = operateurs.top();
		operateurs.pop();
		string opR = operandes.top();
		operandes.pop();
		string opL = operandes.top();
		operandes.pop();

		string newOp = op + opL + opR;
		operandes.push(newOp);
	}
	
	string expression_prefixe = operandes.top();
	vector<char> vect = vector<char>(expression_prefixe.begin(), expression_prefixe.end());

	for (vector<char>::iterator i = vect.begin(); i != vect.end(); i++)
	{
		this->pile.push(*i);
	}

	cout << expression_prefixe << endl;


}

int Prefix::evaluer_expression(stack<char> pile, vector<char> tableau)
{
	int result = 0;
	stack<int> nombres;
	for (vector<char>::iterator i = --(tableau.end()); i != tableau.begin(); i--)
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

int prioriteOperateur(char operateur)
{
	int resultat = 0;
	if (operateur == '*' || operateur == '/' || operateur == '%') resultat = 3;
	else if (operateur == '+' || operateur == '-') resultat = 2;
	return resultat;
}