//  Описание класса матрицы
//  Да, программа имеет в названии слово "массив",
//  но по факту речь, естественно, идет о матрицах

#pragma once

template<typename T>
class Matrix {
 private:
  // Размер матрицы
  // m - количество строк
  // n - количество столбцов
  int m, n;
  // Элементы
  T** elements;

 public:
   // Конструктор
   Matrix(int rows, int columns);
};


// Конструктор
template<typename T>
Matrix<T>::Matrix(int rows, int columns) {
  // Записываем строки/столбцы
  m = rows;
  n = columns;
  // Выделяем место для элементов
  elements = new T*[m];
  for (int j = 0; j < n; j++)
    // Создаем элементы
    elements[j] = new T(0);
}