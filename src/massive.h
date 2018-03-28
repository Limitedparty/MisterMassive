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

#include "position.h"
#include "size.h"

class Massive {
 private:
  double **massive_;  // Массив
  Size size_;         // Размер
  char letter_;       // Определяющая буква
 public:
  Massive(Size &size, char letter);

  void set(Position &position, double var);  // Установка значения элемента
  double get(Position &position);  // Получение значения элемента
  const Size *getSize();  // Получение размера массива
};