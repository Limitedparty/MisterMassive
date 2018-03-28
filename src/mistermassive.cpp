#include "mistermassive.h"

using namespace MisterMassive;

// Основное меню
void MisterMassive::Menu(bool &isExit) {
  // Выводим список доступных действий
  printf("\nActions:\n 1) Declare new massive\n 2) Print massive\n 3) Exit");
  printf("\n\nAction: ");

  // Получение ввода
  int action = 0;
  scanf_s("%d", &action);
  // Отчистка буффера
  while ((getchar()) != '\n')
    ;
  // Обработка ввода
  switch (action) {
    case 1:  // Объявление нового массива
      DeclareMassive();
      break;
    case 2:  // Вывод массива
      printf("Print massive\n");
      break;
    case 3:  // Выход из программы
      isExit = true;
      break;
    default:
      printf("Error. Action not found.");
      break;
  }
}

// Объявление нового массива
void MisterMassive::DeclareMassive() {
  // Задаем букву массиву
  char c = 0;
  printf("New massive letter: ");
  std::cin.get(c);
  // Переводим букву в верхний регистр
  c = (char)toupper(c);

  // Задаем длину будущего массива
  int x, y;
  printf("Size x (length): ");
  scanf_s("%d", &x);
  printf("Size y (hight): ");
  scanf_s("%d", &y);

  Size size(x, y);
}