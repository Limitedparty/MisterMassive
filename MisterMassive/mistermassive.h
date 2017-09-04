#pragma once
#include "massive.h"

/*
	Сей файл содержит прототипы функций, управляющие работой программы.
*/

static int StartInputValue(int input);  // Проверка валидности выбранной операции

// Методы работы с массивами
enum modes { msummation, mmultiplication, mtransposition, smultiplication, ssummation }; // Все возможные операции
static modes Action; // Выбранная операция

// Два массива
static Massive *m1; // Первый массив
static Massive *m2; // Второй масив

// Функции для работы с вводом
void StartInput(); // Выбирает режим
void MassiveSizeSet(); // Устанавливает размер и выделяет память массивам
void MassiveInput(); // Ввод данных в массив(ы)
void MassiveSizeTest(); // Проверка совместимости массивов в зависимости от типа задачи. (TODO)
void MassiveOperationStart(); // Начинает операцию с массивом