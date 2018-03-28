// Основные функции программы
#pragma once

#include <ctype.h>
#include <iostream>
#include <vector>
#include "massive.h"
#include "size.h"
#include "vars.h"

namespace MisterMassive {

// Массив массивов :D
static std::vector<Massive> massives;

// Основное меню
void Menu(bool &isExit);
// Объявление массива
void DeclareMassive();
// Вывод массива
void PrintMassive();

}  // namespace MisterMassive