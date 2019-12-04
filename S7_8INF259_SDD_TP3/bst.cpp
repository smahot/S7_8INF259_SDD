#include "BST.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

BST::BST(int d)
{
	this->root = (node*)malloc(sizeof(node));
	if (this->root)
	{
		this->root->data = d;
		this->root->gauche = NULL;
		this->root->droite = NULL;
	}
	else cout << "Erreur, plus assez de memoire." << endl;
}
BST::BST()
{
	this->root = NULL;
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
				if (newNode)
				{
					newNode->gauche = NULL;
					newNode->droite = NULL;
					newNode->data = d;
					root->gauche = newNode;
				}
				else cout << "Erreur, plus assez de memoire." << endl;
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
				if (newNode)
				{
					newNode->gauche = NULL;
					newNode->droite = NULL;
					newNode->data = d;
					root->droite = newNode;
				}
				else cout << "Erreur, plus assez de memoire." << endl;
			}
			else
			{
				_Insert(root->droite, d);
			}
		}
	}
	else
	{
		this->root = (node*)malloc(sizeof(node));
		if (this->root)
		{
			this->root->data = d;
			this->root->gauche = NULL;
			this->root->droite = NULL;
		}
		else cout << "Erreur, plus assez de memoire." << endl;
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
void BST::Imprimer_decroissant()
{
	_affichage_decroissant(this->GetRootNode());
	cout << endl;
}
int BST::Print_height()
{
	return _Print_height(this->GetRootNode());
}
int BST::_Print_height(node* root)
{
	cout << "Equilibre des noeud postfixe (valeur:equilibre) : ";
	int hauteur = Hauteur(root);
	cout << endl;
	return hauteur;
}

int BST::Hauteur(node* root)
{
	int result = -1;
	if (root!= NULL)
	{		
		int hauteur_gauche = Hauteur(root->gauche);
		int hauteur_droite = Hauteur(root->droite);
		int equilibre = hauteur_droite - hauteur_gauche;
		cout << root->data << ":" << equilibre << " ";
		if (hauteur_droite > hauteur_gauche) result = hauteur_droite;
		else result = hauteur_gauche;
		result++;
	}	
	return result;
}
void BST::Print_ancetres(int d)
{
	vector<int> ancetres;
	this->_Print_ancetres(d, this->GetRootNode(), ancetres);

	if (ancetres.size() > 1)
	{
		cout << "Les ancetres de " << d << " sont : " << endl;
		for (int i : ancetres)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	else if (ancetres.size() == 1) cout << "L'ancetre de " << d << " est : " << ancetres[0] << endl;
	else cout << d << " n'a pas d'ancetres dans l'arbre" << endl;

}
node* BST::_Print_ancetres(int d, node* pNode, vector<int> &ancetres)
{
	if (pNode != NULL)
	{
		if (pNode->data == d) return pNode;
		else if (d < pNode->data && pNode->gauche != NULL)
		{
			ancetres.push_back(pNode->data);
			return this->_Print_ancetres(d, pNode->gauche, ancetres);
		}
		else if (d > pNode->data&& pNode->droite != NULL)
		{
			ancetres.push_back(pNode->data);
			return this->_Print_ancetres(d, pNode->droite, ancetres);
		}
		else return NULL;
	}
	else return NULL;
}
void BST::Print_childrens(int d)
{
	node* root = this->GetNode(d);
	if (root != NULL)
	{
		if (root->gauche != NULL) _affichage_infixe(root->gauche);
		if (root->droite != NULL) _affichage_infixe(root->droite);
	}
	cout << endl;
}
void BST::Niveau()
{
	int niveau = 0;
	vector<node*> nodesList;
	nodesList.push_back(this->GetRootNode());
	while (nodesList.size() > 0)
	{
		cout << "Niveau " << niveau << ": ";
		
		vector<node*> newNodesList;
		for (node* iNode : nodesList)
		{
			cout << iNode->data << " ";
			if (iNode->gauche) newNodesList.push_back(iNode->gauche);
			if (iNode->droite) newNodesList.push_back(iNode->droite);
		}
		cout << endl;
		nodesList = newNodesList;
		niveau++;
	}

}

node* BST::GetRootNode()
{
	return this->root;
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

void BST::_affichage_decroissant(node* root)
{
	if (root != NULL)
	{
		if (root->droite != NULL) _affichage_decroissant(root->droite);
		cout << root->data << " ";
		if (root->gauche != NULL) _affichage_decroissant(root->gauche);
	}
}

void afficher_offset(int offset)
{
	for (int i = 0; i < offset; i++)
	{
		cout << "  "; // 2 espaces
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
		_affichage_arborescence(arbre->gauche, offset + 1);


		// Etape 3 - appel récursif avec sous-arbre de droite
		_affichage_arborescence(arbre->droite, offset + 1);
	}
}

void BST::_affichage_arborescence_infixe(node* arbre, int offset)
{
	if (arbre != NULL)
	{
		// Etape 2 - appel récursif avec sous-arbre gauche
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