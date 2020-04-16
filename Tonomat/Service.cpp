#include <iostream>
#include "Service.h"
#include "Repo.h"

Service::Service()
{
	
}

Service::Service(const RepoFisier<Produs>& rep)
{
	this->repo = rep;
}

Service::~Service() {}

void Service::addProdus(int c, double pr, char* n)
{
	Produs p(c, pr, n);
	this->repo.addElem(p);
}

void Service::delProdus(int cod)
{
	Produs lista[100];
	this->repo.getAll(lista);
	for(int i=0; i<this->getSize(); i++)
		if(lista[i].getCod() == cod)
			this->repo.delElem(lista[i]);
}

void Service::updateProdus(int c, double pr, char* n)
{
	Produs prod = this->repo.getElem(c);
	if (pr && n)
	{
		Produs p(c, pr, n);
		this->repo.updateElem(prod, p);
	}
	else
		if (pr)
		{
			Produs p(c, pr, prod.getNume());
			this->repo.updateElem(prod, p);
		}
		else
		{
			Produs p(c, prod.getPret(), n);
			this->repo.updateElem(prod, p);
		}
}

void Service::getAll(Produs rez[])
{
	this->repo.getAll(rez);
}

Produs Service::getProdus(int cod)
{
	return this->repo.getElem(cod);
}

int Service::getSize()
{
	return this->repo.getSize();
}