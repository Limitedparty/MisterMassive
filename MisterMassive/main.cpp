#include "mistermassive.h"
#include <iostream>

// ���������� �� ���� �������� ���������

int main () {
	// ����� �����������
	std::cout << "Mister Massive v2\n\n";

	// �������� �����
	MM::StartInput();
	// ��������� ������ ��������
	MM::MassiveSizeSet();
	// ��������� ������������� ��������
	MM::MassiveSizeTest();
	// ������ ������ � ������� (��������� ��)
	MM::MassiveInput();
	// �������� ����������� � ��������� � ����������� �� ������������ ������
	MM::MassiveOperationStart();

	// �����. ����� �� enter.
	int no;
	std::cin >> no;
	return 0;
}
