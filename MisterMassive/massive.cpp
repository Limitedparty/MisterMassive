#include "massive.h"

// ������������� � �������� �������.
void Massive::init(int & m, int & n) {
	// ���������� ������ �������
	m_ = m;
	n_ = n; 

	// �������� ������ �������
	data = new double *[m_];
	for (int i = 0; i < m_; i++) {
		data[i] = new double[n_];
	}
}

// �������� ������� ������� � �������.
std::ostream & operator<<(std::ostream & os, const Massive & masive) {
	// ������ � ������� ������ �� �������
	for (size_t m = 0; m < masive.m_; m++) {
		for (size_t n = 0; n < masive.n_; n++) {
			os << masive.data[m][n] << "   "; // ����� � ��������
		}
		os << std::endl; // ������� �� ����� ������
	}
	return os;
}

// �������� ��������.
Massive Massive::operator+(Massive & massive) {
	Massive operation;
	return Massive();
}