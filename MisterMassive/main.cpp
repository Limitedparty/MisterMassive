#include "mistermassive.h"
#include <iostream>

// Собственно, отсюда стартует программа.

int main () {
	// Вывод приветствия
	std::cout << "Mister Massive v2\n\n";

	// Выбираем режим:
	MM::StartInput();
	// Указываем размер массивов
	MM::MassiveSizeSet();
	// Проверяем совместимость массивов
	MM::MassiveSizeTest();
	// Вводим данные в массивы (заполняем их)
	MM::MassiveInput();
	// Начинаем оперировать с массивами в зависимости от поставленной задачи
	MM::MassiveOperationStart();

	// Конец. Выход по enter.
	int no;
	std::cin >> no;
	return 0;
}
