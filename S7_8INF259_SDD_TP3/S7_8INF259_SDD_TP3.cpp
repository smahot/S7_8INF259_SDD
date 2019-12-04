#include <iostream>
#include <fstream>
#include "bst.h"
#include <vector>
#include <stdlib.h> 
#include <windows.h>
using namespace std;

void ExecutionOperations(string fileName, BST arbre)
{
	ifstream fichierTransaction(fileName);  //Ouverture d'un fichier en lecture

	if (!fichierTransaction)
	{
		cout << "Le fichier transaction n'a pas pû être ouvert." << endl;
	}
	else
	{
		string entree;
		while (!fichierTransaction.eof())
		{
			fichierTransaction >> entree;

			if (entree[0] == 'I') //insérer l’élément de valeur x dans l’arbre binaire de recherche.
			{
				int valeur = atoi(entree.substr(2).c_str());
				cout << entree << " : Insersion de " << valeur << " dans l'arbre." << endl;
				arbre.Insert(valeur);
			}
			else if (entree[0] == 'D') // supprimer l’élément de valeur x de l’arbre binaire de recherche.
			{
				int valeur = atoi(entree.substr(2).c_str());
				cout << entree << " : Suppresion de " << valeur << " dans l'arbre." << endl;
				arbre.Delete(valeur);
			}
			else if (entree[0] == 'P') // afficher les éléments de l’arbre binaire de recherche dans l’ordre décroissant.
			{
				cout << entree << " : Afficher les éléments de l’arbre binaire de recherche dans l’ordre décroissant" << endl;
				arbre.Imprimer_decroissant();
			}
			else if (entree[0] == 'H') // afficher la hauteur de l’arbre binaire de recherche et l`équilibre ou le déséquilibre de chaque noeud.
			{
				cout << entree << " : Afficher la hauteur de l’arbre binaire de recherche et l`équilibre ou le déséquilibre de chaque noeud" << endl;
				cout << "Hauteur de l'arbre : " << arbre.Print_height() << endl;
			}
			else if (entree[0] == 'N') // afficher niveau par niveau les éléments de l’arbre.
			{
				cout << entree << " : Afficher niveau par niveau les éléments de l’arbre" << endl;
				arbre.Niveau();
				cout << endl << "Affichage alternatif :";
				arbre.affichage_arborescence();
			}
			else if (entree[0] == 'A') // afficher les ascendants de l’élément de valeur x.
			{
				int valeur = atoi(entree.substr(2).c_str());
				cout << entree << " : Afficher les ascendants de l’élément de valeur " << valeur << endl;
				arbre.Print_ancetres(valeur);
			}
			else if (entree[0] == 'C') // afficher les descendants de l’élément de valeur x.
			{
				int valeur = atoi(entree.substr(2).c_str());
				cout << entree << " : Afficher les descendants de l’élément de valeur " << valeur << endl;
				arbre.Print_childrens(valeur);
			}
			else
			{
				cout << "Instruction inconnue" << endl;
			}
			cout << endl;
		}
	}
}

int main()
{
	SetConsoleOutputCP(CP_UTF8); //pour les accents

	cout << "TP3 de Structures de données" << endl;
	cout << "Fait par :" << endl << "- Steve MAHOT" << endl << "- Nieves RODRIGUEZ ALVAR" << endl << endl;

	BST arbre = BST();

	ExecutionOperations("FT.txt", arbre);

	{/*
		BST arbre = BST(10);
		std::vector<int> vect{ 5,12,3,9,16,13,11,6,8 };
		arbre.Insert(vect);
		arbre.affichage_infixe();
		//arbre.affichage_arborescence();
		arbre.Delete(12);
		arbre.affichage_infixe();
		arbre.affichage_arborescence();

		arbre.Print_childrens(11);
		arbre.Niveau();

		arbre.Imprimer_decroissant();

		arbre.Print_ancetres(9);

		cout << "Hauteur de l'arbre : " << arbre.Print_height() << endl;
		arbre.Niveau();
	*/}	

	std::cout << endl << "Fin programme" << endl;
	system("pause");
}