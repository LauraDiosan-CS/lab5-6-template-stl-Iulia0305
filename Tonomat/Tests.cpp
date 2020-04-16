#include <iostream>
#include "Produs.h"
#include "Moneda.h"
#include "RepoFisier.h"
#include "Service.h"
#include "ServiceMonede.h"
#include <assert.h>
#include <string.h>
#include <vector>

void TestProdus()
{
	char* cola = new char[10];
	char* covrigi = new char[10];
	strcpy_s(cola, 5, "cola");
	strcpy_s(covrigi, 8, "covrigi");
	Produs p1(1, 1.5, covrigi);
	Produs p2(2, 2.5, cola);
	Produs p3(2, 2.5, cola);

	assert(p1.getCod() == 1);
	assert(p2.getPret() == 2.5);
	assert(strcmp(p2.getNume(), cola) == 0);
	assert(p2 == p3);

	delete[] cola;
	delete[] covrigi;
}

void TestRepoFisier()
{
	char* testin = new char[20];
	char* testout = new char[20];
	strcpy_s(testin, 11, "TestIn.txt");
	strcpy_s(testout, 12, "TestOut.txt");
	RepoFisier <Produs> repo(testin, testout);
	char* cola = new char[10];
	char* apa = new char[10];
	char* covrigi = new char[10];
	strcpy_s(cola, 5, "cola");
	strcpy_s(covrigi, 8, "covrigi");
	strcpy_s(apa, 4, "apa");
	
	Produs p1(1, 1.5, covrigi);
	Produs p2(2, 3.5, cola);
	Produs p3(1, 2.5, apa);
	repo.addElem(p1);
	repo.addElem(p2);
	
	assert(repo.getSize() == 4);
	assert(repo.getElem(2) == p2);

	repo.updateElem(p1, p3);
	repo.delElem(p2);

	assert(repo.getSize() == 3);
	assert(repo.getElem(1) == p3);

	delete[] cola;
	delete[] covrigi;
	delete[] apa;
	delete[] testin;
	delete[] testout;
}

void TestServiceCRUD()
{
	Service service;
	Produs p1, p2;
	char* cola = new char[10];
	char* covrigi = new char[10];
	char* apa = new char[10];
	strcpy_s(cola, 5, "cola");
	strcpy_s(covrigi, 8, "covrigi");
	strcpy_s(apa, 4, "apa");
	service.addProdus(1, 2.5, apa);
	service.addProdus(2, 3.5, cola);
	service.addProdus(3, 1.5, covrigi);
	service.delProdus(1);
	p1 = service.getProdus(2);
	p2 = service.getProdus(3);

	assert(service.getSize() == 2);
	assert(p1.getPret() == 3.5);
	assert(p2.getPret() == 1.5);

	delete[] cola;
	delete[] covrigi;
	delete[] apa;
}

void TestMoneda()
{
	Moneda m1(0.5, 4);
	Moneda m2(1, 5);
	assert(m1.getNumar() == 4);
	assert(m1.getValoare() == 0.5);
	assert(m2.getNumar() == 5);
	assert(m2.getValoare() == 1);
}

void TestServiceMonede()
{
	char* testin = new char[30];
	char* testout = new char[20];
	strcpy_s(testin, 22, "TestServiceMonede.txt");
	strcpy_s(testout, 12, "TestOut.txt");
	RepoFisier <Moneda> repo(testin, testout);
	ServiceMonede sm(repo);
	assert(sm.getSize() == 3);
	
	sm.delMoneda(5);
	assert(sm.getSize() == 2);

	delete[] testin;
	delete[] testout;
}

void TestRest()
{
	double rest = 2.5;
	bool ok;
	ServiceMonede s;
	Moneda lista[7];
	for (int i = 0; i < 7; i++)
	{
		lista[i].setValoare(0);
		lista[i].setNumar(0);
	}
	Moneda m1(0.5, 10);
	Moneda m2(1, 10);
	Moneda m3(5, 10);
	lista[0] = m1;
	lista[1] = m2;
	lista[2] = m3;
	ok = s.Rest(lista, 3, rest);
	assert(ok == true);
	assert(lista[0].getNumar() == 9);
	assert(lista[1].getNumar() == 8);
	assert(lista[2].getNumar() == 10);
}
