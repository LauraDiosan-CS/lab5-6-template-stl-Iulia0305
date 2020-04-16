#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
using namespace std;

template <class T>
class Repo
{
private:
	vector <T> elemente;
public:
	Repo() {}

	~Repo() 
	{
		this->elemente.clear();
	}

	void addElem(T& e)
	{
		int ok = 1;
		for (int i = 0; i < this->getSize(); i++)
			if (e == this->elemente[i])
				ok = 0;
		if (ok)
			elemente.push_back(e);	
	}

	void getAll(T rez[])
	{
		for (int i = 0; i < this->getSize(); i++)
			rez[i] = elemente[i];
	}

	T getElem(int c)
	{
		for (int i = 0; i < this->getSize(); i++)
			if (c == elemente[i].getCod())
				return elemente[i];
	}

	void delElem(T e)
	{
		for (int i = 0; i < this->getSize(); i++)
			if (e == this->elemente[i])
				elemente.erase(elemente.begin() + i);
	}

	void updateElem(T& e1, T& e2)
	{
		for (int i = 0; i < this->getSize(); i++)
			if (e1 == elemente[i])
				elemente[i] = e2;
				
	}

	int getSize()
	{
		return this->elemente.size();
	}
};