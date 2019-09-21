#include <iostream>
#include <string>
#include <fstream>
#include "dossierProfesseur.h"
#include <windows.h> //pour les accents
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
				cout << endl << "OP: supprimmer " << param1 << endl;
				dossierProf.Supprimer((char*)param1.c_str());
			}
			else if (entree == "&") // cours en commun
			{
				fichierTransaction >> param1 >> param2;
				cout << endl << "OP: nb de cours en commun " << param1 << " et "<< param2 << " : " << dossierProf.Commun((char*)param1.c_str(), (char*)param2.c_str()) << endl;
			}
			else if (entree == "+") // cours le plus demandé
			{
				cout << endl << "OP: cours le plus demandé : "<< dossierProf.LecoursLeplusDemande() << endl;
			}
			else if (entree == "*") // cours le plus ancien
			{
				cout << endl << "OP: prof le plus ancien : " << dossierProf.ProfeseurLeplusAncien() << endl;
			}
			else if (entree == "$") // recopier dans le fichier
			{
				fichierTransaction >> param1;
				cout << endl << "OP: recopier dans le fichier " << param1 << endl;
				dossierProf.Recopier((char*)param1.c_str());
			}
			else if (entree == "#") // fonctionnalitée supplémentaire : affichage
			{				
				cout << endl << "OP: affichage "<< endl;
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
	SetConsoleOutputCP(CP_UTF8); //pour les accents

	cout << "TP1 de Structures de données" << endl;
	cout << "Fait par :" << endl << "- Steve MAHOT" << endl << "- Nieves RODRIGUEZ ALVAR" << endl;
	DossierProfesseur unDossier = DossierProfesseur("FP.txt");
	TraitementDossierProf(unDossier, "FT.txt");
	system("pause");
}
