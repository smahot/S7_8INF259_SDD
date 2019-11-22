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
		std::cout << i << endl;
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

node* BST::GetParentNode(int d, node* pNode)
{
	if (pNode != NULL)
	{
		if (pNode->data == d) return NULL;
		else if (pNode->data < d)
		{
			if (pNode->gauche != NULL)
			{
				if (pNode->gauche->data == d) return pNode;
				else return GetParentNode(d, pNode->gauche);
			}
			else return NULL;
		}
		else
		{
			if (pNode->droite != NULL)
			{
				if (pNode->droite->data == d) return pNode;
				else return GetParentNode(d, pNode->droite);
			}
			else return NULL;
		}
	}
	return NULL;
}
