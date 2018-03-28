//  Определение массива
//
//  Структура массива (ее описывает класс ниже) выглядит так:
//	  _________________________
//	 |    c  т  о  л  б  ц  ы  |
//	 | с  x  x  x  x  x  x  x  |
//	 | т  x  x  x  x  x  x  x  |
//	 | р  x  x  x  x  x  x  x  |
//	 | о  x  x  x  x  x  x  x  |
//	 | к  x  x  x  x  x  x  x  |
//	 | и  x  x  x  x  x  x  x  |
//	 |    x  x  x  x  x  x  x  |
//	  —————————————————————————
//  x - это элементы массива
#pragma once

#include <iostream>
#include "position.h"
#include "size.h"

class Massive {
 private:
  double **massive_;  // Массив
  Size size_;         // Размер
 public:
  Massive(Size &size);

  void set(Position &position, double var);  // Установка значения элемента
  double get(Position &position);  // Получение значения элемента
  const Size *getSize();  // Получение размера массива

  void print();  // Вывод массива в консоль
};