#include "massive.h"

// Инициализация и создание массива.
void Massive::init(int & m, int & n) {
	// Записываем размер массива
	m_ = m;
	n_ = n; 

	// Выделяем память массиву
	data = new double *[m_];
	for (int i = 0; i < m_; i++) {
		data[i] = new double[n_];
	}
}

// Операция ввывода массива в консоль.
std::ostream & operator<<(std::ostream & os, const Massive & masive) {
	// Читаем и выводим данные из массива
	for (size_t m = 0; m < masive.m_; m++) {
		for (size_t n = 0; n < masive.n_; n++) {
			os << masive.data[m][n] << "   "; // Вывод с пробелом
		}
		os << std::endl; // Переход на новую строку
	}
	return os;
}

// Сложение массивов.
Massive Massive::operator+(Massive & massive) {
	Massive operation;
	return Massive();
}