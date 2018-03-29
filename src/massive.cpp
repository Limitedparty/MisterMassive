#include "massive.h"

Massive::Massive(Size &size) {
  // Указываем размер
  size_ = size;

  // Выделяем память массиву
  massive_ = new double *[size.getX()];
  for (int i = 0; i < size.getX(); i++) {
    massive_[i] = new double[size.getY()];
  }
}

// Установка значения элемента
void Massive::set(Position &position, double var) {
  massive_[position.getX()][position.getY()] = var;
}

// Получение значения элемента
double Massive::get(Position &position) {
  return massive_[position.getX()][position.getY()];
}

// Получение размера массива
Size *Massive::getSize() { return &size_; }

// Вывод массива в консоль
void Massive::print() {
  std::cout << std::endl;
  for (int i = 0; i < size_.getX(); i++) {
    for (int j = 0; j < size_.getY(); j++) {
      std::cout << massive_[i][j] << "   ";
    }
    std::cout << std::endl;
  }
}

/*  Операции с массивом  */

// Сложение двух массивов
//  У складываемых массивов размерность должна быть одинаковой.
//  Сумма двух массивов - это сумма соответствующих значений массива А и
//  массива B, соответственно записанная в массив С.
//
//  Пример:
//  |1 2 3|     |1 1 1|     |2 3 4|
//  |4 5 6|  +  |2 1 2|  =  |6 6 8|
//  |7 8 9|     |1 1 0|     |8 9 9|
//
Massive Massive::operator+(Massive &massive) {
  Massive operation(size_);  // Локальный массив, который уйдет в ответ

  for (int i = 0; i < size_.getX(); i++)
    for (int j = 0; j < size_.getY(); j++)
      operation.massive_[i][j] = massive_[i][j] + massive.massive_[i][j];

  return operation;
}

// Умножение двух массивов
//  Размер будущей матрицы - это количество столбцов массива А на количество
//  строк массива B. Перебор состоит из трех циклов. Старший цикл перебирает
//  количество строк массива B, младший перебирает количество столбцов массива
//  А, а внутренний перебирает количество строк массива А.
//
//  Первые два цикла перебирают саму будущую матрицу (задом наперед правда).
//  Внутренний цикл как раз занимается созданием данных. В отличии от сложения,
//  в умножении будущая ячейка массива C равна сумме произведений элементов
//  столбцов массива А на элементы строк массива B.
Massive Massive::operator*(Massive &massive) {
  Massive operation(Size(size_.getX(), massive.size_.getY()));

  for (int i = 0; i < massive.size_.getY(); i++) {
    for (int j = 0; j < size_.getX(); j++) {
      double buffer = 0;
      for (int k = 0; k < size_.getY(); k++)
        buffer += massive_[i][k] * massive.massive_[k][j];  // Магия
      operation.massive_[i][j] = buffer;  // Записываем значение
    }
  }

  return operation;
}