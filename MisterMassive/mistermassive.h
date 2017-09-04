﻿#pragma once
#include "massive.h"

/*
	Сей файл содержит прототипы функций, управляющие работой программы.
*/

static int StartInputValue(int input);  // Проверка валидности выбранной операции

// Методы работы с массивами
enum actions { msummation, mmultiplication, mtransposition, smultiplication, ssummation }; // Все возможные операции
static actions Action; // Выбранная операция

					   // Два массива
static Massive *ary1; // Первый массив
static Massive *ary2; // Второй масив

					  // Функции для работы с вводом
void StartInput(); // Выбирает режим
void MassiveSizeSet(); // Устанавливает размер и выделяет память массивам
void MassiveInput(); // Ввод данных в массив(ы)
void MassiveSizeTest(); // Проверка совместимости массивов в зависимости от типа задачи. (TODO)
void MassiveOperationStart(); // Начинает операцию с массивом