#include <stdio.h>
#include "pokelista.h"

// cria uma pokelista, aloca a memória e a retorna
// essa implementação é funcional pelo fato de a memória alocada
// para a célula permanecer na memória mesmo após a finalização da
// função, além do fato de o endereço da célula ser atribuido ao
// ponteiro primeiro, ou seja, a célula não fica perdida na memória
Pokelista pl_init() {
	Pokelista pl;

	pl.primeiro = (Pokecelula*) malloc(sizeof(Pokecelula));
  pl.ultimo = pl.primeiro;
  pl.primeiro->prox = NULL;

	return pl;
}

// insere uma célula ao final da lista
// a complexidade dessa operação de inserção é O(1) devido ao uso do
// ponteiro auxiliar ultimo
// não é necessário verificar se a lista está vazia no momento da inserção
// pelo fato de que a lista sempre possuir ao menos uma célula: a célula cabeça
void pl_insere(Pokelista *pl, Pokemon p) {
	pl->ultimo->prox = (Pokecelula*) malloc(sizeof(Pokecelula));

  pl->ultimo = pl->ultimo->prox;
  pl->ultimo->pokemon = p;
  pl->ultimo->prox = NULL;
}

// remove o primeiro elemento da lista
// a operação de remoção transforma o primeiro elemento real (o primeiro.prox)
// em uma nova célula cabeça, e libera a célula cabeça antiga
void pl_remove(Pokelista *pl) {
	if (pl_vazia(pl)) {
		return;
	}

  Pokecelula *aux;
  
  aux = pl->primeiro;                   
  pl->primeiro = pl->primeiro->prox;
  free(aux);                                 
}

// percorre a lista em busca do pokemon com o id desejado
// retorna NULL caso não encontre o elemento
Pokecelula* pl_busca(Pokelista *pl, int id) {
	Pokecelula *aux = pl->primeiro->prox; 
    
	while (aux != NULL) {
		if (aux->pokemon.id == id) {
			return aux; 
		}

		aux = aux->prox;
	}

	return NULL; 
}

// percorre a lista e imprime os pokemons
void pl_imprime(Pokelista *pl, FILE *outputFile) {
	Pokecelula *aux = pl->primeiro->prox;

	while (aux != NULL) {
		fprintf(outputFile, "%03d %s\n", p_get_numPokedex(&aux->pokemon), p_get_nome(&aux->pokemon));
		aux = aux->prox;
	}
}

// em listas encadeadas com cabeça, a lista estar vazia
// significa que os ponteiros primeiro e último apontam para
// a mesma célula (a célula cabeça)
int pl_vazia(Pokelista *pl) {
	return (pl->primeiro == pl->ultimo);
}

// percorre a lista inteira e libera todas as células alocadas,
// inclusive a célula cabeça, ao final os ponteiros são redefinidos
// evitando ponteiros soltos no código
void pl_libera(Pokelista *pl) {
	Pokecelula *aux = pl->primeiro;
    
	while (aux != NULL) {
		Pokecelula *prox = aux->prox;
		free(aux);
		aux = prox;
	}
    
	pl->primeiro = NULL;
	pl->ultimo = NULL;
}

// percorre toda lista e retorna o tamanho
int pl_tamanho(Pokelista *pl) {
	int tam = 0;
	Pokecelula *aux = pl->primeiro->prox;
	
	while (aux != NULL) {
		tam++;
		aux = aux->prox;
	}

	return tam;
}

// retorna o primeiro pokemon presente na lista
Pokemon pl_get_p(Pokelista *pl) {
	if (!pl_vazia(pl)) {
		return pl->primeiro->prox->pokemon;
	}
	
	return p_init(ZERO, ZERO, VAZIO, VAZIO, c_init(ORIGEM, ORIGEM));	
}