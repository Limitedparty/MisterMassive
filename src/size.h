/* Определение размера (для массивов)
 */

class Size {
   private:
    int _x;
    int _y;

   public:
    Size(int x = 0, int y = 0) {
        _x = x;
        _y = y;
    }

    // Получение длин
    int getX() { return _x; }
    int getY() { return _y; }

    // Установка длин
    void setX(int x) { _x = x; }
    void setY(int y) { _y = y; }

    // Оператор присвоения
    Size operator=(Size b) {
        _x = b.getX();
        _y = b.getY();
    }
};