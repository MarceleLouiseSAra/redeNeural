#include "redeNeural.hpp"
#include "Matriz.hpp"
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

redeNeural::redeNeural(int i_nodes, int h_nodes, int o_nodes)
  : i_nodes(i_nodes), 
    h_nodes(h_nodes), 
    o_nodes(o_nodes),
    learning_rate(0.1),
    camadaEntrada(i_nodes, 1),   // <--- Constrói direto no tamanho certo!
    camadaOculta(h_nodes, 1),
    camadaSaida(o_nodes, 1),
    bias_ih(h_nodes, 1),
    bias_ho(o_nodes, 1),
    weigths_ih(h_nodes, i_nodes),
    weigths_ho(o_nodes, h_nodes) {
  
  this->bias_ih.randomizaMatriz();
  this->bias_ho.randomizaMatriz();
  this->weigths_ih.randomizaMatriz();
  this->weigths_ho.randomizaMatriz();
};

void redeNeural::inputsParaEntrada(int *inputs) {
  // cout << "Entrei no inputsParaEntrada." << endl;

  for (int i = 0; i < this->i_nodes; i++) {
    this->camadaEntrada.m[i][0] = inputs[i];
  }
};

double redeNeural::Sigmoid(double x) { 
  return 1 / (1 + exp(-x)); 
};

double redeNeural::derivadaDaSigmoid(double x) { 
  return x * (1-x);
};

void redeNeural::Feedfoward() {

  // cout << "camadaEntrada:" << endl;
  // this->camadaEntrada.imprimeMatriz();
  // cout << "bias_ih:" << endl;
  // this->bias_ih.imprimeMatriz();
  // cout << "weigths_ih:" << endl;
  // this->weigths_ih.imprimeMatriz();
  // cout << "camadaOculta:" << endl;
  // this->camadaOculta.imprimeMatriz();

  this->camadaOculta = Matriz::multiplicaMatrizes(this->weigths_ih, this->camadaEntrada);
  // cout << "camadaOculta:" << endl;
  // this->camadaOculta.imprimeMatriz();

  this->camadaOculta.somaMatrizes(this->bias_ih);
  // cout << "camadaOculta:" << endl;
  // this->camadaOculta.imprimeMatriz();

  for (int i = 0; i < this->h_nodes; i++) {
    this->camadaOculta.m[i][0] = Sigmoid(this->camadaOculta.m[i][0]);
  }

  // cout << "camadaOculta:" << endl;
  // this->camadaOculta.imprimeMatriz();
  // cout << "bias_ho:" << endl;
  // this->bias_ho.imprimeMatriz();
  // cout << "weigths_ho:" << endl;
  // this->weigths_ho.imprimeMatriz();
  // cout << "camadaSaida:" << endl;
  // this->camadaSaida.imprimeMatriz();

  this->camadaSaida = Matriz::multiplicaMatrizes(this->weigths_ho, this->camadaOculta);
  // cout << "camadaSaida: " << endl;
  // this->camadaSaida.imprimeMatriz();
  
  this->camadaSaida.somaMatrizes(this->bias_ho);
  // cout << "camadaSaida: " << endl;
  // this->camadaSaida.imprimeMatriz();

  for (int i = 0; i < this->o_nodes; i++) {
    this->camadaSaida.m[i][0] = Sigmoid(this->camadaSaida.m[i][0]);
  }

  // cout << "camadaSaida: " << endl;
  // this->camadaSaida.imprimeMatriz();
};

