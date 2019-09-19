#include <iostream>
#include <string>
#include <fstream>
#include "dossierProfesseur.h"
using namespace std;

//passage par référence du dossier prof
void TraitementDossierProf(DossierProfesseur &dossierProf, string nomFichierTransaction)
{
	ifstream fichierTransaction(nomFichierTransaction);  //Ouverture d'un fichier en lecture

	if (!fichierTransaction)
	{
		cout << "Le fichier transaction n'a pas pû être ouvert." << endl;
	}
	else
	{
		string entree, param1, param2;
		while (!fichierTransaction.eof())
		{
			fichierTransaction >> entree;

			if (entree == "%") // supprimer
			{
				fichierTransaction >> param1;
				cout << endl << "OP supprimmer " << param1 << endl;
				dossierProf.Supprimer((char*)param1.c_str());
			}
			else if (entree == "&")
			{
				fichierTransaction >> param1 >> param2;
				cout << endl << "OP nb de cours en commun " << param1 << " et "<< param2 << " : " << dossierProf.Commun((char*)param1.c_str(), (char*)param2.c_str()) << endl;
			}
			else if (entree == "+")
			{
				cout << endl << "OP cours le plus demandé : "<< dossierProf.LecoursLeplusDemande() << endl;
			}
			else if (entree == "*")
			{
				cout << endl << "OP prof le plus ancien : " << dossierProf.ProfeseurLeplusAncien() << endl;
			}
			else if (entree == "$")
			{
				fichierTransaction >> param1;
				cout << endl << "OP recopier dans le fichier " << param1 << endl;
				dossierProf.Recopier((char*)param1.c_str());
			}
			else if (entree == "#") // ajout affichage
			{				
				cout << endl << "OP affichage "<< endl;
				dossierProf.afficherListe();
			}
			else
			{
				cout << "error 404" << endl;
			}

		}
	}

}

int main()
{		
	DossierProfesseur unDossier = DossierProfesseur("dossier.txt");
	TraitementDossierProf(unDossier, "FT.txt");
	//cout << "Prof le plus ancien : " << unDossier.ProfeseurLeplusAncien() << endl;
	//cout << "Cours le plus demande : " << unDossier.LecoursLeplusDemande() << endl;
	//cout << "Nombre cours commum : " << unDossier.Commun("MAHOT Steve", "RODRIGUEZ ALVAR Nieves") << endl;
	//unDossier.Supprimer("MACRON Emmanuel");
	//unDossier.Recopier("fichierSortie.txt");
	system("pause");
}
