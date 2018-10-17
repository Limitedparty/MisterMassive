//  Элемент матрицы
//  Описываем элемент матрицы, его позицию
//  а так же работу с ним.

template<typename T>
class Element {
 public:
  // Значение элемента
  T value;

  // Конструктор
  // По умолчанию эелемент равен нулю
  Element(T v = 0) {
    m = row;
    n = column;
    value = v;
  }
};