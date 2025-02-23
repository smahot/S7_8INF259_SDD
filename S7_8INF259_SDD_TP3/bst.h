#include <stdbool.h>
#include <vector>

using namespace std;

typedef struct node {	
	int data;
	struct node* gauche;
	struct node* droite;
} node;

class BST {
private:
	node* root; // La racine de l’arbre BST
public:
	BST(int d); // Construit l’arbre dont la racine contient la donnée d.
	BST();
	~BST(); // Désalloue l’espace mémoire occupé par l’arbre.
	void Insert(int d); // Insérer l’élément de valeur d dans l’arbre à partir de la racine.
	void Insert(vector<int> vect); // Insérer l’élément de valeur d dans l’arbre à partir de la racine.
	void _Insert(node* root, int d); // Insérer l’élément de valeur d dans l’arbre.
	void Delete(int d); // Supprime l’élément de valeur d de l’arbre.
	node* _Delete(node* root, int d); // Renvoie le noeud root sans la valeur d
	void Imprimer_decroissant(); //Affiche les éléments de l’arbre dans l’ordre décroissant.
	int Print_height(); //Affiche la hauteur de l’arbre et par la même occasion l’équilibre ou le déséquilibre de chaque noeud.
	int _Print_height(node* root);
	int Hauteur(node* root);
	void Print_ancetres(int d); //Affiche les ascendants de l’élément de valeur d. (bonus 15pts)
	node* _Print_ancetres(int d, node* pNode, vector<int> &ancetres);
	void Print_childrens(int d); //Affiche les descendants de l’élément de valeur d.
	void Niveau(); // afficher niveau par niveau les éléments de l’arbre.
	node* GetRootNode(); // Retourne le noeud root
	node* GetParentNode(int d); // Retourne le noeud parent
	node* _GetParentNode(int d, node* pNode); // Retourne le noeud parent
	node* GetNode(int d); // Retourne le noeud contenant la valeur d
	node* _GetNode(int d, node* pNode); // Retourne le noeud contenant la valeur d
	int maxValue(node* root);
	void affichage_infixe();
	void _affichage_infixe(node* root);
	void _affichage_decroissant(node* root);
	void _affichage_arborescence(node* arbre, int offset);
	void _affichage_arborescence_infixe(node* arbre, int offset);
	void affichage_arborescence();
	void affichage_arborescence_infixe();
};

bool estFeuille(node* noeud);