// Определение размера (для массивов)
#pragma once
class Size {
 private:
  int x_;  // Ширина (столбцы)
  int y_;  // Высота (строки)

 public:
  // Конструктор размера (по умолчанию 0 и 0)
  Size() {
    x_ = 0;
    y_ = 0;
  }
  Size(int x, int y) {
    x_ = x;
    y_ = y;
  }

  bool operator==(Size& size) {  // Проверка на равенство
    if (size.getX() == x_ && size.getY() == y_)
      return true;
    else
      return false;
  }

  bool operator!=(Size& size) {  // Проверка на неравенство
    if (size.getX() == x_ && size.getY() == y_)
      return false;
    else
      return true;
  }

  int getX() { return x_; }      // Получение ширины
  int getY() { return y_; }      // Получение высоты
  void setX(int& x) { x_ = x; }  // Установка ширины
  void setY(int& y) { y_ = y; }  // Установка высоты
};