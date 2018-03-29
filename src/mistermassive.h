// Основные функции программы
#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <ctype.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "massive.h"
#include "size.h"
#include "utils.h"
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

namespace Operation {

// Операция сложения двух массивов
void summation(std::vector<Massive> &massives);
// Операция умножения двух массивов
void multiplication(std::vector<Massive> &massives);

}  // namespace Operation

}  // namespace MisterMassive