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
      PrintMassive();
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
  // Задаем длину будущего массива
  int x, y;
  printf("Size x (length): ");  // Кол-во столбцов
  scanf_s("%d", &x);
  printf("Size y (hight): ");  // Кол-во строк
  scanf_s("%d", &y);
  Size size(x, y);

  // Создаем массив
  massives.push_back(Massive(size));
  int id = massives.size() - 1;

  // Заполняем массив (ручками)
  double input;
  for (int i = 0; i < size.getX(); i++) {
    for (int j = 0; j < size.getY(); j++) {
      printf("Massive%d[%d][%d]: ", id + 1, i, j);
      int err = scanf_s("%lf", &input);
      // Попытка словить ошибку (при вводе говна)
      if (err == 0) {
        // Таки словили ошибку
        std::cout << "<seting zero>\n";
        // Отчистка буффера
        while ((getchar()) != '\n')
          ;
        // Ставим ноль
        input = 0;
      }
      // Устанавливаем значение
      massives[id].set(Position(i, j), input);
    }
  }

  massives[id].print();
}

void MisterMassive::PrintMassive() {
  int id = -1;
  // Ввод номера массива
  printf("Enter massive number: ");
  scanf_s("%d", &id);
  // Отчистка буффера
  while ((getchar()) != '\n')
    ;
  // Проверка введеного номера
  if (id > 0 && id <= (int)massives.size())
    massives[id - 1].print();  // Выводим массив
  else
    printf("Error. WTF with number?");  // Возмущаемся

  printf("\n");
}
