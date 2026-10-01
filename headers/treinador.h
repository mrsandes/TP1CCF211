#ifndef TREINADOR_H
#define TREINADOR_H

#include "utils.h"
#include "pokelista.h"

typedef struct {
  int id;
  char nome[MAX_TAM_STRING];
  Coordenada localizacao;
  Pokelista pokelista;
  int numPokebolas;
} Treinador;

// inicializa o treinador
Treinador t_init(int id, char nome[], int numPokebolas);

// move o treinador para um localização
void t_move(Treinador *t, Coordenada newLocalizacao);

// captura o pokemon e remove uma pokebola do treinador
void t_captura(Treinador *t, Pokemon p);

// retira o primeiro pokemon da lista do treinador
void t_retira_pokemon(Treinador *t);

// imprime as informações do treinador
void t_imprime(Treinador *t);

// getters
int t_get_id(Treinador *t);
// const é usado para impedir alterações no endereço 
// retornado fora do escopo da estrutura
const char* t_get_nome(Treinador *t);
Coordenada t_get_localizacao(Treinador *t);
Pokelista* t_get_pl(Treinador *t);
int t_get_numPokebolas(Treinador *t);

// setters
void t_set_id(Treinador *t, int id);
void t_set_nome(Treinador *t, char nome[]);
void t_set_localizacao(Treinador *t, Coordenada l);
void t_set_pl(Treinador *t, Pokelista pl);
void t_set_numPokebolas(Treinador *t, int numPokebolas);

#endif