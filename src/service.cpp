#include "service.h"

// Конструктор
Service::Service() { isExit = false; }

// Цикл
void Service::loop() {
  int option = -1;
  std::cout << "What you can do:\n  1) Create matrix\n\n>>> ";
  std::cin >> option;
  switch (option) {
    case 1:
      createMatrix();
      break;
    default:
      break;
  }
}

// Создание матрицы
void Service::createMatrix() {
  int m = 0, n = 0;         // Размеры
  int num = matrix.size();  // Номер матрицы

  std::cout << "\nMatrix " << num << "\nRows (m): ";
  std::cin >> m;  // Ввод количества строк
  std::cout << "Columns (n): ";
  std::cin >> n;  // Ввод количества столбцов

  // Создаем матрицу
  Matrix<double>* M = new Matrix<double>(m, n);
  matrix.push_back(M);

  // Выбирвем что с ней делать
  int option = -1;
  std::cout << "Matrix created. What you can do:\n  1) Manual input\n  2) Zero "
               "matrix\n  3) Unit matrix\n\n>>> ";
  std::cin >> option;
  switch (option) {
    case 1:  // Ручной ввод элементов
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
          std::cout << "[" << i + 1 << "][" << j + 1 << "]: ";
          double value;
          std::cin >> value;
          matrix[num]->set(i, j, value);
        }
      break;
    case 3:  // Создание единичной матрицы
      break;
    case 2:  // Нулевая матрица (ничего не делаем, там и так нули)
    default:
      break;
  }
}