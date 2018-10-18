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
  // Вывод матрицы
  void printMatrix(int num);
  // Длина числа
  int length(double number);

 public:
  // Для выхода и завершения программы
  bool isExit;

  // Конструктор
  Service();
  // Цикл
  void loop();
};