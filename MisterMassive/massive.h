#pragma once
#include <iostream>

class Massive {
private:
	double** data; // Собственно сам массив
	int n_, m_; // Размеры массива
public:
	void init(int & m, int & n); // Инициализация и создание массива
	friend std::ostream & operator<<(std::ostream & os, const Massive & masive); // Операция ввывода массива в консоль (с помощью cout)
	void set(int & m, int & n, double var); // Изменение элемента массива
	void get(int & m, int & n); // Получение элемента массива

	// Доступные операции
	Massive operator+(Massive & massive); // Сложение массивов
	Massive operator+(double & var); // Простое сложение массива
	Massive operator*(Massive & massive); // Умножение массивов
	Massive transposition(); // Транспонирование массива
};