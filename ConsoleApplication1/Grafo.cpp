#include "Grafo.h"
#include <vector>
#include <string>
#include <list>

Grafo::Grafo()
{
}

Grafo::Grafo(int tamanho)
{
	this->tamanho = tamanho;
	this->lista = new list<Adjacencia>[tamanho];
	
	this->vertices = new Vertice[tamanho];

	for (int i = 0; i < tamanho; ++i) {
		vertices[i].setNome("[" + to_string(i) + "]");
		vertices[i].setIndice(i);
	}
}

Grafo::~Grafo()
{
}

bool Grafo::cria_adjacencia(int de, int para, float peso)
{
	if (de > this->tamanho || para > this->tamanho || de < 0 || para < 0) {
		return false;
	}else if (lista[de].empty()) {
		lista[de].push_back(Adjacencia(getVertices(para), peso));
		return true;
	}

	for (auto it = lista[de].begin(); it != lista[de].end(); it++) {
		if (it->getIndice() == para) {
			return false; //erro~, já existe a adj.
		}
		else if (it->getIndice() > para) {
			lista[de].insert(it, Adjacencia(getVertices(para), peso));
			return true;
		}
	}

	lista[de].push_back(Adjacencia(getVertices(para), peso));
	return true;
}

bool Grafo::remove_adjacencia(int de, int para)
{
	if (de > this->tamanho || para > this->tamanho || de < 0 || para < 0) {
		return false;
	}
	else if (lista[de].empty()) {
		return true;
	}

	for (auto it = lista[de].begin(); it != lista[de].end(); it++) {
		if (it->getIndice() == para) {
			lista[de].erase(it);
			return true; 
		}
		else if (it->getIndice() > para) {
			return false;
		}
	}
	return false;
}

list<Adjacencia> Grafo::adjacentes(int indice)
{
	for (auto it = lista[indice].begin(); it != lista[indice].end(); it++) {
		cout << it->getIndice() << " ";
	}
	cout << endl;
	return this->lista[indice];
}

bool Grafo::seta_informacoes(int indice, string nome)
{
	this->vertices[indice].setNome(nome);
	return true;
}

void Grafo::printaNome(int indice) {
	cout << this->vertices[indice].getNome() << endl;
}

void Grafo::imprime() {
	for (int i = 0; i < tamanho; ++i) {
		cout << "-->";
		for (auto it = lista[i].begin(); it != lista[i].end(); it++) {
			cout << it->getNome() << " --> ";
		}
		cout << "NULL" << endl;
	}
}

Vertice* Grafo::getVertices(int indice) {
	return &vertices[indice];
}
