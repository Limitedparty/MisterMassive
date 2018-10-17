//  Описание размера
//  Впринципе все просто - описывает размер матрицы.

#pragma once
#include "position.h"

class Size : private Position {
 private:
  // m - количество строк
  // n - количество столбцов
  int m, n;

 public:
  // Конструктор
  Size(int rows, int columns) {
    m = rows;
    n = columns;
  }
  // Строки
  int rows() { return n; }
  // Столбцы
  int columns() { return m; }

  // Способ изменить размерность отсутствует
  // (он и не нужен, это глупо)
};