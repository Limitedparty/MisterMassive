// Операции над массивами
// Интерфейс для пользователя. Непосредственно массивы не трогает
#include "mistermassive.h"

using namespace MisterMassive::Operation;

// Операция сложения двух массивов
void MisterMassive::Operation::summation(std::vector<Massive> &massives) {
  // Ввод данных (выбор двух массивов)
  int x, y;
  printf("\nMassiveX + MassiveY = Massive%d\n", massives.size() + 1);
  printf("X = ");
  scanf("%d", &x);
  printf("Y = ");
  scanf("%d", &y);

  // Провека существования таких массивов
  if (!(x <= (int)massives.size() && x > 0 && y <= (int)massives.size() && y > 0)) {
    printf("WTF with number? Massives not found.\n");
    return;
  }
}