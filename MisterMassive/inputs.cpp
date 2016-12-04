#include "mistermassive.h"
#include <iostream>
#include <string>

using namespace std;

MM::actions MM::Action;

// Размеры двух массивов
int MM::size1n;
int MM::size1m;
int MM::size2n;
int MM::size2m;

// Массивы
float MM::ary1[10000][10000];
float MM::ary2[10000][10000];

void MM::StartInput()
{
	cout << "Actions:\n(1) Summation massives\n(2) Multiplication massives\n(3) Transposition massive\n\n";

	int now = 0;

	while (StartInputValue(now)){
		cout << "Select  action: ";
		try
		{
			cin >> now;
		}
		catch (exception e) {
			cout << "Error. Please enter integer value.";
		}
	}
}

void MM::MassiveSizeSet()
{
	// Вбиваем размеры двух массивов
	cout << "\nNumber of columns of the array #1: ";
	cin >> MM::size1m;
	cout << "\nNumber of rows of the array #1: ";
	cin >> MM::size1n;

	// Ну или одного ;)
	if (MM::Action != mtransposition) {
		cout << "\nNumber of columns of the array #2: ";
		cin >> MM::size2m;
		cout << "\nNumber of rows of the array #2: ";
		cin >> MM::size2n;
	}

}

void MM::MassiveInput()
{
	// Вбиваем данные массивов
	for (int i = 0; i < size1n; i++) {
		for (int j = 0; j < size1m; j++) {
			cout << "\nmassive1[" << i << "][" << j << "]";
			cin >> ary1[i][j];
		}
	}
	// Вбиваем данные одного массива, если так надо
	if (MM::Action != mtransposition) {
		for (int i = 0; i < size2n; i++) {
			for (int j = 0; j < size2m; j++) {
				cout << "\nmassive2[" << i << "][" << j << "]";
				cin >> ary2[i][j];
			}
		}
	}
}

void MM::MassiveSizeTest()
{
	 // TODO Проверка совместимости массивов
}

void MM::MassiveOperationStart()
{
	switch (MM::Action)
	{
	case msummation:
		MM::Summation();
		break;
	case mmultiplication:
		MM::Multiplication();
		break;
	case mtransposition:
		MM::Transposition();
		break;
	default:
		break;
	}
}


int MM::StartInputValue(int input) 
{
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
	default:
		return 1;
	}
}