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
  if (!(x <= (int)massives.size() && x > 0 && y <= (int)massives.size() &&
        y > 0)) {
    printf("WTF with number? Massives not found.\n");
    return;
  }

  Massive *MassiveX = &massives[x - 1];
  Massive *MassiveY = &massives[y - 1];

  // Проверка совместимости массивов
  if (*MassiveX->getSize() != *MassiveY->getSize()) {
    printf("Massives are not compatible.\n");
    return;
  }

  // Операция
  Massive operation = *MassiveX + *MassiveY;
  // Вывод массива
  operation.print();
}

// Операция умножения двух массивов
void MisterMassive::Operation::multiplication(std::vector<Massive> &massives) {
  // Ввод данных (выбор двух массивов)
  int x, y;
  printf("\nMassiveX * MassiveY = Massive%d\n", massives.size() + 1);
  printf("X = ");
  scanf("%d", &x);
  printf("Y = ");
  scanf("%d", &y);

  // Провека существования таких массивов
  if (!(x <= (int)massives.size() && x > 0 && y <= (int)massives.size() &&
        y > 0)) {
    printf("WTF with number? Massives not found.\n");
    return;
  }

  Massive *MassiveX = &massives[x - 1];
  Massive *MassiveY = &massives[y - 1];
  
  // Проверка совместимости массивов
  if (MassiveX->getSize()->getX() != MassiveY->getSize()->getY()) {
    printf("Massives are not compatible.\n");
    return;
  }

  // Операция
  Massive operation = *MassiveX * *MassiveY;
  // Вывод массива
  operation.print();
}