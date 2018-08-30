#include "Grafo.h"
#include <vector>

Grafo::Grafo()
{
}

Grafo::Grafo(int tamanho)
{
	this->tamanho = tamanho;
	vector<Adjacencia> ADJ;
	
	for (int i = 0; i < tamanho; ++i) {
		lista.push_back(ADJ);
	}
}

Grafo::~Grafo()
{
}

bool Grafo::cria_adjacencia(int de, int para, float peso)
{
	if (vertices[de] != NULL && vertices[para] != NULL) {
		matrizADJ[de][para] = peso;
		return true;
	}
	return false;
}

bool Grafo::remove_adjacencia(int de, int para)
{
	matrizADJ[de][para] = INFINITY;
	return true;
}

bool Grafo::cria_vertice(int indice, string nome) {
	if (vertices[indice] == NULL) {
		vertices[indice] = new Vertice(nome, indice);
		return true;
	}
	return false;
}

bool Grafo::cria_vertice(int indice){
	if (vertices[indice] == NULL) {
		vertices[indice] = new Vertice(indice);
		matrizADJ[indice][indice] = 0;
		return true;
	}
	return false;
}

bool Grafo::remove_vertice(int indice){
	for (int i = 0; i < tamanho; ++i) {
		matrizADJ[indice][i] = INFINITY;
	}
	for (int j = 0; j < tamanho; ++j) {
		matrizADJ[j][indice] = INFINITY;
	}
	if (vertices[indice] != NULL) {
		vertices[indice]->~Vertice();
		vertices[indice] = NULL;
	}
	return true;
}

int Grafo::adjacentes(int indice)
{
	int adjacencias = 0;
	for (int i = 0; i < tamanho; ++i) {
		if (matrizADJ[indice][i] != INFINITY)
			adjacencias++;
	}
	for (int j = 0; j < tamanho; ++j) {
		if (matrizADJ[j][indice] != INFINITY)
			adjacencias++;
	}
	return adjacencias;
}

bool Grafo::seta_informacoes(int indice, string nome)
{
	vertices[indice]->setNome(nome);
	return true;
}

void Grafo::printaNome() {
	cout << nome << endl;
}

void Grafo::imprime() {
	for (int i = 0; i < tamanho; ++i) {
		cout << "\| ";
		for (int j = 0; j < tamanho; ++j) {
			cout << matrizADJ[i][j] << "\t";
		}
		cout << "\|" << endl;
	}
}

Vertice* Grafo::getVertices(int indice) {
	return this->vertices[indice];
}
