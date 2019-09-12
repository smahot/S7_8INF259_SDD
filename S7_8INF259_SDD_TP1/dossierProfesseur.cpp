#include "dossierProfesseur.h"

Professeur* creationListe(FILE* fichier) {
	Professeur* liste = (Professeur*)malloc(1*sizeof Professeur);
	if (fichier != NULL)
	{
		string ligne;
		ifstream entree;

	}
	return liste;
}

class DossierProfesseur {
private:
	Professeur* tete;

public:
	DossierProfesseur(char* FP)
	{

	}

	~DossierProfesseur()
	{

	}

	void Supprimer(char* NOM)
	{

	}
	int Commun(char* X, char* Y)
	{

	}
	char* LecoursLeplusDemande() const
	{

	}
	char* ProfeseurLeplusAncien() const
	{

	}
	void Recopier(char* Nouveau)
	{
		
	}
};