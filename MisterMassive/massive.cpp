﻿#include "massive.h"

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

// Изменение элемента массива
void Massive::set(int & n, int & m, double var) {
	data[n][m] = var; // Вери симпл, мэн! Нарушаем ООП нафиг.
}


// Сложение двух массивов
Massive Massive::operator+(Massive & massive) {
	Massive operation;
	operation.init(n_, m_); // Инициализируем локальный массив, который выкинем в ответ
	for (int i = 0; i < n_; i++) { // Перебираем
		for (int j = 0; j < m_; j++) { // весь массив
			operation.data[i][j] = data[i][j] + massive.get(i, j); // Собственно сама операция
		}
	}
	return operation;
}

// Умножение двух массивов
Massive Massive::operator*(Massive & massive) {
	Massive operation;
	operation.init(m_, massive.n_); // Инициализируем локальный массив, который выкинем в ответ
	for (int i = 0; i < massive.m_; i++) {
		for (int j = 0; j < n_; j++) {
			for (size_t k = 0; k < m_; k++) {
				operation.data[i][k] += data[i][k] * massive.data[k][j]; // Магия
			}
		}
	}
	return operation;
}

// Простое умножение массива
Massive Massive::operator*(double & var) {
	Massive operation;
	operation.init(n_, m_); // Инициализируем локальный массив, который выкинем в ответ
	for (int i = 0; i < n_; i++) { // Перебираем
		for (int j = 0; j < m_; j++) { // весь массив
			operation.data[n_][m_] = data[n_][m_] + var; // Собственно сама операция
		}
	}
	return operation;
}

// Транспонирование массива
Massive Massive::transposition() {
	Massive operation;
	operation.init(m_, n_); // Инициализируем локальный массив, который выкинем в ответ
	for (int i = 0; i < n_; i++) { // Перебираем
		for (int j = 0; j < m_; j++) { // весь массив
			operation.data[i][j] = data[j][i]; // Собственно сама операция
		}
	}
	return operation;
}