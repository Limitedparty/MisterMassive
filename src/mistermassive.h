// Основные функции программы
#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <ctype.h>
#include <stdio.h>
#include <string>
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
// Операции с массивами
void OperationsMassive();

}  // namespace MisterMassive