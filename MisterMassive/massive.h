#pragma once
#include <iostream>

class Massive {
private:
	double** data; // Собственно сам массив.
	int m_, n_; // Размеры массива.
public:
	void init(int & m, int & n); // Инициализация и создание массива.
	friend std::ostream & operator<<(std::ostream & os, const Massive & masive); // Операция ввывода массива в консоль (с помощью cout).

};