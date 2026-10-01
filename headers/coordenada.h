#ifndef COORDENADA_H
#define COORDENADA_H

typedef struct {
  float x;
  float y;
} Coordenada;

// função de inicialização da coordenada
Coordenada c_init(float x, float y);

// calculo da distância
float c_distancia(Coordenada c1, Coordenada c2);

// getters
float c_get_localizacao_x(Coordenada c);
float c_get_localizacao_y(Coordenada c);

#endif