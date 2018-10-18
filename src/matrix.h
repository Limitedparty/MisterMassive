//  Матрица
//   Обычная математическая прямоугольная таблица цифр,
//   описание, операции.
//	  ___________________________
//	 | \  c  т  о  л  б  ц  ы (m)|
//	 | с \—————————————————————— |
//	 | т |   x  x  x  x  x  x    |
//	 | р |   x  x  x  x  x  x    |
//	 | о |   x  x  x  x  x  x    |
//	 | к |   x  x  x  x  x  x    |
//	 | и |   x  x  x  x  x  x    |
//   |(n)|                       |
//	  ———————————————————————————

#pragma once

template <typename T>
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

  // Получение количества строк
  int sizeRows() { return m; }
  // Получение количества столбцов
  int sizeColumns() { return n; }
  // Получение элемента
  T get(int row, int column) { return elements[row][column]; }
  // Установка значения элемента
  void set(int row, int column, T value);
};

// Конструктор
template <typename T>
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

// Установка значения элемента
template <typename T>
void Matrix<T>::set(int row, int column, T value) {
  elements[row][column] = value;
}