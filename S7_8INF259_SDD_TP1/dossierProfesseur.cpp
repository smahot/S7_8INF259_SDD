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
	entree.close();
}

//destructeur
DossierProfesseur::~DossierProfesseur() {
	Professeur* pointeurProfesseur = tete;

	while (pointeurProfesseur)
	{
		pointeurProfesseur->anciennete = 0;
		delete pointeurProfesseur->nom;
		pointeurProfesseur->nom = NULL;

		Cours* pointeurCours = pointeurProfesseur->listeCours;		
		while (pointeurCours)
		{
			delete pointeurCours->sigle;
			pointeurCours->sigle = NULL;
			pointeurCours->nbEtudiants = 0;

			Cours* pointeurCoursSup = pointeurCours;
			pointeurCours = pointeurCours->suivant;
			delete pointeurCoursSup;
		}
		pointeurProfesseur->listeCours = NULL;

		Professeur* pointeurProfesseurSup = pointeurProfesseur;
		pointeurProfesseur = pointeurProfesseur->suivant;
		delete pointeurProfesseurSup;
	}
	tete = NULL;
}

//Méthode pour supprimer un professeur du dossier
void DossierProfesseur::Supprimer(char* nom) {
	//déclaration d'un pointeur temporaire afin de parcourir la liste sans perdre ni modifier la tete
	Professeur** pointeurProfesseur = &tete;
	//déclaration d'un pointeur pour gerder en mémoire la position précédente. Au départ il s'agit de la tete
	Professeur** pointeurPrecedent = &tete;

	(*pointeurProfesseur) = (Professeur*)malloc(sizeof(Professeur));
	(*pointeurPrecedent) = (Professeur*)malloc(sizeof(Professeur));

	if ((*pointeurProfesseur) && (*pointeurPrecedent))
	{
		while ((*pointeurProfesseur) != NULL && (*pointeurProfesseur)->nom != nom)
		{
			(*pointeurPrecedent) = (*pointeurProfesseur);
			(*pointeurProfesseur) = (*pointeurProfesseur)->suivant;
		}
		if ((*pointeurProfesseur)->nom == nom && (*pointeurProfesseur)->suivant != NULL)
		{
			(*pointeurPrecedent)->suivant = (*pointeurProfesseur)->suivant;
			delete (*pointeurProfesseur);
			cout << "Suppression ok. Pas en queue.";
		}
		else if ((*pointeurProfesseur)->nom == nom && (*pointeurProfesseur)->suivant == NULL)
		{
			(*pointeurPrecedent)->suivant = NULL;
			delete (*pointeurProfesseur);
			cout << "Suppression ok. En queue.";
		}
		else cout << "Le professeur n'apparait pas dans la liste. Nous n'avons pas effectuer sa suppression." << endl;
	}
}

int DossierProfesseur::Commun(char* X, char* Y) {
	return -1;
}

char* DossierProfesseur::LecoursLeplusDemande() const {
	//Déclaration du paramètre que l'on recupèrera en sortie
	char* coursLePlusDemande = (char*)malloc(7*sizeof(char));

	return coursLePlusDemande;
}

char* DossierProfesseur::ProfeseurLeplusAncien() const {
	char* kirikou = (char*)malloc(sizeof(char));
	return kirikou;
}

void DossierProfesseur::Recopier(char* Nouveau) {

}

void DossierProfesseur::afficherListe()
{
	Professeur* temp = tete;
	if (tete == NULL) cout << "Liste NULL  ." << endl;
	while (temp != NULL)
	{
		cout << "nom : " << temp->nom << endl;
		cout << "anciennete : " << temp->anciennete << endl;
		while (temp->listeCours != NULL)
		{
			cout << "Nom cours : " << temp->listeCours->sigle << endl;
			cout << "Nb etudiants : " << temp->listeCours->nbEtudiants << endl;
			temp->listeCours = temp->listeCours->suivant;
		}
		temp = temp->suivant;
	}
}