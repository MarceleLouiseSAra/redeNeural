#include "Matriz.hpp"
#include "redeNeural.hpp"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <random>

using namespace std;

map<int, vector<int>> XORProblemInputsMap = {
  {0, {0, 0}},
  {1, {0, 1}},
  {2, {1, 0}},
  {3, {1, 1}},
};

map<int, int> XORProblemRightAnswers = {
  {0, 0},
  {1, 1},
  {2, 1},
  {3, 0},
};

int main() {

  cout << "It's running!" << endl;

  int i_nodes = 2, h_nodes = 2, o_nodes = 2, exercicio = 0;

  redeNeural redeNeural(i_nodes, h_nodes, o_nodes);

  int *inputs = new int[i_nodes];

  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> dist(0, 3);

  Matriz respostaCerta(o_nodes, 1);
  
  for (int i = 0; i < 10000; i++) {

    exercicio = dist(mt);

    // cout << "Exercicio: " << exercicio << endl;

    for (int i = 0; i < i_nodes; i++) {
      inputs[i] = XORProblemInputsMap[exercicio][i];
    }

    // cout << "Resposta do exercício: " << endl;
    // cout << XORProblemRightAnswers[exercicio] << endl;

    int resultadoEsperado = XORProblemRightAnswers[exercicio];

    if (resultadoEsperado == 0) { // se a resposta correta for zero, a linha 0 deve ter a maior probabilidade
        respostaCerta.m[0][0] = 1.0;
        respostaCerta.m[1][0] = 0.0;

    } else { // se a resposta correta for um, a linha 1 deve ter a maior probabilidade
        respostaCerta.m[0][0] = 0.0;
        respostaCerta.m[1][0] = 1.0;
    }

    redeNeural.inputsParaEntrada(inputs);

    redeNeural.train(respostaCerta);
  }

  for (int i = 0; i < 10; i++) {
    exercicio = dist(mt);

    for (int i = 0; i < i_nodes; i++) {
      inputs[i] = XORProblemInputsMap[exercicio][i];
    }

    redeNeural.inputsParaEntrada(inputs);

    redeNeural.predict();

    // cout << "Matriz respostaCerta: " << endl;
    // respostaCerta.imprimeMatriz();

    cout << "Resposta da rede: " << endl;
    redeNeural.camadaSaida.imprimeMatriz();

    cout << "Resposta certa: " << endl;
    cout << XORProblemRightAnswers[exercicio] << endl;

    cout << endl;
  }
  
  delete[] inputs;
  
  return 0;
}