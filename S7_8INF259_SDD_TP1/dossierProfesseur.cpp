#include "dossierProfesseur.h"

DossierProfesseur::DossierProfesseur(char* FP){
	tete = new Professeur;
	Professeur* temp = tete;
	ifstream entree;
	entree.open(FP);
	if (entree.fail())cout << "Probleme d'ouverture. Fichier inexistant ou endomage." << endl;
	else
	{
		string ligne;
		int i = 0;
		while (getline(entree, ligne))
		{
			if (i == 0) tete[0].nom = (char*)ligne.c_str();
			else if (i == 1) tete[0].anciennete = atoi(ligne.c_str());
			else if (i % 2 == 0 && ligne[0] != '&');

		}
	}
}

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