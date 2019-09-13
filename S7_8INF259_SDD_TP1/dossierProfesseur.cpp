#include "dossierProfesseur.h"
using namespace std;

//constructeur
DossierProfesseur::DossierProfesseur(char* FP){
	//déclaration et ouverture du fichier
	ifstream entree;
	entree.open(FP);

	this->tete = NULL;

	if (entree.fail()) cout << "Problème d'ouverture. Fichier inexistant ou endommagé." << endl;
	else
	{
		string ligne;

		this->tete = NULL;
		//pointeur vers l'adresse du pointeur vers le professeur
		Professeur** pointeurProfesseur = &tete;

		//boucle des profs
		while (getline(entree, ligne))
		{
			(*pointeurProfesseur) = (Professeur*)malloc(sizeof(Professeur));

			//condition à vérifier cf avertissement C6011 : https://docs.microsoft.com/fr-fr/visualstudio/code-quality/c6011?view=vs-2019
			if (*pointeurProfesseur)
			{
				//allocation du pointeur nom et copie de la ligne dans l'espace mémoire du pointeur
				(*pointeurProfesseur)->nom = new char[ligne.length() + 1];
				strcpy((*pointeurProfesseur)->nom, (char*)ligne.c_str());

				//ligne suivante
				getline(entree, ligne);

				(*pointeurProfesseur)->anciennete = atoi(ligne.c_str());
				
				(*pointeurProfesseur)->listeCours = NULL;
				Cours** pointeurCours = &(*pointeurProfesseur)->listeCours;
				//boucle des cours
				while (getline(entree, ligne) && ligne != "&")
				{
					(*pointeurCours) = (Cours*)malloc(sizeof(Cours));

					if (*pointeurCours) //C6011
					{
						(*pointeurCours)->sigle = new char[ligne.length() + 1];
						strcpy((*pointeurCours)->sigle, (char*)ligne.c_str());

						getline(entree, ligne);

						(*pointeurCours)->nbEtudiants = atoi(ligne.c_str());
						(*pointeurCours)->suivant = NULL;
						if (*pointeurCours) pointeurCours = &(*pointeurCours)->suivant; //C6011
					}
				}

				(*pointeurProfesseur)->suivant = NULL;
				if (*pointeurProfesseur) pointeurProfesseur = &(*pointeurProfesseur)->suivant; //C6011
			}
		}
	}
}

//destructeur
DossierProfesseur::~DossierProfesseur() {

}

void DossierProfesseur::Supprimer(char* nom) {

}

int DossierProfesseur::Commun(char* X, char* Y) {
	return -1;
}

char* DossierProfesseur::LecoursLeplusDemande() const {
	char* kirikou = (char*)malloc(sizeof(char));
	return kirikou;
}

char* DossierProfesseur::ProfeseurLeplusAncien() const {
	char* kirikou = (char*)malloc(sizeof(char));
	return kirikou;
}

void DossierProfesseur::Recopier(char* Nouveau) {

}