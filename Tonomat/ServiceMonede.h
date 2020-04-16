#pragma once
#include <iostream>
#include <algorithm>
#include "RepoFisier.h"
#include "Moneda.h"
#include "Produs.h"
using namespace std;

bool Comp(Moneda m1, Moneda m2);

class ServiceMonede
{
private:
	RepoFisier <Moneda> repo;
public:
	ServiceMonede();
	~ServiceMonede();
	ServiceMonede(const RepoFisier <Moneda>& r);
	int getSize();
	void getAll(Moneda rez[]);
	void delMoneda(double val);
	void updateMoneda(double val, int nr);
	void Sortare();
	bool Rest(Moneda lista[], int size, double rest);
};
