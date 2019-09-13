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

		this->tete = (Professeur*)malloc(sizeof(Professeur));
		Professeur* pointeurProfesseur = tete;

		//boucle des profs
		while (ligne != "&" && getline(entree, ligne))
		{
			//condition à vérifier pour utiliser un attribut d'un pointeur attribué dynamiquement, cf avertissement C6011 : https://docs.microsoft.com/fr-fr/visualstudio/code-quality/c6011?view=vs-2019
			if (pointeurProfesseur)
			{
				pointeurProfesseur->suivant = (Professeur*)malloc(sizeof(Professeur));

				//allocation du pointeur nom et copie de la ligne dans l'espace mémoire du pointeur
				pointeurProfesseur->nom = new char[ligne.length() + 1];
				strcpy(pointeurProfesseur->nom, (char*)ligne.c_str());

				//ligne suivante
				getline(entree, ligne);

				pointeurProfesseur->anciennete = atoi(ligne.c_str());
				
				pointeurProfesseur->listeCours = (Cours*)malloc(sizeof(Cours));
				Cours* pointeurCours = pointeurProfesseur->listeCours;
				//boucle des cours
				while (getline(entree, ligne) && ligne != "&")
				{
					if (!pointeurCours)
					pointeurCours = (Cours*)malloc(sizeof(Cours));

					if (pointeurCours)
					{
						pointeurCours->sigle = new char[ligne.length() + 1];
						strcpy(pointeurCours->sigle, (char*)ligne.c_str());

						getline(entree, ligne);

						pointeurCours->nbEtudiants = atoi(ligne.c_str());
						pointeurCours->suivant = NULL;
					}
				}

				pointeurProfesseur->suivant = NULL;
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