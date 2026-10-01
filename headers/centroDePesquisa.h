#ifndef CENTRODEPESQUISA_H
#define CENTRODEPESQUISA_H

#include <stdio.h>
#include "utils.h"
#include "treinador.h"

typedef struct {
  Treinador treinadores[NUM_TREINADORES];
  Pokelista pl_fugitivos;
  Pokelista pl_recuperados;
  Coordenada localizacao;
} CentroDePesquisa;

// inicialização do centro de pesquisa
CentroDePesquisa cp_init();

// inserção dos registros 
void cp_insere_registros(CentroDePesquisa *cp, FILE* inputFile);

// remoção do primeiro pokemon fugitivo
void cp_remove_fugitivo(CentroDePesquisa *cp);

// impressão dos pokemons fugitivos
void cp_imprime_fugitivos(CentroDePesquisa *cp);

// recebimento dos pokemons
void cp_recebe_pokemons(CentroDePesquisa *cp, int id);

// recarrega as pokebolas do treinador desejado
int cp_recarrega_pokebolas(CentroDePesquisa *cp, int id);

// inicializa o treinador uma única vez
void cp_init_treinador(CentroDePesquisa *cp, Treinador t, int id);

// getters
Treinador* cp_get_treinador(CentroDePesquisa *cp, int id);
Pokelista* cp_get_pl_fugitivos(CentroDePesquisa *cp);
Pokelista* cp_get_pl_recuperados(CentroDePesquisa *cp);
Coordenada cp_get_localizacao(CentroDePesquisa *cp);

// setters
void cp_set_treinador(CentroDePesquisa *cp, char nome[], int numPokebolas, int id);
void cp_set_pl_fugitivos(CentroDePesquisa *cp, Pokelista pl);
void cp_set_pl_recuperados(CentroDePesquisa *cp, Pokelista pl);
void cp_set_localizacao(CentroDePesquisa *cp, Coordenada l);

#endif