//  Описание класса матрицы
//  Да, программа имеет в названии слово "массив",
//  но по факту речь, естественно, идет о матрицах

#pragma once
#include "element.h"
#include "size.h"

template<typename T>
class Matrix {
 private:
  // Размер матрицы
  Size size_;
  // Элементы
  Element<T>** elements_;

 public:
   // Конструктор
   Matrix(Size size) {
     // Записываем размер
     size_ = size;
     // Выделяем память
     elements_ = new Element[size_.rows(), size.columns()];
   }
};