//  Сервис
//   Непосредственно занимается интерфейсом для
//   пользователя, создает и хранит матрицы, выводит
//   их, представляет командную строку.

#pragma once
#include <iostream>
#include <vector>
#include "matrix.h"

class Service {
 private:
  // Массив матриц
  std::vector<Matrix<double>*> matrix;
  
  // Создание матрицы
  void createMatrix();

 public:
  // Для выхода и завершения программы
  bool isExit;

  // Конструктор
  Service();
  // Цикл
  void loop();
};