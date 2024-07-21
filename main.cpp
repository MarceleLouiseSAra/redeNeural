#include "Matriz.hpp"
#include "redeNeural.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {

  cout << "It's running!" << endl;

  int i_nodes = 2, h_nodes = 2, o_nodes = 2;

  redeNeural redeNeural(i_nodes, h_nodes, o_nodes);

  double *inputs = new double[i_nodes];

  for (int i = 0; i < i_nodes; i++) {
    cin >> inputs[i];
  }

  redeNeural.inputsParaEntrada(inputs);

  delete[] inputs;

  redeNeural.Feedfoward();

  return 0;
}