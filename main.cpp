#include "Matriz.hpp"
#include "redeNeural.hpp"
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {

  cout << "funcionou" << endl;

  int i_nodes = 2, h_nodes = 2, o_nodes = 2;

  redeNeural redeNeural(i_nodes, h_nodes, o_nodes);

  double *inputs = new double[i_nodes];

  for (int i = 0; i < i_nodes; i++) {
    cin >> inputs[i];
  }

  redeNeural.inputsParaEntrada(inputs);

  delete[] inputs;

  redeNeural.Feedfoward();

  /*
  // int x, y;

  // cin >> x;
  // cin >> y;

  cout << "matrizSoma:" << endl;
  // Matriz matrizSoma(x, y);
  Matriz matrizSoma(2, 2);
  matrizSoma.imprimeMatriz();
  cout << '\n';
  sleep(1);

  cout << "matrizMultiplicacao:" << endl;
  // Matriz matrizMultiplicacao(x, y);
  Matriz matrizMultiplicacao(2, 1);
  matrizMultiplicacao.imprimeMatriz();
  cout << '\n';
  sleep(1);

  // cin >> x;
  // cin >> y;
  cout << "matriz1:" << endl;
  // Matriz matriz1(x, y);
  Matriz matriz1(2, 2);
  matriz1.randomizaMatriz();
  matriz1.imprimeMatriz();
  cout << '\n';
  sleep(1);

  // cin >> x;
  // cin >> y;
  cout << "matriz2:" << endl;
  // Matriz matriz2(x, y);
  Matriz matriz2(2, 2);
  matriz2.randomizaMatriz();
  matriz2.imprimeMatriz();
  cout << '\n';
  sleep(1);

  // cin >> x;
  // cin >> y;
  cout << "matriz3:" << endl;
  // Matriz matriz3(x, y);
  Matriz matriz3(2, 1);
  matriz3.randomizaMatriz();
  matriz3.imprimeMatriz();
  cout << '\n';

  cout << "matrizSoma:" << endl;
  matrizSoma.somaMatrizes(matriz1, matriz2);
  matrizSoma.imprimeMatriz();
  cout << '\n';

  cout << "matrizMultiplicacao:" << endl;
  matrizMultiplicacao.multiplicaMatrizes(matriz1, matriz3);
  matrizMultiplicacao.imprimeMatriz();
  cout << '\n';

  matrizSoma.liberaMemoria();
  matrizMultiplicacao.liberaMemoria();
  matriz1.liberaMemoria();
  matriz2.liberaMemoria();
  matriz3.liberaMemoria();
  */

  return 0;
}