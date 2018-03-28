#include "massive.h"

Massive::Massive(Size &size, char letter) {
  // Указываем размер
  size_ = size;
  // Указываем определяющую букву
  letter_ = letter;

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
const Size *Massive::getSize() { return &size_; }