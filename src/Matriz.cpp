#include "Matriz.hpp"
#include <iostream>
#include <random>

using namespace std;

Matriz::Matriz() {
  this->rows = 0;
  this->columns = 0;
  this->m = nullptr;
}

Matriz::Matriz(int x, int y) {
  this->rows = x;
  this->columns = y;
  this->m = nullptr;

  this->m = new double *[rows];

  for (int i = 0; i < rows; i++) {
    m[i] = new double[columns];

    for (int j = 0; j < columns; j++) {
      m[i][j] = 0;
    }
  }
}

Matriz::Matriz(const Matriz& copy) {
  this->rows = copy.rows;
  this->columns = copy.columns;

  if (copy.m == nullptr) {
    this->m = nullptr;
    return;
  }

  this->m = new double *[rows];

  for (int i = 0; i < rows; i++) {
    this->m[i] = new double[columns];

    for (int j = 0; j < columns; j++) {
      this->m[i][j] = copy.m[i][j];
    }
  }
}

Matriz& Matriz::operator=(const Matriz& copy) {
  if (this != &copy) {
    return *this;
  }

  if (this->m != nullptr) {
    for (int i = 0; i < this->rows; i++) {
      delete[] this->m[i];
    }

    delete[] this->m;
  }

  this->rows = copy.rows;
  this->columns = copy.columns;

  if (copy.m == nullptr) {
    this->m = nullptr;
    return *this;
  }

  this->m = new double *[rows];

  for (int i = 0; i < rows; i++) {
    this->m[i] = new double[columns];

    for (int j = 0; j < columns; j++) {
      this->m[i][j] = copy.m[i][j];
    }
  }

  return *this;
}

Matriz::~Matriz() {
  // cout << "Entrei no destrutor." << endl;

  if (this->m != nullptr) {
    for (int i = 0; i < rows; i++) {
      delete[] m[i];
    }
  }

  delete[] m;
}

void Matriz::randomizaMatriz() {
  // cout << "Entrei no randomizaMatriz." << endl;

  random_device rd;
  mt19937 mt(rd());
  uniform_real_distribution<> dist(-1.0, 1.0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      m[i][j] = dist(mt);
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

void Matriz::somaMatrizes(const Matriz& matriz) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      this->m[i][j] += matriz.m[i][j];
    }
  }
}

Matriz Matriz::multiplicaMatrizes(const Matriz& matriz1, const Matriz& matriz2) {
  Matriz auxMatrix(matriz1.rows, matriz2.columns);

  if (matriz1.columns == matriz2.rows) {

    for (int i = 0; i < matriz1.rows; i++) {
      for (int j = 0; j < matriz2.columns; j++) {

        double aux = 0;

        for (int k = 0; k < matriz1.columns; k++) {
          aux += matriz1.m[i][k] * matriz2.m[k][j];
        }

        auxMatrix.m[i][j] = aux;
        aux = 0;
      }
    }
  } else {
    cout << "É necessário que o número de colunas de matriz1 seja igual ao "
            "número de linhas de matriz2"
         << endl;
  }

  return auxMatrix;
}