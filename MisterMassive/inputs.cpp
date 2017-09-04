#include "mistermassive.h"
#include <iostream>
#include <string>

using namespace std;

void StartInput() {
	// Выводим возможные операции
	cout << "Actions:\n(1) Summation massives\n(2) Multiplication massives\n(3) Transposition massive\n(4) Simple multiplication massive\n(5) Simple summation massive\n\n";

	int now = 0;

	// Заставляем выбирать до тех пор, пока нам не дадут существующую операцию
	while (StartInputValue(now)) { // См. функцию. Помимо проверки существования операции, она еще и присваивается (actions)
		cout << "Select  action: ";
		try
		{
			// Получаем ввод из клавиатуры и записываем в локальную переменную. Ее в свою очередь отправляем на проверку
			cin >> now;
		}
		catch (exception e) {
			// Выводим ошибочку, если нам втирают какую-то дичь
			cout << "Error. Please enter integer value.";
		}
	}
}

void MassiveSizeSet() {
	int n, m;

	// Вбиваем размеры первого массива
	cout << "\nNumber of columns of the array #1: ";
	cin >> m;
	cout << "\nNumber of rows of the array #1: ";
	cin >> n;
	// Выделяем память массиву
	m1 = new Massive(n, m);

	// Тут просто идет отскок, если операция требует всего один массив
	if (Action == mtransposition || Action == smultiplication || Action == ssummation)
		return;

	// Вбиваем размеры второго массива
	cout << "\nNumber of columns of the array #2: ";
	cin >> m;
	cout << "\nNumber of rows of the array #2: ";
	cin >> n;
	// Выделяем память массиву
	m2 = new Massive(n, m);
}

void MassiveInput() {
	double input;

	// Вбиваем данные первого массива.
	for (int i = 0; i < m1->n(); i++) {
		for (int j = 0; j < m1->m(); j++) {
			cout << "\nmassive1[" << i + 1 << "][" << j + 1 << "]: ";
			cin >> input;
			m1->set(i, j, input);
		}
	}

	// Вбиваем данные одного массива, если так надо
	// Тут просто идет отскок, если операция требует всего один массив
	if (Action == mtransposition || Action == smultiplication || Action == ssummation)
		return;

	// Вбиваем данные второго массива.
	for (int i = 0; i < m2->n(); i++) {
		for (int j = 0; j < m2->m(); j++) {
			cout << "\nmassive2[" << i + 1 << "][" << j + 1 << "]: ";
			cin >> input;
			m2->set(i, j, input);
		}
	}
}

void MassiveSizeTest() {
	 // TODO Проверка совместимости массивов
}

void MassiveOperationStart() {
	// В зависимости от выбранной операции проделывает работу
	switch (Action)
	{
	case msummation:
		cout << endl << *m1 + *m2;
		break;
	case mmultiplication:
		cout << endl << *m1 * *m2;
		break;
	case mtransposition:
		cout << endl << m1->transposition();
		break;
	case smultiplication:
		double multi;
		cout << "\n\nMultiplication by: ";
		cin >> multi;
		cout << endl << *m1 * multi;
		break;
	case ssummation:
		double var;
		cout << "\n\nSummation by: ";
		cin >> var;
		cout << endl << *m1 + var;
		break;
	default:
		break;
	}
}

// Проверка валидности выбранной операции
int StartInputValue(int input) {
	// В зависимости от выбранной цифры выбирает нужную нам операцию
	// Если прилетает какая-то дичь - возращаем 1 (т.е. true), что является сигналом об ошибке
	switch (input)
	{
	case 1:
		Action = msummation;
		return 0;
	case 2:
		Action = mmultiplication;
		return 0;
	case 3:
		Action = mtransposition;
		return 0;
	case 4:
		Action = smultiplication;
		return 0;
	case 5:
		Action = ssummation;
		return 0;
	default:
		return 1;
	}
}
