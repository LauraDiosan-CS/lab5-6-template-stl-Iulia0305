#pragma once
#include <iostream>
using namespace std;

class Moneda
{
private:
	double valoare;
	int numar;
public:
	Moneda();
	~Moneda();
	Moneda(double v, int nr);
	Moneda(const Moneda& m);
	double getValoare();
	int getNumar();
	void setValoare(double val);
	void setNumar(int nr);
	Moneda& operator=(const Moneda& m);
	bool operator==(const Moneda& m);
	bool operator!();
	friend ostream& operator<<(ostream& os, const Moneda& m);
	friend istream& operator>>(istream& is, Moneda& m);
};
