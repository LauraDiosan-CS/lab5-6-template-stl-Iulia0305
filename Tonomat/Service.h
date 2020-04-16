#pragma once
#include <iostream>
#include "Produs.h"
#include "RepoFisier.h"
using namespace std;

class Service
{
private:
	RepoFisier <Produs> repo;
public:
	Service();
	Service(const RepoFisier<Produs>& rep);
	~Service();
	void addProdus(int c, double pr, char* n);
	void delProdus(int cod);
	void updateProdus(int c, double pr, char* n);
	void getAll(Produs rez[]);
	Produs getProdus(int cod);
	int getSize();
};
