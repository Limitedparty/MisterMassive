#include "massive.h"

Massive::Massive(Size &size) {
  // Указываем размер
  size_ = size;

  // Выделяем память массиву
  massive_ = new double *[size.getY()];
  for (int i = 0; i < size.getY(); i++) {
    massive_[i] = new double[size.getX()];
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
  for (int i = 0; i < size_.getY(); i++) {
    for (int j = 0; j < size_.getX(); j++) {
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

  for (int i = 0; i < size_.getY(); i++)
    for (int j = 0; j < size_.getX(); j++)
      operation.massive_[i][j] = massive_[i][j] + massive.massive_[i][j];

  return operation;
}

// Умножение двух массивов
//  Размер будущей матрицы - это количество столбцов массива B на количество
//  строк массива A. Перебор состоит из трех циклов. Старший цикл перебирает
//  строки массива А, младший перебирает столбцы массива B, а внутренний
//  перебирает столбцы массива А.
//  Первые два цикла перебирают саму будущую матрицу.
//  Внутренний цикл как раз занимается созданием данных. В отличии от сложения,
//  в умножении будущая ячейка массива C равна сумме произведений элементов
//  столбцов массива А на элементы строк массива B.
Massive Massive::operator*(Massive &massive) {
  Massive operation(Size(massive.size_.getX(), size_.getY()));

  for (int i = 0; i < size_.getY(); i++) {            // строки A
    for (int j = 0; j < massive.size_.getX(); j++) {  // столбцы B
      double buffer = 0;
      for (int k = 0; k < size_.getX(); k++)  // столбцы A
        buffer += massive_[i][k] * massive.massive_[k][j];
      operation.massive_[i][j] = buffer;  // Записываем значение
    }
  }

  return operation;
}