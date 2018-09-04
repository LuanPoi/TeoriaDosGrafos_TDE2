#pragma once
#include "Vertice.h"
#include <string>

using namespace std;

class Adjacencia
{
private:
	float peso;
	Vertice* para;
	Adjacencia();

public:
	Adjacencia(Vertice *para, float peso);
	string getNome();
	int getIndice();
	float getPeso();
	Vertice* getVertice();
	~Adjacencia();
};

