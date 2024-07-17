#include "Matriz.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Matriz::Matriz() {
  this->rows = 0;
  this->columns = 0;
}

Matriz::Matriz(int x, int y) {
  this->rows = x;
  this->columns = y;
  m = new double *[rows];
  for (int i = 0; i < rows; i++) {
    m[i] = new double[columns];
    for (int j = 0; j < columns; j++) {
      m[i][j] = 0;
    }
  }
}

// Matriz::~Matriz() {
//   for (int i = 0; i < rows; i++) {
//     delete[] m[i];
//   }
//   delete[] m;
// }

void Matriz::randomizaMatriz() {
  srand(time(0));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      m[i][j] = rand() % 10;
    }
  }
}

void Matriz::imprimeMatriz() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      cout << m[i][j] << ' ';
    }
    cout << '\n';
  }
}

// void Matriz::somaMatrizes(Matriz matriz1, Matriz matriz2) {
//   for (int i = 0; i < rows; i++) {
//     for (int j = 0; j < columns; j++) {
//       this->m[i][j] = matriz1.m[i][j] + matriz2.m[i][j];
//     }
//   }
// }

void Matriz::somaMatrizes(Matriz matriz) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      this->m[i][j] += matriz.m[i][j];
    }
  }
}

void Matriz::multiplicaMatrizes(Matriz matriz1, Matriz matriz2) {
  if (matriz1.columns == matriz2.rows) {
    for (int i = 0; i < matriz1.rows; i++) {
      for (int j = 0; j < matriz2.columns; j++) {
        double aux = 0;
        for (int k = 0; k < matriz1.rows; k++) {
          aux += matriz1.m[i][k] * matriz2.m[k][j];
        }
        this->m[i][j] = aux;
        aux = 0;
      }
    }
  } else {
    cout << "É necessário que o número de colunas de matriz1 seja igual ao "
            "número de linhas de matriz2"
         << endl;
  }
}

void Matriz::liberaMemoria() {
  for (int i = 0; i < this->rows; i++) {
    delete[] m[i];
  }
  delete[] m;
}