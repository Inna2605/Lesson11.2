/*3. Написати перевантажені функції (int, double, char) для виконання таких завдань:
■ Ініціалізація квадратної матриці;
■ Вивід матриці на екран;
■ Визначення максимального й мінімального елемента на головній діагоналі матриці;
■ Сортування елементів за зростанням окремо для кожного рядка матриці.*/
#include "Zadacha3.h"
using namespace std;

void Matruca()
{
	int a = 0;
	while (a != 4) {
		Vubir_dii();
		Vvod(a);
		Switch_dii(a);
		Show('\n');
	}
}


void Kvadratna_matruca(int Ar[][5], int N)
{
	Random();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Ar[i][j] = rand() % 30 - 15;
		}
	}
}

void Kvadratna_matruca(double Ar[][5], int N)
{
	Random();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Ar[i][j] = (double)(rand() % 30 - 15) / (double)(rand() % 9 + 1);
		}
	}
}

void Kvadratna_matruca(char Ar[][5], int N)
{
	Random();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Ar[i][j] = (char)(rand() % 30);
		}
	}
}

void Vubir_dii()
{
	cout << "Oberite diy z matrucei:\n"
		<< "1. Dii y int matruci\n"
		<< "2. Dii y double matruci\n"
		<< "3. Dii y char matruci\n"
		<< "4. Vuhid iz zadachi\n";
}

void Switch_dii(int N)
{
	switch (N)
	{
	case 1:Matrica_int(); break;
	case 2:Matrica_double(); break;
	case 3:Matrica_char(); break;
	case 4:break;
	default:Default;
	}
}
const int N = 5;
	
void Matrica_int()
{
	int Ar_int[N][N];
	cout << "Matruca int chisel:\n";
	Kvadratna_matruca(Ar_int, N);
	Show_matruci<int>(Ar_int, N);
	Show('\n');
	int max = Max_element_diagonal<int>(Ar_int, N);
	int min = Min_element_diagonal<int>(Ar_int, N);
	cout << "Maksumalnui element na golovnii diagonali: ";
	Show(max);
	Show('\n');
	cout << "Minimalnui element na golovnii diagonali: ";
	Show(min);
	Show('\n');
	Sortuvanna_za_zrostannam<int>(Ar_int, N);
	cout << "\nVidsortovani elementu za zrostannam okremo koznogo radka:\n";
	Show_matruci<int>(Ar_int, N);
	Show('\n');
}

void Matrica_double()
{
	double Ar_double[N][N];
	cout << "Matruca double chisel:\n";
	Kvadratna_matruca(Ar_double, N);
	Show_matruci<double>(Ar_double, N);
	Show('\n');
	double max = Max_element_diagonal<double>(Ar_double, N);
	double min = Min_element_diagonal<double>(Ar_double, N);
	cout << "Maksumalnui element na golovnii diagonali: ";
	Show(max);
	Show('\n');
	cout << "Minimalnui element na golovnii diagonali: ";
	Show(min);
	Show('\n');
	Sortuvanna_za_zrostannam<double>(Ar_double, N);
	cout << "\nVidsortovani elementu za zrostannam okremo koznogo radka:\n";
	Show_matruci<double>(Ar_double, N);
	Show('\n');
}

void Matrica_char()
{
	char Ar_char[N][N];
	cout << "Matruca char chisel:\n";
	Kvadratna_matruca(Ar_char, N);
	Show_matruci<char>(Ar_char, N);
	Show('\n');
	char max = Max_element_diagonal<char>(Ar_char, N);
	char min = Min_element_diagonal<char>(Ar_char, N);
	cout << "Maksumalnui element na golovnii diagonali: ";
	Show(max);
	Show('\n');
	cout << "Minimalnui element na golovnii diagonali: ";
	Show(min);
	Show('\n');
	Sortuvanna_za_zrostannam<char>(Ar_char, N);
	cout << "\nVidsortovani elementu za zrostannam okremo koznogo radka:\n";
	Show_matruci<char>(Ar_char, N);
	Show('\n');
}
