#include <iostream>
#include "Vertice.h"
#include "Grafo.h"
#include "Adjacencia.h"

using namespace std;

int main() {
	Grafo * grafo = new Grafo(10);
	
	grafo->imprime();
	
	cout << endl;

	grafo->seta_informacoes(2, "Paulo");
	grafo->seta_informacoes(3, "Claudio");
	grafo->seta_informacoes(4, "Carlos");

	grafo->cria_adjacencia(0, 1, 12);
	grafo->cria_adjacencia(0, 4, 12);
	grafo->cria_adjacencia(2, 0, 12);
	grafo->cria_adjacencia(3, 0, 1);
	grafo->cria_adjacencia(3, 2, 2);
	grafo->cria_adjacencia(3, 4, 3);
	grafo->cria_adjacencia(0, 0, 3);

	grafo->adjacentes(3);
	grafo->imprime();
	cout << endl;	
	grafo->adjacentes(0);	
	cout << endl;
	grafo->remove_adjacencia(0, 1);
	grafo->imprime();	
	cout << endl;
	grafo->adjacentes(0);
	return 0;
}