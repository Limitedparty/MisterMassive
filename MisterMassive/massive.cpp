#include "massive.h"

// Инициализация и создание массива
void Massive::init(int & n, int & m) {
	// Записываем размер массива
	n_ = n;
	m_ = m;

	// Выделяем память массиву
	data = new double *[n_];
	for (int i = 0; i < n_; i++) {
		data[i] = new double[m_];
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

	return os; // возвращаем ostream который прекрасно поймет cout
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
			operation.data[i][j] = data[i][j] + massive.data[i][j]; // Собственно сама операция
		}
	}
	return operation;
}

// Умножение двух массивов
Massive Massive::operator*(Massive & massive) {
	Massive operation;
	operation.init(n_, massive.m_); // Инициализируем локальный массив, который выкинем в ответ
	// Супер цикл. Тут вся магия
	for (int i = 0; i < massive.m_; i++) {
		for (int j = 0; j < n_; j++) {
			double input = 0;
			for (size_t k = 0; k < m_; k++) {
				input += data[i][k] * massive.data[k][j]; // Магия
			}
			operation.data[i][j] = input; // Записываем сумму
		}
	}

	/*
		Как это работает?

		Размер будущей матрицы - это количество строк матрицы A и количество стобцов матрицы B.
		Создаем перебор из двух for, где старший цикл - количество столбцов B, а младший - количество строк A.
		Проще говоря - делаем перебор будущей матрицы (чтобы заполнить ее еще не созданными данными)
		Теперь заворачиваем внутрь еще один цикл - это уже для создания данных. Будущая ячейка новой матрицы C - это
		сумма произведений элементов строки А на элементы столбца B.
		Вот и все.
	*/

	return operation;
}

// Простое умножение массива
Massive Massive::operator*(double & var) {
	Massive operation;
	operation.init(n_, m_); // Инициализируем локальный массив, который выкинем в ответ
	for (int i = 0; i < n_; i++) { // Перебираем
		for (int j = 0; j < m_; j++) { // весь массив
			operation.data[i][j] = data[i][j] * var; // Собственно сама операция
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
			operation.data[j][i] = data[i][j]; // Собственно сама операция
		}
	}
	return operation;
}