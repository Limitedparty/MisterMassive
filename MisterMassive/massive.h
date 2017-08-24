#pragma once
#include <iostream>

/*
	Как это работает?

	В кратце структура матрицы (ее описывает класс ниже) выглядит так:
	 ______________________
	|    с  т  р  о  к  а  |
	| с  x  x  x  x  x  x  |
	| т  x  x  x  x  x  x  |
	| о  x  x  x  x  x  x  |
	| л  x  x  x  x  x  x  |
	| б  x  x  x  x  x  x  |
	| е  x  x  x  x  x  x  |
	| ц  x  x  x  x  x  x  |
	 ——————————————————————

	x - это элементы матрицы. Доступ к элементам можно получит примерно так: massive.get(строка, столбец);
	Границы матрицы задаются конструктором. Им же и выделяется память.
	Делается это просто: massive.init(колвоСтрок, колвоСтолбцов)

	Прототипы функций данного класса описаны в файле massive.cpp
*/

class Massive {
private:
	double** data; // Собственно сам массив [строка][стобец]
	int n_; // Строка
	int m_; // Стобец
public:
	Massive(int & n, int & m); // Конструктор
	friend std::ostream & operator<<(std::ostream & os, const Massive & masive); // Операция ввывода массива в консоль (с помощью cout)
	void set(int & n, int & m, double var); // Изменение элемента массива
	const double get(int & n, int & m) { return data[n][m]; }; // Получение элемента массива
	const int n() { return n_; }; // Возвращает количество строк
	const int m() { return m_; }; // возвращает количество столбцов

	// Доступные операции
	Massive operator+(Massive & massive); // Сложение массивов
	Massive operator+(double & var); // Простое сложение массива (TODO)
	Massive operator*(Massive & massive); // Умножение массивов
	Massive operator*(double & var); // Простое умножение массива
	Massive transposition(); // Транспонирование массива
};