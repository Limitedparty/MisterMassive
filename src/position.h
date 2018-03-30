// Определение позиции для элемента массива
#pragma once

class Position {
 private:
  int x_;  // Столбец
  int y_;  // Строка
 public:
  // Конструктор позиции (по умолчанию 0 0)
  Position() {
    x_ = 0;
    y_ = 0;
  }
  Position(int& x, int& y) {
    x_ = x;
    y_ = y;
  }

  int getX() { return x_; }      // Получение столбца
  int getY() { return y_; }      // Получение строки
  void setX(int& x) { x_ = x; }  // Установка столбца
  void setY(int& y) { y_ = y; }  // Установка строки
};