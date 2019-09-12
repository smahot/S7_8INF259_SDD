#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct Cours {
	char* sigle;
	int nbEtudints;
	Cours* suivant;
};

struct Professeur{
	char* nom;
	int anciennete;
	Cours* listeCours;
	Professeur* suivant;
};

class DossierProfesseur {
private:
	Professeur* tete; // d�but de la liste cha�n�e.
public:
	DossierProfesseur(char* FP); // construit la liste cha�n�e en m�moire � partir du fichier FP.
	~DossierProfesseur(); // d�truit la liste cha�n�e existant en m�moire.
	void Supprimer(char* NOM); // supprime de la liste cha�n�e le professeur NOM.
	int Commun(char* X, char* Y); // affiche le nombre de cours en commun entre les profs X et Y.
	char* LecoursLeplusDemande() const; // affiche le cours le plus demand� de la liste cha�n�e. En	cas de solutions multiples, prendre celui ayant le plus d��tudiants.
	char* ProfeseurLeplusAncien() const; // affiche le nom du professeur le plus ancien.
	void Recopier(char* Nouveau); // recopie � partir de la liste cha�n�e le nom, anciennet� et le nombre de cours demand�s pour chaque professeur dans le fichier texte Nouveau.
};