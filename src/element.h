//  Элемент матрицы
//  Описываем элемент матрицы, его позицию
//  а так же работу с ним.

class Element {
 private:
  // m - позиция по строке
  // n - позиция по столбцу
  int m, n;
 public:
  // Знаение элемента
  double value;
  // Конструктор
  Element(int row, int column, double v = 0) {
    m = row;
    n = column;
    value = v;
  }
};