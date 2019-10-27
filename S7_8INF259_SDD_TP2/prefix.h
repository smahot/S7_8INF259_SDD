#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Prefix
{
private:
	std::stack<char> pile;
	std::vector<char> tableau;
public:
	Prefix(string str);
	~Prefix();
	bool prefixe(vector<char> tableau);// lit l’expression à évaluer, à partir du clavier, dans tableau et valide si l’expression ne contient que les caractères ci - dessus, à savoir les nombres entiers composés de caractères nombres et les opérateurs ci - dessus.
	bool valider_expression(vector<char> tableau); // (bonus) teste si l’expression lue contient un nombre valide de parenthèses
	void transformerEnNombres(vector <char> tableau); // transforme les nombres lus en caractères en valeurs numériques
	void transformerEnPrefixe(stack<char> Pile, vector<char> tableau);// transforme l’expression lue en une expression préfixée et l’afficher.
	int evaluer_expression(stack<char> Pile, vector<char> tableau); // évalue l’expression préfixée et affiche sa valeur.

};