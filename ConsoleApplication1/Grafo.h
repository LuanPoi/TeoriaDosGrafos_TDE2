#pragma once
#include "Vertice.h"
#include "Adjacencia.h"
#include <vector>
#include <list>

using namespace std;

class Grafo
{
private:
	list<Adjacencia> * lista;
	Vertice *vertices;

	int tamanho;
	string nome;
	Grafo();

public:
	Grafo(int tamanho);
	~Grafo();
	bool cria_adjacencia(int de,int para,float peso); // cria uma adjacência entre i e j com custo P no grafo G;
	bool remove_adjacencia(int de, int para); // remove a adjacência entre i e j no grafo G;
	list<Adjacencia> adjacentes(int indice); // atualiza a informação do nó i com o valor V (que deve ser uma string) no grafo G;
	bool seta_informacoes(int indice, string nome); // atualiza a informação do nó i com o valor V (que deve ser uma string) no grafo G
	void imprime();
	void printaNome(int indice);
	Vertice* getVertices(int indice);
};

