#ifndef POKEMON_H
#define POKEMON_H

#include "utils.h"
#include "coordenada.h"

typedef struct {
  int id;
  int numPokedex;
  char nome[MAX_TAM_STRING];
  char tipo[MAX_TAM_STRING];
  Coordenada localizacao;
} Pokemon;

// função de inicialização
Pokemon p_init(int id, int numPokedex, char nome[], char tipo[], Coordenada localizacao);

// função de impressão
void p_imprime(Pokemon *p);

// getters
int p_get_id(Pokemon *p);
int p_get_numPokedex(Pokemon *p);
// const é usado para impedir alterações no endereço 
// retornado fora do escopo da estrutura
const char* p_get_nome(Pokemon *p);
const char* p_get_tipo(Pokemon *p);
Coordenada p_get_localizacao(Pokemon *p);

// setters
void p_set_id(Pokemon *p, int id);
void p_set_numPokedex(Pokemon *p, int numPokedex);
void p_set_nome(Pokemon *p, char nome[]);
void p_set_tipo(Pokemon *p, char tipo[]);
void p_set_localizacao(Pokemon *p, Coordenada l);

#endif