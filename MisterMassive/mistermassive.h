#pragma once

class MM {
	static int StartInputValue(int input);
public:
	// Методы работы с массивами 
	enum actions { msummation, mmultiplication };
	static actions Action;

	// Расзмеры двух массивов
	static int size1n; // кол-во строк массива 1
	static int size1m; // кол-во столбцов массива 1
	static int size2n; // кол-во строк массива 2
	static int size2m; // кол-во столбцовк массива 2

	// Два массива
	static float ary1[10000][10000]; // Костыль. Размер массива ограничен максимально (условно) допустимым значением. Глупо, ну да пофиг.
	static float ary2[10000][10000];

	// Функции для работы с вводом
	static void StartInput();
	static void MassiveSizeSet();
	static void MassiveInput();

	static void MassiveSizeTest(); // Проверка совместимости массивов в зависимости от типа задачи
	static void MassiveOperationStart(); // Начинает операцию с массивом

	// Операции с массивами
	static void Summation(); // Сложение массивов
	static void Multiplication(); // Умножение массивов
};