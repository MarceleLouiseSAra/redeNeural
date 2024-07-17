#ifndef Matriz_H
#define Matriz_H
#include <iostream>

using namespace std;

class Matriz {
  public:
  int rows;
  int columns;
  double** m;

  Matriz();

  Matriz(int x, int y);

  //~Matriz();

  void randomizaMatriz();

  void imprimeMatriz();
  
  //void somaMatrizes(Matriz matriz1, Matriz matriz2);

  void somaMatrizes(Matriz matriz);
  
  void multiplicaMatrizes(Matriz matriz1, Matriz matriz2);

  void liberaMemoria();
  
};


#endif