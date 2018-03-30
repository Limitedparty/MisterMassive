// Основные функции программы (меню)
#include "mistermassive.h"

using namespace MisterMassive;

// Основное меню
void MisterMassive::Menu(bool &isExit) {
  // Выводим список доступных действий
  printf(
      "\nActions:\n 1) Declare new massive\n 2) Print massive\n 3) Operate "
      "with massives\n 4) Exit");
  printf("\n\nAction: ");

  // Получение ввода
  int action = 0;
  scanf("%d", &action);
  // Отчистка буффера
  Utils::clearBuffer();
  // Обработка ввода
  switch (action) {
    case 1:  // Объявление нового массива
      DeclareMassive();
      break;
    case 2:  // Вывод массива
      PrintMassive();
      break;
    case 3:  // Режим оперирования с массивами
      OperationsMassive();
      break;
    case 4:  // Выход из программы
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
  printf("Size x (columns / length): ");  // Кол-во столбцов
  scanf("%d", &x);
  printf("Size y (rows / hight): ");  // Кол-во строк
  scanf("%d", &y);
  Size size(x, y);

  // Создаем массив
  massives.push_back(Massive(size));
  int id = massives.size() - 1;

  // Заполняем массив (ручками)
  double input;
  for (int i = 0; i < size.getY(); i++) {
    for (int j = 0; j < size.getX(); j++) {
      printf("Massive%d[%d][%d]: ", id + 1, i, j);
      int err = scanf("%lf", &input);
      // Попытка словить ошибку (при вводе говна)
      if (err == 0) {
        // Таки словили ошибку
        std::cout << "<seting zero>\n";
        // Отчистка буффера
        Utils::clearBuffer();
        // Ставим ноль
        input = 0;
      }
      Position position(i, j);

      // Устанавливаем значение
      massives[id].set(position, input);
    }
  }

  massives[id].print();
}

void MisterMassive::PrintMassive() {
  int id = -1;
  // Ввод номера массива
  printf("Enter massive number: ");
  scanf("%d", &id);
  // Отчистка буффера
  Utils::clearBuffer();
  // Проверка введеного номера
  if (id > 0 && id <= (int)massives.size())
    massives[id - 1].print();  // Выводим массив
  else
    printf("Error. WTF with number?");  // Возмущаемся

  printf("\n");
}

void MisterMassive::OperationsMassive() {
  // Выводим все доступные массивы
  printf("\nAvailable massives: ");
  for (int i = 0; i < (int)massives.size(); i++) {
    printf("(%d) ", i + 1);
  }
  // Выводим все доступные операции
  printf(
      "\nOperations:\n 1) Summation massives\n 2) Multiplication massives\n"
      " 3) Transposition massive\n 4) Simple multiplication "
      "massive\nOperation: ");

  // Получение ввода
  int action = 0;
  scanf("%d", &action);
  // Отчистка буффера
  Utils::clearBuffer();
  // Обработка ввода
  switch (action) {
    case 1:  // Сложение массивов
      Operation::summation(massives);
      break;
    case 2:  // Умножение массивов
      Operation::multiplication(massives);
      break;
    case 3:  // Транспонирование массива
      Operation::transpose(massives);
      break;
    case 4:  // Простое сложение массива
      Operation::simpleSummation(massives);
      break;
    default:
      printf("Error. Operation not found.");
      break;
  }
}
