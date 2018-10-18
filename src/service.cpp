#include "service.h"

// Конструктор
Service::Service() { isExit = false; }

// Цикл
void Service::loop() {
  int option = -1;
  std::cout
      << "\nWhat you can do:\n  1) Create matrix\n  2) Print matrix\n  0) "
         "Exit\n\n>>> ";
  std::cin >> option;
  switch (option) {
    case 1:  // Создание матрицы
      createMatrix();
      break;
    case 2:  // Вывод матрицы
      int num;
      std::cout << "Matrix number: ";
      // Получаем номер запрашиваемой матрицы
      std::cin >> num;
      printMatrix(num);
      break;
    case 0:  // Выход из программы
      isExit = true;
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

  // Выбираем что с ней делать
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
      for (int i = 0; i < m && i < n; i++)
        matrix[num]->set(i, i, 1);  // По главной диагонали забиваем 1
      break;
    case 2:  // Нулевая матрица (ничего не делаем, там и так нули)
    default:
      break;
  }
}

// Вывод матрицы
void Service::printMatrix(int num) {
  // Проверяем на существование матрицу
  if (num >= 0 && !(num <= matrix.size() - 1)) {
    std::cout << "Matrix " << num << " not found!\n";
    return;
  }
  Matrix<double>* M = matrix[num];

  // Поиск самого длинного числа
  int maxlenth = 0;
  for (int i = 0; i < M->sizeRows(); i++)
    for (int j = 0; j < M->sizeColumns(); j++) {
      int l = length(M->get(i, j));
      if (l > maxlenth) maxlenth = l;
    }

  for (int i = 0; i < M->sizeRows(); i++) {
    for (int j = 0; j < M->sizeColumns(); j++) {
      int spaces = maxlenth - length(M->get(i, j));
      for (int s = 0; s < spaces; s++) std::cout << " ";
      std::cout << M->get(i, j);
      std::cout << " ";
    }
    std::cout << std::endl;
  }
}

// Длина числа
int Service::length(double number) {
  int maxlenth = 0;
  // Делим элемент до тех пор, пока он не станет равным нулю
  while (number != 0) {
    number /= 10;
    // количество итераций записываем - это и будет длинна
    maxlenth++;
  }
  return maxlenth;
}