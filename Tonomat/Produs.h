#pragma once
#include <iostream>
using namespace std;

class Produs
{
private:
	int cod;
	double pret;
	char* nume;
public:
	Produs();
	~Produs();
	Produs(int c, double p, char* n);
	Produs(const Produs& p);
	int getCod();
	double getPret();
	char* getNume();
	void setCod(int c);
	void setPret(double pr);
	void setNume(char* n);
	Produs& operator=(const Produs& p);
	bool operator==(const Produs& p);
	bool operator!();
	friend ostream& operator<<(ostream& os, const Produs& p);
	friend istream& operator>>(istream& is, Produs& p);
};
