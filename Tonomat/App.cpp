#include <iostream>
#include "Produs.h"
#include "Repo.h"
#include "Tests.h"
#include "UI.h"

int main()
{
	// Parola pentru a intra in meniu tonomat este "admin" 
	system("color 0C");
	TestProdus();
	TestRepoFisier();
	TestServiceCRUD();
	TestMoneda();
	TestServiceMonede();
	TestRest();

	char* f1 = new char[20];
	char* f2 = new char[20];
	char* f3 = new char[20];
	char* f4 = new char[20];
	strcpy_s(f1, 14, "ProduseIn.txt");
	strcpy_s(f2, 14, "ProduseIn.txt");
	strcpy_s(f3, 13, "MonedeIn.txt");
	strcpy_s(f4, 13, "MonedeIn.txt");
	
	RepoFisier<Produs> repo(f1, f2);
	RepoFisier<Moneda> repoM(f3, f4);
	Service s(repo);
	ServiceMonede sm(repoM);
	UI ui(s, sm);
	ui.run();
	delete[] f1;
	delete[] f2;
	delete[] f3;
	delete[] f4;

	return 0;
}