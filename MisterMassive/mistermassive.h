#pragma once
#include "massive.h"

/* Указывает номер версии */
#ifdef BUILD_VERSION
#define VERSION BUILD_VERSION
#else
#define VERSION 0
#endif

/* Указывает номер сборки */
#ifdef BUILD_ID
#define BUILDID BUILD_ID
#else
#define BUILDID 0
#endif


/*
	Сей класс содержит прототипы функций, управляющий работой программы.
*/

class MM {
	static int StartInputValue(int input);  // Проверка валидности выбранной операции
public:
	// Методы работы с массивами
	enum actions { msummation, mmultiplication, mtransposition, smultiplication}; // Все возможные операции
	static actions Action; // Выбранная операция

	// Два массива
	static Massive ary1; // Первый массив
	static Massive ary2; // Второй масив

	// Функции для работы с вводом
	static void StartInput(); // Выбирает режим
	static void MassiveSizeSet(); // Устанавливает размер и выделяет память массивам
	static void MassiveInput(); // Ввод данных в массив(ы)
	static void MassiveSizeTest(); // Проверка совместимости массивов в зависимости от типа задачи. (TODO)
	static void MassiveOperationStart(); // Начинает операцию с массивом
};