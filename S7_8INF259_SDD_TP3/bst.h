#include <stdbool.h>

typedef struct node {	
	int data;
	struct node* gauche;
	struct node* droit;
} node;

class BST
{
private:
	node* root; // La racine de l’arbre BST
public:
	BST(node* root, int d); // Construit l’arbre dont la racine contient la donnée d.
	~BST(); // Désalloue l’espace mémoire occupé par l’arbre.
	void Insert(node* root, int d); // Insérer l’élément de valeur d dans l’arbre.
	void Delete(node* root, int d); // Supprime l’élément de valeur d de l’arbre.
	void Imprimer_decroissant(node* root); //Affiche les éléments de l’arbre dans l’ordre décroissant.
	int Print_height(node* root); //Affiche la hauteur de l’arbre et par la même occasion l’équilibre ou le déséquilibre de chaque noeud.
	void Print_ancetres(node* root, int d); //Affiche les ascendants de l’élément de valeur d. (bonus 15pts)
	void Print_childrens(node* root, int d); //Affiche les descendants de l’élément de valeur d.
	void Niveau(node* root); // afficher niveau par niveau les éléments de l’arbre.
};
