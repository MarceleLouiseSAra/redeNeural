#ifndef redeNeural_H
#define redeNeural_H
#include "Matriz.hpp"
#include <iostream>

using namespace std;

class redeNeural {
  public:
  int i_nodes;
  int h_nodes;
  int o_nodes;

  double learning_rate;

  Matriz camadaEntrada;
  Matriz camadaOculta;
  Matriz camadaSaida;

  Matriz bias_ih;
  Matriz bias_ho;

  Matriz weigths_ih;
  Matriz weigths_ho;

  redeNeural(int i_nodes, int h_nodes, int o_nodes);

  void inputsParaEntrada(double *inputs);

  double Sigmoid(double x);

  void Feedfoward();

  void train();

};

#endif