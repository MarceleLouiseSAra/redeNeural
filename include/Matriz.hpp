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

  Matriz(const Matriz& copy);

  Matriz& operator=(const Matriz& copy);

  Matriz(int x, int y);

  ~Matriz();

  void randomizaMatriz();

  void imprimeMatriz();
  
  void somaMatrizes(const Matriz& matriz);
  
  static Matriz multiplicaMatrizes(const Matriz& matriz1, const Matriz& matriz2);

  static Matriz hadamard(const Matriz& matriz1, const Matriz& matriz2);

  void multiplicaMatrizPorEscalar(double escalar);

  static Matriz transpoeMatriz(const Matriz& matriz);

  static Matriz subtraiMatrizes(const Matriz& matriz1, const Matriz& matriz2);
  
};


#endif