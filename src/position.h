// Определение позиции для массива
#pragma once

class Position {
 private:
  int _x;  // Столбец
  int _y;  // Строка
 public:
  // Конструктор позиции (по умолчанию 0 0)
  Position() {
    _x = 0;
    _y = 0;
  }
  Position(int& x, int& y) {
    _x = x;
    _y = y;
  }

  int getX() { return _x; }      // Получение столбца
  int getY() { return _y; }      // Получение строки
  void setX(int& x) { _x = x; }  // Установка столбца
  void setY(int& y) { _y = y; }  // Установка строки
}