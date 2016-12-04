#include "mistermassive.h"
#include <iostream>
#include <string>

using namespace std;

void MM::Summation() {
	cout << "\nOutput:\n";
	for (int i = 0; i < size1n; i++) {
		for (int j = 0; j < size1m; j++) {
			float operation = ary1[i][j] + ary2[i][j];
			cout << operation << "   ";
		}
		cout << "\n";
	}
}

void MM::Multiplication() {
	cout << "\nOutput:\n";
	for (int i = 0; i < size2m; i++) {
		for (int j = 0; j < size1n; j++) {
			float operation = 0;
			for (int a = 0; a < size1m; a++) {
				operation += ary1[i][a] * ary2[a][j];
			}
			cout << operation << "   ";
		}
		cout << "\n";
	}
}

void MM::Transposition()
{
	cout << "\nOutput:\n";
	for (int i = 0; i < size1m; i++) {
		for (int j = 0; j < size1n; j++) {
			float operation = ary1[j][i];
			cout << operation << "   ";
		}
		cout << "\n";
	}
}
