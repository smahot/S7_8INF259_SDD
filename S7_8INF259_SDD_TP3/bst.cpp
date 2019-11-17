#include "BST.h"
#include <stdlib.h>

BST::BST(int d)
{
	this->root = (node*)malloc(sizeof(node));
	this->root->data = d;
	this->root->gauche = NULL;
	this->root->droite = NULL;
}
BST::~BST()
{

}
void BST::Insert(node* root, int d)
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
				Insert(root->gauche, d);
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
				Insert(root->droite, d);
			}
		}
	}
}
void BST::Delete(node* root, int d)
{

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
