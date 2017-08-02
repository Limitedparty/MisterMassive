#pragma once
#include <iostream>

class Massive {
private:
	double** data; // Собственно сам массив
	int n_; // Строка
	int m_; // Стобец
public:
	void init(int & n, int & m); // Инициализация и создание массива
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