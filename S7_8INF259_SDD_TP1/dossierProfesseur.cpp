#include "dossierProfesseur.h"
using namespace std;

//Constructeur
DossierProfesseur::DossierProfesseur(char* FP){
	//déclaration et ouverture du fichier
	ifstream entree;
	entree.open(FP);

	this->tete = NULL;

	if (entree.fail()) cout << "Problème d'ouverture. Fichier inexistant ou endommagé." << endl;
	else
	{
		string ligne;
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

//Destructeur
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
	Professeur* pointeurProfesseur = tete->suivant;
	//déclaration d'un pointeur pour gerder en mémoire la position précédente. Au départ il s'agit de la tete
	Professeur* pointeurPrecedent = tete;
	if (pointeurProfesseur && pointeurPrecedent)
	{
		while (pointeurProfesseur != NULL)
		{
			if (strcmp(pointeurPrecedent->nom, nom) == 0)
			{
				tete = pointeurProfesseur;
				delete pointeurPrecedent;
				cout << "Suppression de l'element ok. En tete." << endl;
			}
			else if (strcmp(pointeurProfesseur->nom, nom) == 0 && pointeurProfesseur->suivant != NULL)
			{
				pointeurPrecedent->suivant = pointeurProfesseur->suivant;
				delete pointeurProfesseur;
				cout << "Suppression de l'element ok. Ni en tete ni en queue." << endl;
				break;
			}
			else if (strcmp(pointeurProfesseur->nom, nom) == 0 && pointeurProfesseur->suivant == NULL)
			{
				pointeurPrecedent->suivant = NULL;
				delete pointeurProfesseur;
				cout << "Suppression de l'element ok. En queue." << endl;
				break;
			}
			pointeurPrecedent = pointeurProfesseur;
			pointeurProfesseur = pointeurProfesseur->suivant;
		}
	}
}

//Méthode qui compte le nombre d ecours commun entre deux profs.
int DossierProfesseur::Commun(char* X, char* Y) {
	int nombreCoursCommun = 0;
	Professeur* pointeurProfesseur = tete;
	Cours* listeCoursProfX = NULL;
	Cours* listeCoursProfY = NULL;
	while (pointeurProfesseur != NULL)
	{
		if (strcmp(pointeurProfesseur->nom, X) == 0) listeCoursProfX = pointeurProfesseur->listeCours;
		if (strcmp(pointeurProfesseur->nom, Y) == 0) listeCoursProfY = pointeurProfesseur->listeCours;
		pointeurProfesseur = pointeurProfesseur->suivant;
	}
	while (listeCoursProfX != NULL)
	{
		Cours* copieListeProfY = listeCoursProfY;
		while (copieListeProfY != NULL)
		{
			if (strcmp(listeCoursProfX->sigle, copieListeProfY->sigle) == 0) nombreCoursCommun++;
			copieListeProfY = copieListeProfY->suivant;
		}
		listeCoursProfX = listeCoursProfX->suivant;
	}
	return nombreCoursCommun;
}

/*
Renvoie le cours le plus demandé.
Si plusieurs cours ont le même nombre d'étudiants, renvoie le premier trouvé.
Car la signature imposée de la fonction ne permet pas de renvoyer plusieurs cours.
*/
char* DossierProfesseur::LecoursLeplusDemande() const {
	//Déclaration du paramètre que l'on recupèrera en sortie
	char* coursLePlusDemande = NULL;
	int nombreEleve = -1;
	Professeur* pointeurProfesseur = tete; //pointeur vers le professeur
	while (pointeurProfesseur != NULL)
	{
		Cours* pointeurCours = pointeurProfesseur->listeCours; //pointeur vers le cours
		while (pointeurCours != NULL)
		{
			//Si le cours a un nb d'étudiant supérieur à celui en mémoire alors on actualise
			if (pointeurCours->nbEtudiants > nombreEleve)
			{
				coursLePlusDemande = pointeurCours->sigle;
				nombreEleve = pointeurCours->nbEtudiants;
			}
			pointeurCours = pointeurCours->suivant;
		}
		pointeurProfesseur = pointeurProfesseur->suivant;
	}
	return coursLePlusDemande;
}

/*
Renvoie le professeur le plus ancien.
Si plusieurs professeur ont la même ancienneté, renvoie le premier trouvé.
Car la signature imposée de la fonction ne permet pas de renvoyer plusieurs noms.
*/
char* DossierProfesseur::ProfeseurLeplusAncien() const {
	Professeur* profLePlusAge = tete; // pointeur vers le professeur le plus ancien
	Professeur* pointeurProfesseur = tete; // pointeur vers le professeur qui est lu actuellement
	int ancienneteMax = tete->anciennete; // ancienneté du professeur le plus ancien trouvé
	
	// boucle sur les professeurs
	while (pointeurProfesseur->suivant)
	{
		//on passe au prof suivant
		pointeurProfesseur = pointeurProfesseur->suivant;

		//si le prof suivant est plus ancien, on maj les infos sur le prof le plus ancien
		if (pointeurProfesseur->anciennete > ancienneteMax)
		{
			profLePlusAge = pointeurProfesseur;
			ancienneteMax = pointeurProfesseur->anciennete;
		}
	}
	return profLePlusAge->nom;
}

//Recopie à partir de la liste chaînée le nom, ancienneté et le nombre de cours demandés pour chaque professeur dans le fichier texte Nouveau.
void DossierProfesseur::Recopier(char* Nouveau) {
	Professeur* pointeurProfesseur = tete;
	ofstream fichierSortie(Nouveau, ios::out | ios::trunc);
	if (fichierSortie)
	{
		while (pointeurProfesseur != NULL)
		{
			fichierSortie << pointeurProfesseur->nom << endl;
			fichierSortie << pointeurProfesseur->anciennete << endl;
			Cours* pointeurCours = pointeurProfesseur->listeCours;
			int compteur = 0;
			while (pointeurCours != NULL)
			{
				compteur++;
				//il rentre jamais dans cette boucle
				//fichierSortie << pointeurCours->sigle << endl;
				//fichierSortie << pointeurCours->nbEtudiants << endl;
				pointeurCours = pointeurCours->suivant;
			}
			fichierSortie << "Nombre de cours : " << compteur << endl;
			fichierSortie << "&" << endl;
			pointeurProfesseur = pointeurProfesseur->suivant;
		}
		fichierSortie.close();
	}
	else cout << "Erreur à l'ouverture !" << endl;
}

//Affiche la liste chaînée
void DossierProfesseur::afficherListe(){
	Professeur* pointeurProfesseur = tete;
	if (tete == NULL) cout << "Liste NULL  ." << endl;
	while (pointeurProfesseur != NULL)
	{
		cout << "nom : " << pointeurProfesseur->nom << endl;
		cout << "anciennete : " << pointeurProfesseur->anciennete << endl;
		Cours* pointeurCours = pointeurProfesseur->listeCours;
		while (pointeurCours != NULL)
		{
			cout << "Nom cours : " << pointeurProfesseur->listeCours->sigle << endl;
			cout << "Nb etudiants : " << pointeurProfesseur->listeCours->nbEtudiants << endl;
			pointeurCours = pointeurCours->suivant;
		}
		pointeurProfesseur = pointeurProfesseur->suivant;
	}
}