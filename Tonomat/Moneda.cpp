#include "Moneda.h"
#include <fstream>
#include <ostream>
#include <istream>

using namespace std;

Moneda::Moneda()
{
	this->valoare = 0;
	this->numar = 0;
}

Moneda::~Moneda() {}

Moneda::Moneda(double v, int nr)
{
	this->valoare = v;
	this->numar = nr;
}

Moneda::Moneda(const Moneda& m)
{
	this->valoare = m.valoare;
	this->numar = m.numar;
}

double Moneda::getValoare()
{
	return this->valoare;
}

int Moneda::getNumar()
{
	return this->numar;
}

void Moneda::setValoare(double val)
{
	this->valoare = val;
}

void Moneda::setNumar(int nr)
{
	this->numar = nr;
}

Moneda& Moneda::operator=(const Moneda& m)
{
	this->valoare = m.valoare;
	this->numar = m.numar;
	return* this;
}

bool Moneda::operator==(const Moneda& m)
{
	return (this->valoare == m.valoare && this->numar == m.numar);
}

bool Moneda::operator!()
{
	if (this->valoare == 0 or this->numar == 0)
		return true;
	return false;
}

ostream& operator<<(ostream& os, const Moneda& m)
{
	os << m.valoare << " " << m.numar;
	return os;
}

istream& operator>>(istream& is, Moneda& m)
{
	int nr = 0;
	double val = 0;
	if (&is == &cin)
		cout << "Introdu valoarea: ";
	is >> val;
	if (&is == &cin)
		cout << "Introdu numarul de monede: ";
	is >> nr;
	m.setValoare(val);
	m.setNumar(nr);
	return is;
}
