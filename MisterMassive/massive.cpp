#include "massive.h"

// Инициализация и создание массива
void Massive::init(int & n, int & m) {
	// Записываем размер массива
	n_ = n;
	m_ = m;

	// Выделяем память массиву
	data = new double *[m_];
	for (int i = 0; i < m_; i++) {
		data[i] = new double[n_];
	}
}

// Операция вывода массива в консоль
std::ostream & operator<<(std::ostream & os, const Massive & masive) {
	// Читаем и выводим данные из массива
	for (size_t n = 0; n < masive.n_; n++) {
		for (size_t m = 0; m < masive.m_; m++) {
			os << masive.data[n][m] << "   "; // Вывод с пробелом
		}
		os << std::endl; // Переход на новую строку
	}
	return os;
}

// Сложение массивов
Massive Massive::operator+(Massive & massive) {
	Massive operation;
	operation.init(n_, m_); // Инициализируем локальный массив, который выкинем в ответ
	for (int i = 0; i < n_; i++) { // Перебираем
		for (int j = 0; j < m_; j++) { // весь массив
			operation.data[m_][n_] = data[m_][n_] + massive.data[m_][n_]; // Собственно сама операция
		}
	}
	return operation;
}
