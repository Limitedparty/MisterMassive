#include "mistermassive.h"
#include <iostream>
#include <string>

using namespace std;

MM::actions MM::Action;

// Массивы
Massive MM::ary1;
Massive MM::ary2;;

void MM::StartInput() {
	// Выводим возможные операции.
	cout << "Actions:\n(1) Summation massives\n(2) Multiplication massives\n(3) Transposition massive\n(4) Simple multiplication massive\n\n";

	int now = 0;

	// Заставляем выбирать до тех пор, пока нам не дадут существующую операцию.
	while (StartInputValue(now)) { // См. функцию. Помимо проверки существования операции, она еще и присваивается (MM::actions).
		cout << "Select  action: ";
		try
		{
			// Получаем ввод из клавиатуры и записываем в локальную переменную. Ее в свою очередь отправляем на проверку.
			cin >> now;
		}
		catch (exception e) {
			// Выводим ошибочку, если нам втирают какую-то дичь.
			cout << "Error. Please enter integer value.";
		}
	}
}

void MM::MassiveSizeSet() {
	int n, m;

	// Вбиваем размеры первого массива.
	cout << "\nNumber of columns of the array #1: ";
	cin >> n;
	cout << "\nNumber of rows of the array #1: ";
	cin >> m;
	// Выделяем память массиву
	MM::ary1.init(n, m);

	// Тут просто идет отскок, если операция требует всего один массив.
	if (MM::Action == mtransposition || MM::Action == smultiplication)
		return;

	// Вбиваем размеры второго массива.
	cout << "\nNumber of columns of the array #2: ";
	cin >> n;
	cout << "\nNumber of rows of the array #2: ";
	cin >> m;
	// Выделяем память массиву
	MM::ary2.init(n, m);
}

void MM::MassiveInput() {
	double input;

	// Вбиваем данные первого массива.
	for (int i = 0; i < MM::ary1.n(); i++) {
		for (int j = 0; j < MM::ary1.m(); j++) {
			cout << "\nmassive1[" << i << "][" << j << "]: ";
			cin >> input;
			ary1.set(i, j, input);
		}
	}

	// Вбиваем данные одного массива, если так надо.
	// Тут просто идет отскок, если операция требует всего один массив.
	if (MM::Action == mtransposition || MM::Action == smultiplication)
		return;

	// Вбиваем данные второго массива.
	for (int i = 0; i < MM::ary2.n(); i++) {
		for (int j = 0; j < MM::ary2.m(); j++) {
			cout << "\nmassive2[" << i << "][" << j << "]: ";
			cin >> input;
			ary2.set(i, j, input);
		}
	}
}

void MM::MassiveSizeTest() {
	 // TODO Проверка совместимости массивов.
}

void MM::MassiveOperationStart() {
	// В зависимости от выбранной операции, направляет на нужную функцию, которые находятся в master.cpp
	switch (MM::Action)
	{
	case msummation:
		cout << endl << MM::ary1 + MM::ary2;
		break;
	case mmultiplication:
		cout << endl << MM::ary1 * MM::ary2;
		break;
	case mtransposition:
		cout << endl << MM::ary1.transposition();
		break;
	case smultiplication:
		double multi;
		cout << "\n\nMultiplication by: ";
		cin >> multi;
		cout << endl << MM::ary1 * multi;
		break;
	default:
		break;
	}
}


int MM::StartInputValue(int input) {
	// В зависимости от выбранной цифры выбирает нужную нам операцию.
	// Если прилетает какая-то дичь - возращаем 1 (т.е. true), что является сигналом об ошибке.
	switch (input)
	{
	case 1:
		MM::Action = msummation;
		return 0;
	case 2:
		MM::Action = mmultiplication;
		return 0;
	case 3:
		MM::Action = mtransposition;
		return 0;
	case 4:
		MM::Action = smultiplication;
		return 0;
	default:
		return 1;
	}
}
