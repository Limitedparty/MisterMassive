#include "mistermassive.h"
#include <iostream>
#include <string>

using namespace std;

// Операция сложения двух массивов:
void MM::Summation() {
	cout << "\nOutput:\n";
	for (int i = 0; i < size1n; i++) {
		for (int j = 0; j < size1m; j++) {
			float operation = ary1.data[i][j] + ary2.data[i][j]; // Сама операция.
			cout << operation << "   "; // Ее вывод.
		}
		cout << "\n"; // Новая строка после вывода строки данных.
	}
}

// Операция умножения двух массивов:
void MM::Multiplication() {
	cout << "\nOutput:\n";
	for (int i = 0; i < size2m; i++) {
		for (int j = 0; j < size1n; j++) {
			float operation = 0;
			for (int a = 0; a < size1m; a++) { // Повторение операции и сложение.
				operation += ary1.data[i][a] * ary2.data[a][j]; // Операция.
			}
			cout << operation << "   "; // Вывод.
		}
		cout << "\n"; // Новая строка после вывода строки данных.
	}
}

// Транспонирование массива:
void MM::Transposition()
{
	cout << "\nOutput:\n";
	for (int i = 0; i < size1m; i++) {
		for (int j = 0; j < size1n; j++) {
			float operation = ary1.data[j][i]; // Операция.
			cout << operation << "   "; // Вывод.
		}
		cout << "\n"; // Новая строка после вывода строки данных.
	}
}

// Простое умножение массива:
void MM::SimpleMultiplication()
{
	float multi;
	cout << "\n\nMultiplication by: ";
	cin >> multi;

	cout << "\nOutput:\n";
	for (int i = 0; i < size1n; i++) {
		for (int j = 0; j < size1m; j++) {
			float operation = ary1.data[i][j] * multi; // Операция.
			cout << operation << "   "; // Вывод.
		}
		cout << "\n"; // Новая строка после вывода строки данных.
	}
}

// Установка размера и выделение памяти массиву
void Massive::SetSize(int m, int n) {
	data = new float *[m];
	for (int i = 0; i < m; i++) {
		data[i] = new float[n];
	}
}
