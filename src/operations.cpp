// Операции над массивами
// Интерфейс для пользователя. Непосредственно массивы не трогает
#include "mistermassive.h"

using namespace MisterMassive::Operation;

// Операция сложения двух массивов
void MisterMassive::Operation::summation(std::vector<Massive> &massives) {
  // Ввод данных (выбор двух массивов)
  int x, y;
  printf("\nMassiveX + MassiveY = Massive%d\n", (int)massives.size() + 1);
  printf("X = ");
  scanf("%d", &x);
  printf("Y = ");
  scanf("%d", &y);

  // Проверка существования таких массивов
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

  // Добавляем массив
  massives.push_back(operation);
}

// Операция умножения двух массивов
void MisterMassive::Operation::multiplication(std::vector<Massive> &massives) {
  // Ввод данных (выбор двух массивов)
  int x, y;
  printf("\nMassiveX * MassiveY = Massive%d\n", (int)massives.size() + 1);
  printf("X = ");
  scanf("%d", &x);
  printf("Y = ");
  scanf("%d", &y);

  // Проверка существования таких массивов
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

  // Добавляем массив
  massives.push_back(operation);
}

// Операция транспонирования массива
void MisterMassive::Operation::transpose(std::vector<Massive> &massives) {
  // Ввод данных (выбор массива)
  int t;
  printf("\nT(MassiveT) = Massive%d\n", (int)massives.size() + 1);
  printf("T = ");
  scanf("%d", &t);
  // Проверка существования такого массива
  if (!(t <= (int)massives.size() && t > 0)) {
    printf("WTF with number? Massive not found.\n");
    return;
  }

  Massive *MassiveT = &massives[t - 1];

  // Операция
  Massive operation = !*MassiveT;
  // Вывод массива
  operation.print();

  // Добавляем массив
  massives.push_back(operation);
}

// Операция простого сложения массива
void MisterMassive::Operation::simpleSummation(std::vector<Massive> &massives) {
  // Ввод данных (выбор массива)
  int s, n;
  printf("\nMassiveS + N = Massive%d\n", (int)massives.size() + 1);
  printf("S = ");
  scanf("%d", &s);
  // Ввод числа
  printf("N = ");
  scanf("%d", &n);
  // Проверка существования такого массива
  if (!(s <= (int)massives.size() && s > 0)) {
    printf("WTF with number? Massive not found.\n");
    return;
  }

  Massive *MassiveT = &massives[s - 1];

  // Операция
  Massive operation = *MassiveT + n;
  // Вывод массива
  operation.print();

  // Добавляем массив
  massives.push_back(operation);
}