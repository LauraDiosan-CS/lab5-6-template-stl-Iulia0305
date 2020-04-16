#include <iostream>
#include <string.h>
#include <conio.h>
#include <string.h>
#include "Service.h"
#include "Repo.h"
#include "Produs.h"
#include "UI.h"
using namespace std;

UI::UI() {}
UI::UI(const Service& s, const ServiceMonede& sm)
{
	this->service = s;
	this->serviceMonede = sm;
}

void UI::showMeniu()
{
	cout << "0. Stop" << endl;
	cout << "1. Achizitionare produs" << endl;
	cout << "2. Meniu tonomat" << endl;
}

void UI::showMeniuTonomat()
{
	cout << "0. Stop" << endl;
	cout << "1. Adaugare produs" << endl;
	cout << "2. Stergere produs" << endl;
	cout << "3. Modificare produs:" << endl;
	cout << "		3a. Modificare nume produs dupa cod" << endl;
	cout << "		3b. Modificare pret produs dupa cod" << endl;
	cout << "		3c. Modificare pret si nume produs dupa cod" << endl;
	cout << "4. Afisare produse" << endl;
	cout << "5. Afisare monede" << endl;
}

void UI::adaugare()
{
	int cod;
	double pret;
	char* nume = new char[20];
	cout << "INtrodu codul produsului: ";
	cin >> cod;
	cout << "Introdu pretul produsului: ";
	cin >> pret;
	cout << "Introdu numele produsului: ";
	cin >> nume;
	this->service.addProdus(cod, pret, nume);
	delete[] nume;
}

void UI::stergere()
{
	int cod;
	cout << "Introdu codul produsului ce va fi sters: ";
	cin >> cod;
	this->service.delProdus(cod);
}

void UI::modificareNume()
{
	int cod;
	char* nume = new char[20];
	cout << "Introdu codul produsului ce va fi modificat: ";
	cin >> cod;
	cout << "Introdu noul nume: ";
	cin >> nume;
	this->service.updateProdus(cod, 0, nume);
	delete[] nume;
}

void UI::modificarePret()
{
	int cod;
	double pret;
	cout << "Introdu codul produsului ce va fi modificat: ";
	cin >> cod;
	cout << "Introdu noul pret: ";
	cin >> pret;
	this->service.updateProdus(cod, pret, NULL);
}

void UI::modificareNumePret()
{
	int cod;
	double pret;
	char* nume = new char[20];
	cout << "Introdu codul produsului ce va fi modificat: ";
	cin >> cod;
	cout << "Introdu noul nume: ";
	cin >> nume;
	cout << "Introdu noul pret: ";
	cin >> pret;
	this->service.updateProdus(cod, pret, nume);
	delete[] nume;
}

void UI::afisareProduse()
{
	Produs lista[100];
	int lungime = this->service.getSize();
	this->service.getAll(lista);
	for (int i = 0; i < lungime; i++)
		cout << lista[i].getCod() << " " << lista[i].getPret() << " " << lista[i].getNume() << endl;
}

void UI::AchizitionareProdus()
{
	Moneda lista[100];
	Produs p;
	int cod;
	double sumaProd, x;
	serviceMonede.getAll(lista);
	cout << "Cod produs: ";
	cin >> cod;
	p = service.getProdus(cod);
	sumaProd = p.getPret();
	while (sumaProd > 0)
	{
		cout << "Introdu moneda: ";
		cin >> x;
		sumaProd -= x;
		for(int i=0; i< serviceMonede.getSize(); i++)
			if (lista[i].getValoare() == x)
			{
				int nr = lista[i].getNumar();
				lista[i].setNumar(nr + 1);
				break;
			}
				
	}
	if (sumaProd != 0)
	{
		if (this->serviceMonede.Rest(lista, this->serviceMonede.getSize(), -sumaProd))
		{
			for (int i = 0; i < this->serviceMonede.getSize(); i++)
				this->serviceMonede.updateMoneda(lista[i].getValoare(), lista[i].getNumar());
			cout << "Pofta buna!" << endl;
				
		}
		else
			cout << "Bani insuficienti pentru rest!"  << endl;
	}
	else
	{
		cout << "Pofta buna!" << endl;
		for (int i = 0; i < this->serviceMonede.getSize(); i++)
			this->serviceMonede.updateMoneda(lista[i].getValoare(), lista[i].getNumar());
	}
}

void UI::afisareMonede()
{
	Moneda lista[100];
	this->serviceMonede.getAll(lista);
	for (int i = 0; i < this->serviceMonede.getSize(); i++)
		cout << lista[i] << endl;
}

void UI::run()
{
	char op[10];
	while (true)
	{
		this->showMeniu();
		cout << "Introdu optiunea: ";
		cin >> op;
		if (!strcmp(op, "1"))
		{
			this->afisareProduse();
			this->AchizitionareProdus();
		}
		else if (!strcmp(op, "2"))
		{
			string pass = "";
			char c;
			cout << "Introdu parola: ";
			c = _getch();
			while (c != 13)
			{
				pass.push_back(c);
				cout << "*";
				c = _getch();
			}
			cout << endl;
			if (pass == "admin")
			{
				while (true)
				{
					this->showMeniuTonomat();
					cout << "Introdu optiunea: ";
					cin >> op;
					if (!strcmp(op, "1")) this->adaugare();
					else if (!strcmp(op, "2")) this->stergere();
					else if (!strcmp(op, "3a")) this->modificareNume();
					else if (!strcmp(op, "3b")) this->modificarePret();
					else if (!strcmp(op, "3c")) this->modificareNumePret();
					else if (!strcmp(op, "4")) this->afisareProduse();
					else if (!strcmp(op, "5")) this->afisareMonede();
					else if (!strcmp(op, "0")) break;
					else cout << "Comanda incorecta!" << endl;
				}
			}
			else cout << "Parola incorecta!" << endl;
		}
		else if (!strcmp(op, "0")) break;
		else cout << "Comanda incorecta!" << endl;
		
	}
}