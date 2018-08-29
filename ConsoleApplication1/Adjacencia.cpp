#include "Adjacencia.h"
#include <iostream>

Adjacencia::Adjacencia()
{
}

Adjacencia::Adjacencia(Vertice * para, float peso)
{
	this->para = para;
	this->peso = peso;
}

Adjacencia::~Adjacencia()
{
}

string Adjacencia::getNome()
{
	return para->getNome();
}

float Adjacencia::getPeso()
{
	return this->peso;
}

Vertice * Adjacencia::getVertice()
{
	return para;
}
