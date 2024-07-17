#include "redeNeural.hpp"
#include "Matriz.hpp"
#include <iostream>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

redeNeural::redeNeural(int i_nodes, int h_nodes, int o_nodes) {
  this->i_nodes = i_nodes;
  this->h_nodes = h_nodes;
  this->o_nodes = o_nodes;

  this->learning_rate = 0.1;

  this->camadaEntrada = Matriz(this->i_nodes, 1);
  this->camadaOculta = Matriz(this->h_nodes, 1);
  this->camadaSaida = Matriz(this->o_nodes, 1);

  this->weigths_ih = Matriz(this->h_nodes, this->i_nodes);
  this->weigths_ih.randomizaMatriz();

  this->weigths_ho = Matriz(this->o_nodes, this->h_nodes);
  sleep(1);
  this->weigths_ho.randomizaMatriz();

  this->bias_ih = Matriz(this->h_nodes, 1);
  sleep(1);
  this->bias_ih.randomizaMatriz();

  this->bias_ho = Matriz(this->o_nodes, 1);
  sleep(1);
  this->bias_ho.randomizaMatriz();
}

void redeNeural::inputsParaEntrada(double *inputs) {
  for (int i = 0; i < this->i_nodes; i++) {
    this->camadaEntrada.m[i][0] = inputs[i];
  }
}

double redeNeural::Sigmoid(double x) { return 1 / (1 + exp(-x)); }

void redeNeural::Feedfoward() {

  cout << '\n';

  cout << "camadaEntrada:" << endl;
  this->camadaEntrada.imprimeMatriz();
  cout << '\n';

  cout << "bias_ih:" << endl;
  this->bias_ih.imprimeMatriz();
  cout << '\n';

  cout << "weigths_ih:" << endl;
  this->weigths_ih.imprimeMatriz();
  cout << '\n';

  cout << "camadaOculta:" << endl;
  this->camadaOculta.imprimeMatriz();
  cout << '\n';

  cout << "camadaOculta:multiplicaMatrizes():" << endl;
  this->camadaOculta.multiplicaMatrizes(this->weigths_ih, this->camadaEntrada);
  this->camadaOculta.imprimeMatriz();
  cout << '\n';

  cout << "camadaOculta.somaMatrizes():" << endl;
  this->camadaOculta.somaMatrizes(this->bias_ih);
  this->camadaOculta.imprimeMatriz();
  cout << '\n';

  for (int i = 0; i < this->h_nodes; i++) {
    this->camadaOculta.m[i][0] = Sigmoid(this->camadaOculta.m[i][0]);
  }

  cout << "Sigmoid(this->camadaOculta):" << endl;
  this->camadaOculta.imprimeMatriz();
  cout << '\n';

  cout << "bias_ho:" << endl;
  this->bias_ho.imprimeMatriz();
  cout << '\n';

  cout << "weigths_ho:" << endl;
  this->weigths_ho.imprimeMatriz();
  cout << '\n';

  cout << "camadaSaida:" << endl;
  this->camadaSaida.imprimeMatriz();
  cout << '\n';

  cout << "camadaSaida.multiplicaMatrizes():" << endl;
  this->camadaSaida.multiplicaMatrizes(this->weigths_ho, this->camadaOculta);
  this->camadaSaida.imprimeMatriz();
  cout << '\n';

  cout << "camadaSaida.somaMatrizes():" << endl;
  this->camadaSaida.somaMatrizes(this->bias_ho);
  this->camadaSaida.imprimeMatriz();
  cout << '\n';

  for (int i = 0; i < this->o_nodes; i++) {
    this->camadaSaida.m[i][0] = Sigmoid(this->camadaSaida.m[i][0]);
  }

  cout << "Sigmoide(this->camadaSaida):" << endl;
  this->camadaSaida.imprimeMatriz();
  cout << '\n';
}

void redeNeural::train() { cout << "tchubirau" << endl; }

// cout << "aux:" << endl;
// Matriz aux(this->h_nodes, 1);
// aux.imprimeMatriz();
// cout << '\n';

// cout << "aux:" << endl;
// aux.multiplicaMatrizes(this->weigths_ih, this->camadaEntrada);
// aux.imprimeMatriz();
// cout << '\n';