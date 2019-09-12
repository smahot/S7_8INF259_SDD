#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct cours {
	char* sigle;
	int nbEtudints;
	cours* suivant;
};

struct Professeur{
	char* nom;
	int anciennete;
	cours* listeCours;
	Professeur* suivant;
};

Professeur* creationListe(FILE* fichier) {
	Professeur* liste = (Professeur*)malloc(1*sizeof Professeur);
	if (fichier != NULL)
	{
		string ligne;
		ifstream entree;

	}
}

class DossierProfesseur {
	Professeur* tete;
};

int main()
{
    cout << "Hello World!\n"; 
}
