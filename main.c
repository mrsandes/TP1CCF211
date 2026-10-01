// importamos no .h apenas as bibliotecas que aparecem nos 
// cabeçalhos das funções (parâmetros e tipos - FILE por exemplo) 
// o que é usado apenas na implementação das funções é importado apenas no .c
#include <time.h>     
#include <string.h>   
#include <stdlib.h>
#include "controleDaMissao.h"

int main(int argc, char const *argv[]) {
  // garante a funcionalidade da aleatoriedade
  srand(time(NULL)); 

  // 1 etapa - inicialização
  CentroDePesquisa cp = cm_init();
  char inputFileName[MAX_TAM_STRING];

  // verificação dos argumentos
  if (argc > 1) {
    strcpy(inputFileName, argv[1]);
  } 
  
  else {
    cm_input(inputFileName);
  }
   
  // 2 etapa - inserção dos registros
  cm_registro(&cp, inputFileName);
  
  // 3 etapa - captura e retorno
  cm_captura(&cp);  
  cm_retorno(&cp);
  
  // 4 etapa - escrita do relatório
  cm_imprime(&cp);

  // 5 etapa - liberação da memória utilizada
  cm_libera(&cp);
   
  return SUCESSO;
}