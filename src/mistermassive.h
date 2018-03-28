/*  Основные функции программы
 */
#pragma once

#include <iostream>
#include <ctype.h>
#include "vars.h"
#include "size.h"

namespace MisterMassive {

// Основной цикл программы
void Loop();

// Основное меню
void Menu(bool &isExit);
// Объявление массива
void DeclareMassive();

}  // namespace MisterMassive