void redeNeural::Backpropagation(const Matriz& respostaCerta) {

  // Saída -> Oculta:
  // cout << "this->camadaSaida.imprimeMatriz(): " << endl;
  // this->camadaSaida.imprimeMatriz();

  Matriz erroDaSaida = Matriz::subtraiMatrizes(respostaCerta, this->camadaSaida);
  // cout << "erroDaSaida.imprimeMatriz(): " << endl; 
  // erroDaSaida.imprimeMatriz();

  Matriz derivadaDaSaida = this->camadaSaida;

  for (int i = 0; i < this->o_nodes; i++) {
    derivadaDaSaida.m[i][0] = derivadaDaSigmoid(derivadaDaSaida.m[i][0]);
  }

  // cout << "derivadaDaSaida: " << endl;
  // derivadaDaSaida.imprimeMatriz();

  Matriz gradiente_da_oculta = Matriz::hadamard(erroDaSaida, derivadaDaSaida);
  // cout << "gradiente da camada oculta: " << endl;
  // gradiente_da_oculta.imprimeMatriz();

  gradiente_da_oculta.multiplicaMatrizPorEscalar(learning_rate);
  // cout << "gradiente da camada oculta multiplicada pelo learning rate: " << endl;
  // gradiente_da_oculta.imprimeMatriz();

  this->bias_ho.somaMatrizes(gradiente_da_oculta);
  // cout << "bias_ih: " << endl;
  // bias_ih.imprimeMatriz();

  Matriz camadaOcultaTransposta = Matriz::transpoeMatriz(this->camadaOculta);

  Matriz weigths_ho_deltas = Matriz::multiplicaMatrizes(gradiente_da_oculta, camadaOcultaTransposta);
  // cout << "Correções dos pesos entre as camadas oculta e de saída: " << endl;
  // weigths_ho_deltas.imprimeMatriz();

  // cout << "weigths_ho: " << endl;
  // this->weigths_ho.imprimeMatriz();

  this->weigths_ho.somaMatrizes(weigths_ho_deltas);

  // cout << "weigths_ho corrigidos: " << endl;
  // this->weigths_ho.imprimeMatriz();

  //Oculta -> Entrada:
  
  Matriz weigths_ho_transposta = Matriz::transpoeMatriz(this->weigths_ho);
  Matriz erroDaOculta = Matriz::multiplicaMatrizes(weigths_ho_transposta, erroDaSaida);
  // cout << "erroDaOculta: " << endl;
  // erroDaOculta.imprimeMatriz();

  Matriz derivadaDaOculta = this->camadaOculta;

  for (int i = 0; i < this->o_nodes; i++) {
    derivadaDaOculta.m[i][0] = derivadaDaSigmoid(derivadaDaOculta.m[i][0]);
  }

  // cout << "derivadaDaOculta: " << endl;
  // derivadaDaOculta.imprimeMatriz();

  Matriz gradiente_da_entrada = Matriz::hadamard(erroDaOculta, derivadaDaOculta);

  // cout << "gradiente da camada de entrada: " << endl;
  // gradiente_da_entrada.imprimeMatriz();

  gradiente_da_entrada.multiplicaMatrizPorEscalar(learning_rate);
  // cout << "gradiente da camada de entrada multiplicada pelo learning rate: " << endl;
  // gradiente_da_entrada.imprimeMatriz();

  this->bias_ih.somaMatrizes(gradiente_da_entrada);
  // cout << "bias_ih: " << endl;
  // bias_ih.imprimeMatriz();

  Matriz camadaEntradaTransposta = Matriz::transpoeMatriz(this->camadaEntrada);

  Matriz weigths_ih_deltas = Matriz::multiplicaMatrizes(gradiente_da_entrada, camadaEntradaTransposta);

  // cout << "Correções dos pesos entre as camadas de entrada e oculta: " << endl;
  // weigths_ih_deltas.imprimeMatriz();

  // cout << "weigths_ih: " << endl;
  // this->weigths_ih.imprimeMatriz();

  this->weigths_ih.somaMatrizes(weigths_ih_deltas);

  // cout << "weigths_ih corrigidos: " << endl;
  // this->weigths_ih.imprimeMatriz();

};

void redeNeural::train(const Matriz& respostaCerta) { 
  this->Feedfoward();

  this->Backpropagation(respostaCerta);
};

void redeNeural::predict() {
  this->Feedfoward();
};