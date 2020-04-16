#include "ServiceMonede.h"
#include <algorithm>

using namespace std;

ServiceMonede::ServiceMonede()
{
	this->repo = RepoFisier <Moneda>();
}

ServiceMonede::~ServiceMonede() {}

ServiceMonede::ServiceMonede(const RepoFisier<Moneda>& r)
{
	this->repo = r;
}

int ServiceMonede::getSize()
{
	return this->repo.getSize();
}

void ServiceMonede::getAll(Moneda rez[])
{
	this->repo.getAll(rez);
}

void ServiceMonede::delMoneda(double val)
{
	Moneda lista[100];
	this->repo.getAll(lista);
	for(int i=0; i<this->getSize(); i++)
		if(lista[i].getValoare() == val)
			this->repo.delElem(lista[i]);
}

void ServiceMonede::updateMoneda(double val, int nr)
{
	Moneda lista[100];
	this->getAll(lista);
	for (int i = 0; i < this->getSize(); i++)
	{
		if (val == lista[i].getValoare())
		{
			Moneda m(val, nr);
			this->repo.updateElem(lista[i], m);
			break;
		}
			
	}
}

void ServiceMonede::Sortare()
{
	int size;
	Moneda lista[50], copie[50];
	this->getAll(lista);
	this->getAll(copie);
	size = this->getSize();
	sort(lista, lista + size, Comp); 
	for (int i = 0; i < size; i++)
		this->repo.updateElem(copie[i], lista[i]);
}

bool ServiceMonede::Rest(Moneda lista[], int size, double rest)
{
	int nr;
	for (int i = size - 1; i >= 0; i--)
	{
		while (rest >= lista[i].getValoare() && lista[i].getNumar() > 0)
		{
			rest -= lista[i].getValoare();
			nr = lista[i].getNumar();
			lista[i].setNumar(nr - 1);
		}
		if (rest == 0)
			return true;
	}
	return false;

}

bool Comp(Moneda m1, Moneda m2)
{
	return m1.getValoare() < m2.getValoare();
}
