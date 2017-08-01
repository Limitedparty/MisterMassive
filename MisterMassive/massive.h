#pragma once
#include <iostream>

class Massive {
private:
	double** data; // Собственно сам массив.
	int m_, n_; // Размеры массива.
public:
	void init(int & m, int & n); // Инициализация и создание массива.
	friend std::ostream & operator<<(std::ostream & os, const Massive & masive); // Операция ввывода массива в консоль (с помощью cout).

	// Доступные операции.
	Massive operator+(Massive & massive); // Сложение массивов.
	Massive operator+(double & object); // Простое сложение массива.
	Massive operator*(Massive & massive); // Умножение массивов.
	Massive operator^(Massive & massive); // Транспонирование массивов.
};