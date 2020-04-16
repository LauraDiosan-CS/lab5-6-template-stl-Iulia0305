#pragma once
#include <iostream>
#include "Service.h"
#include "RepoFisier.h"
#include "Produs.h"
#include "ServiceMonede.h"

using namespace std;

class UI
{
private:
	Service service;
	ServiceMonede serviceMonede;
public:
	UI();
	UI(const Service& s, const ServiceMonede& sm);
	void showMeniu();
	void showMeniuTonomat();
	void adaugare();
	void stergere();
	void modificareNume();
	void modificarePret();
	void modificareNumePret();
	void afisareProduse();
	void AchizitionareProdus();
	void afisareMonede();
	void run();
};