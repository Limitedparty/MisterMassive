//  Сервис
//   Непосредственно занимается интерфейсом для
//   пользователя, создает и хранит матрицы, выводит
//   их, представляет командную строку.

#pragma once
#include <vector>
#include "matrix.h"

class Service {
 private:
  // Массив матриц
  std::vector<Matrix<double>*> matrix;

 public:
  // Для выхода и завершения программы
  bool isExit;

  // Конструктор
  Service();

  // Цикл
  void Loop();
};