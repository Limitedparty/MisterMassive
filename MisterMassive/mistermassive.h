#pragma once

class Massive {
public:
	float **data; // Собственно сам массив.
	int m, n; // Размеры массива.
	void SetSize(int m, int n);  // Установка размера массива и выделение памяти.
};

class MM {
	static int StartInputValue(int input);
public:
	// Методы работы с массивами.
	enum actions { msummation, mmultiplication, mtransposition, smultiplication};
	static actions Action;

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