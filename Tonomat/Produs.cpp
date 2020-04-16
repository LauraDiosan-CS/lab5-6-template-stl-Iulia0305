#include <iostream>
#include "Produs.h"
#include <string.h>
#include <ostream>
#include <istream>
using namespace std;

Produs::Produs()
{
	this->cod = 0;
	this->pret = 0;
	this->nume = NULL;
}

Produs::Produs(int c, double p, char* n)
{
	this->cod = c;
	this->pret = p;
	if (n == NULL)
		this->nume = NULL;
	else
	{
		this->nume = new char[strlen(n) + 1];
		strcpy_s(this->nume, strlen(n) + 1, n);
	}
}

Produs::Produs(const Produs& p)
{
	this->cod = p.cod;
	this->pret = p.pret;

	if (p.nume == NULL)
		this->nume = NULL;
	else {

		this->nume = new char[strlen(p.nume) + 1];
		strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
	}
}

Produs::~Produs()
{
	delete[] this->nume;
	this->nume = NULL;
}

int Produs::getCod()
{
	return this->cod;
}

double Produs::getPret()
{
	return this->pret;
}

char* Produs::getNume()
{
	return this->nume;  
}

void Produs::setCod(int c)
{
	this->cod = c;
}

void Produs::setPret(double pr)
{
	this->pret = pr;
}

void Produs::setNume(char* n)
{
	if (this->nume != NULL)
		delete[] this->nume;
	if (n == NULL)
		this->nume = NULL;
	else
	{
		this->nume = new char[strlen(n) + 1];
		strcpy_s(this->nume, strlen(n) + 1, n);
	}
}

Produs& Produs::operator=(const Produs& p)
{
	this->cod = p.cod;
	this->pret = p.pret;
	this->setNume(p.nume);
	return* this;
}

bool Produs::operator==(const Produs& p)
{
	if (this->nume == NULL && p.nume == NULL)
		return (this->cod == p.cod && this->pret == p.pret);
	if (this->nume == NULL or p.nume == NULL)
		return false;
	return (this->cod == p.cod && this->pret == p.pret && (strcmp(this->nume, p.nume) == 0));
}

bool Produs::operator!()
{
	if (this->cod == 0 or this->pret == 0 or strlen(this->nume) == 0)
		return true;
	return false;
}

ostream& operator<<(ostream& os, const Produs& p)
{
	os << p.cod << " " << p.pret << " " << p.nume;
	return os;
}

istream& operator>>(istream& is, Produs& p)
{
	int cod;
	double pret;
	char* nume = new char[50];
	if (&is == &cin)
		cout << "Introdu codul produsului: ";
	is >> cod;
	if (&is == &cin)
		cout << "Introdu pretul produsului: ";
	is >> pret;
	if (&is == &cin)
		cout << "Introdu numele produsului: ";
	is >> nume;
	p.setCod(cod);
	p.setPret(pret);
	p.setNume(nume);
	delete[] nume;
	return is;
}