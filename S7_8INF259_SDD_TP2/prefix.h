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
	bool prefixe(vector<char> tableau);// lit l�expression � �valuer, � partir du clavier, dans tableau et valide si l�expression ne contient que les caract�res ci - dessus, � savoir les nombres entiers compos�s de caract�res nombres et les op�rateurs ci - dessus.
	bool valider_expression(vector<char> tableau); // (bonus) teste si l�expression lue contient un nombre valide de parenth�ses
	void transformerEnNombres(vector <char> tableau); // transforme les nombres lus en caract�res en valeurs num�riques
	void transformerEnPrefixe(stack<char> Pile, vector<char> tableau);// transforme l�expression lue en une expression pr�fix�e et l�afficher.
	int evaluer_expression(stack<char> Pile, vector<char> tableau); // �value l�expression pr�fix�e et affiche sa valeur.

};