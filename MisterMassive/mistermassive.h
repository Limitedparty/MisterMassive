#pragma once

class Massive {
public:
	float **data;
	void SetSize(int m, int n);
};

class MM {
	static int StartInputValue(int input);
public:
	// Методы работы с массивами.
	enum actions { msummation, mmultiplication, mtransposition, smultiplication};
	static actions Action;

	// Расзмеры двух массивов.
	static int size1n; // кол-во строк массива 1
	static int size1m; // кол-во столбцов массива 1
	static int size2n; // кол-во строк массива 2
	static int size2m; // кол-во столбцовк массива 2

	// Два массива.
	static Massive ary1; // Первый массив.
	static Massive ary2; // Второй масив.

	// Функции для работы с вводом.
	static void StartInput(); // Выбирает режим.
	static void MassiveSizeSet(); // Устанавливает размер и выделяет память массивам.
	static void MassiveInput(); // Ввод данных в массив(ы).

	static void MassiveSizeTest(); // Проверка совместимости массивов в зависимости от типа задачи. (TODO)
	static void MassiveOperationStart(); // Начинает операцию с массивом.

	// Операции с массивами.
	static void Summation(); // Сложение массивов.
	static void Multiplication(); // Умножение массивов.
	static void Transposition(); // Транспонирование массива.
	static void SimpleMultiplication(); // Простое умножение эелементов массива.
};