#pragma once

class MM {
	static int StartInputValue(int input);
public:
	// ������ ������ � ��������� 
	enum actions { msummation, mmultiplication };
	static actions Action;

	// �������� ���� ��������
	static int size1n; // ���-�� ����� ������� 1
	static int size1m; // ���-�� �������� ������� 1
	static int size2n; // ���-�� ����� ������� 2
	static int size2m; // ���-�� ��������� ������� 2

	// ��� �������
	static float ary1[10000][10000]; // �������. ������ ������� ��������� ����������� (�������) ���������� ���������. �����, �� �� �����.
	static float ary2[10000][10000];

	// ������� ��� ������ � ������
	static void StartInput();
	static void MassiveSizeSet();
	static void MassiveInput();

	static void MassiveSizeTest(); // �������� ������������� �������� � ����������� �� ���� ������
	static void MassiveOperationStart(); // �������� �������� � ��������

	// �������� � ���������
	static void Summation(); // �������� ��������
	static void Multiplication(); // ��������� ��������
};