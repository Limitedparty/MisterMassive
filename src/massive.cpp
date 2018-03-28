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
const Size *Massive::getSize() { return &size_; }

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