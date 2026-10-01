#include <math.h>
#include "coordenada.h"

// inicializa uma coordenada e retorna a coordenada inicializada
Coordenada c_init(float x, float y) {
  Coordenada c;

  c.x = x;
  c.y = y;

  return c;
}

// calcula a distancia entre os dois pontos
float c_distancia(Coordenada c1, Coordenada c2) {
  float dx = c1.x - c2.x;
  float dy = c1.y - c2.y;
  
  return sqrt(dx * dx + dy * dy);
}

float c_get_localizacao_x(Coordenada c) {
  return c.x;
}

float c_get_localizacao_y(Coordenada c) {
  return c.y;
}