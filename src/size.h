/* Определение размера (для массивов)
 */

class Size {
 private:
  int _x;
  int _y;

 public:
  // Конструктор размера (по умолчанию 0 и 0)
  Size(int x = 0, int y = 0) {
    _x = x;
    _y = y;
  }

  // Операция присвоения
  Size operator=(Size b) {
    _x = b.getX();
    _y = b.getY();
  }

  int getX() { return _x; }     // Получение ширины
  int getY() { return _y; }     // Получение высоты
  void setX(int x) { _x = x; }  // Установка ширины
  void setY(int y) { _y = y; }  // Установка высоты
};