#include <iostream>
#include "bst.h"
#include <vector>
using namespace std;

int main()
{
	BST arbre = BST(10);
	std::vector<int> vect { 5,12,3,9,16,13,11,6,8 };
	arbre.Insert(vect);
	arbre.affichage_infixe();
	//arbre.affichage_arborescence_infixe();
	arbre.Delete(12);
	arbre.affichage_infixe();
	//arbre.affichage_arborescence_infixe();

	arbre.Print_childrens(11);
	arbre.Niveau();

	std::cout << "Fin programme" << endl;
}