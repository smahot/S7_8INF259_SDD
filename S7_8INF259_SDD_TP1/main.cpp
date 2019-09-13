#include <iostream>
#include <string>
#include <fstream>
#include "dossierProfesseur.h"
using namespace std;

int main()
{
    cout << "Hello World!\n";
	{
		DossierProfesseur dossierProf("dossier.txt");
	}
	
	system("pause");
}
