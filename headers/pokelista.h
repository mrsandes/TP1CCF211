#ifndef POKELISTA_H
#define POKELISTA_H

#include <stdlib.h>
#include "pokemon.h"

// estrutura de dados auaxiliar
typedef struct Pokecelula {
  Pokemon pokemon;               
  struct Pokecelula *prox;    
} Pokecelula;

// implementação da lista encadeada com ponteiro auxiliar ultimo
// o ponteiro auxiliar se fez util pelo fato de as inserções na 
// lista serem apenas ao final, aumentando o desempenho do programa
typedef struct {
  Pokecelula *primeiro;      
  Pokecelula *ultimo;        
} Pokelista;

// inicializa a lista criando a celula cabeça
Pokelista pl_init();

// insere um novo elemento ao final da lista
// faz uso do ponteiro ultimo
void pl_insere(Pokelista *pl, Pokemon p);

// remove o primeiro elemento da lista
// a implementação de uma função de remoção a partir do id ou outro
// parâmetro se fez desnecessária devido ao fluxo de execução linear
// de captura dos pokemons
void pl_remove(Pokelista *pl);

// faz a busca linear do pokemon pela lista
Pokecelula* pl_busca(Pokelista *pl, int id);

// imprime a lista de pokemons da lista desejada
void pl_imprime(Pokelista *pl, FILE *outputFile);

// retorna 1 quando a lista esta vazia e 0 quando possui 1 ou mais elementos
int pl_vazia(Pokelista *pl);

// libera a memória alocada durante a inserção dos pokemons
void pl_libera(Pokelista *pl);

// retorna o tamanho da lista encadeada
int pl_tamanho(Pokelista *pl);

// retorna o primeiro pokemon da lista (ignora a celula cabeça)
Pokemon pl_get_p(Pokelista *pl);

#endif