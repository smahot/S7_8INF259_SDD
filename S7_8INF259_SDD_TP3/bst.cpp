#include "BST.h"
#include <stdlib.h>
#include <iostream>


using namespace std;

BST::BST(int d)
{
	this->root = (node*)malloc(sizeof(node));
	this->root->data = d;
	this->root->gauche = NULL;
	this->root->droite = NULL;
}
BST::~BST()
{
	delete this->root;
}
void BST::Insert(int d)
{
	_Insert(this->GetRootNode(), d);
}
void BST::Insert(vector<int> vect)
{
	for (int i : vect)
	{
		_Insert(this->GetRootNode(), i);
	}
}
void BST::_Insert(node* root, int d)
{
	if (root != NULL)
	{
		if (d < root->data)
		{
			if (root->gauche == NULL)
			{
				node* newNode = (node*)malloc(sizeof(node));
				newNode->gauche = NULL;
				newNode->droite = NULL;
				newNode->data = d;
				root->gauche = newNode;
			}
			else
			{
				_Insert(root->gauche, d);
			}
		}
		else
		{
			if (root->droite == NULL)
			{
				node* newNode = (node*)malloc(sizeof(node));
				newNode->gauche = NULL;
				newNode->droite = NULL;
				newNode->data = d;
				root->droite = newNode;
			}
			else
			{
				_Insert(root->droite, d);
			}
		}
	}
}
void BST::Delete(int d)
{
	this->root = _Delete(this->GetRootNode(), d);
}
node* BST::_Delete(node* pNode, int d)
{
	if (pNode == NULL) return NULL;
	else
	{
		node* newNode;
		if (d > pNode->data)
		{
			newNode = pNode;
			newNode->droite = _Delete(pNode->droite, d);
		}
		else if (d < pNode->data)
		{
			newNode = pNode;
			newNode->gauche = _Delete(pNode->gauche, d);
		}
		else // d == pNode->data
		{
			if (pNode->gauche == NULL && pNode->droite == NULL) newNode = NULL;
			else if (pNode->gauche != NULL && pNode->droite == NULL) newNode = pNode->gauche;
			else if (pNode->gauche == NULL && pNode->droite != NULL) newNode = pNode->droite;
			else // (pNode->gauche != NULL && pNode->droite != NULL)
			{
				newNode = pNode;
				int newValue = maxValue(pNode->gauche);
				newNode->data = newValue;
				newNode->gauche = _Delete(pNode->gauche, newValue);
			}
		}
		return newNode;
	}
}
void BST::Imprimer_decroissant(node* root)
{

}
int BST::Print_height(node* root)
{
	
	return 0;
}
void BST::Print_ancetres(node* root, int d)
{

}
void BST::Print_childrens(node* root, int d)
{

}
void BST::Niveau(node* root)
{

}

node* BST::GetRootNode()
{
	return this->root;
}

bool estFeuille(node* noeud)
{
	bool result = false;
	if (noeud != NULL)
	{
		if (noeud->gauche != NULL || noeud->droite != NULL)
		{
			result = true;
		}
	}
	return result;
}
node* BST::GetParentNode(int d)
{
	return this->_GetParentNode(d, this->GetRootNode());
}
node* BST::_GetParentNode(int d, node* pNode)
{
	if (pNode != NULL)
	{
		if (pNode->data == d) return NULL;
		else if (pNode->data < d)
		{
			if (pNode->gauche != NULL)
			{
				if (pNode->gauche->data == d) return pNode;
				else return _GetParentNode(d, pNode->gauche);
			}
			else return NULL;
		}
		else
		{
			if (pNode->droite != NULL)
			{
				if (pNode->droite->data == d) return pNode;
				else return _GetParentNode(d, pNode->droite);
			}
			else return NULL;
		}
	}
	return NULL;
}
node* BST::GetNode(int d)
{
	return this->_GetNode(d, this->GetRootNode());
}

node* BST::_GetNode(int d, node* pNode)
{
	if (pNode != NULL)
	{
		if (pNode->data == d) return pNode;
		else if (d < pNode->data && pNode->gauche != NULL)
		{
			return this->_GetNode(d, pNode->gauche);
		}
		else if (d > pNode->data && pNode->droite != NULL)
		{
			return this->_GetNode(d, pNode->droite);
		}
		else return NULL;
	}
	else return NULL;
}
int BST::maxValue(node* root)
{
	if (root->droite != NULL) return maxValue(root->droite);
	else return root->data;
}
void BST::affichage_infixe()
{
	_affichage_infixe(this->GetRootNode());
	cout << endl;
}
void BST::_affichage_infixe(node* root)
{
	if (root != NULL)
	{
		if (root->gauche != NULL) _affichage_infixe(root->gauche);
		cout << root->data << " ";
		if (root->droite != NULL) _affichage_infixe(root->droite);
	}
}

void afficher_offset(int offset)
{
	for (int i = 0; i < offset; i++)
	{
		printf("  "); // 2 espaces
	}
}

void BST::_affichage_arborescence(node* arbre, int offset)
{
	if (arbre != NULL)
	{
		// Etape 1 - afficher la valeur
		printf("\n");
		afficher_offset(offset);
		if (offset != 0)
		{
			printf("|- ");
		}
		printf("%d", arbre->data);

		// Etape 2 - appel récursif avec sous-arbre gauche
		/*if (!estFeuille(arbre) && arbre->gauche == NULL)
		{
			printf("\n");
			afficher_offset(offset + 1);
			printf("|- x");
		}*/
		_affichage_arborescence(arbre->gauche, offset + 1);


		// Etape 3 - appel récursif avec sous-arbre de droite
		/*if (!estFeuille(arbre) && arbre->droite == NULL)
		{
			printf("\n");
			afficher_offset(offset + 1);
			printf("|- x");
		}*/
		_affichage_arborescence(arbre->droite, offset + 1);
	}
}

void BST::_affichage_arborescence_infixe(node* arbre, int offset)
{
	if (arbre != NULL)
	{
		// Etape 2 - appel récursif avec sous-arbre gauche
		/*if (!estFeuille(arbre) && arbre->gauche == NULL)
		{
			printf("\n");
			afficher_offset(offset + 1);
			//printf("|- x");
		}*/
		_affichage_arborescence_infixe(arbre->gauche, offset + 1);

		// Etape 1 - afficher la valeur
		printf("\n");
		afficher_offset(offset);
		if (offset != 0)
		{
			printf("|- ");
		}
		printf("%d", arbre->data);

		// Etape 3 - appel récursif avec sous-arbre de droite
		/*if (!estFeuille(arbre) && arbre->droite == NULL)
		{
			printf("\n");
			afficher_offset(offset + 1);
			printf("|- x");
		}*/
		_affichage_arborescence_infixe(arbre->droite, offset + 1);
	}
}

void BST::affichage_arborescence()
{
	_affichage_arborescence(this->GetRootNode(), 0);
	cout << endl;
}

void BST::affichage_arborescence_infixe()
{
	_affichage_arborescence_infixe(this->GetRootNode(), 0);
	cout << endl;
}