#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include "Repo.h"
using namespace std;

template < class T>
class RepoFisier : public Repo <T>
{
private:
	char* fisierin;
	char* fisierout;
public:
	RepoFisier()
	{
		this->fisierin = NULL;
		this->fisierout = NULL;
	}

	~RepoFisier()
	{
		delete[] this->fisierin;
		delete[] this->fisierout;
		fisierin = NULL;
		fisierout = NULL;
	}

	RepoFisier(const char* fin, const char* fout)
	{
		this->fisierin = new char[strlen(fin) + 1];
		this->fisierout = new char[strlen(fout) + 1];
		strcpy_s(this->fisierin, strlen(fin) + 1, fin);
		strcpy_s(this->fisierout, strlen(fout) + 1, fout);
		this->loadFromFisier();
	}

	RepoFisier(const RepoFisier& r)
	{
		fisierin = new char[strlen(r.fisierin) + 1];
		fisierout = new char[strlen(r.fisierout) + 1];
		strcpy_s(fisierin, strlen(r.fisierin) + 1, r.fisierin);
		strcpy_s(fisierout, strlen(r.fisierout) + 1, r.fisierout);
		loadFromFisier();
	}

	RepoFisier& operator=(const RepoFisier& r)
	{
		setNameFisierIn(r.fisierin);
		setNameFisierOut(r.fisierout);
		loadFromFisier();
		return *this;
	}
	
	void setNameFisierIn(const char* fin)
	{
		if (this->fisierin != NULL)
			delete[] this->fisierin;
		if (fin == NULL)
			fisierin = NULL;
		else
		{
			this->fisierin = new char[strlen(fin) + 1];
			strcpy_s(this->fisierin, strlen(fin) + 1, fin);
		}
	}

	void setNameFisierOut(const char* fout)
	{
		if (this->fisierout != NULL)
			delete[] this->fisierout;
		if (fout == NULL)
			fisierout = NULL;
		else
		{
			this->fisierout = new char[strlen(fout) + 1];
			strcpy_s(this->fisierout, strlen(fout) + 1, fout);
		}
	}

	void saveToFisier()
	{
		if (this->fisierout != NULL)
		{
			T lista[100];
			Repo<T>::getAll(lista);
			ofstream out(this->fisierout);
			for (int i = 0; i < this->getSize(); i++)
				out << lista[i] << endl;
			out.close();
		}
	}

	void loadFromFisier()
	{
		if (this->fisierin != NULL)
		{
			T e;

			ifstream f(this->fisierin);
			while (!f.eof())
			{
				f >> e;
				if(!!e)
					this->addElem(e);
			}
			f.close();
		}
	}

	int getSize()
	{
		return Repo<T>::getSize();
	}

	void getAll(T rez[])
	{
		Repo<T>::getAll(rez);
	}

	void addElem(T& e)
	{
		Repo<T>::addElem(e);
		saveToFisier();
	}

	void delElem(T e)
	{
		Repo<T>::delElem(e);
		saveToFisier();
	}

	void updateElem(T& e1, T& e2)
	{
		Repo<T>::updateElem(e1, e2);
		saveToFisier();
	}

	T getElem(int cod)
	{
		return Repo<T>::getElem(cod);
	}
};


