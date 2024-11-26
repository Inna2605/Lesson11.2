/*3. Написати перевантажені функції (int, double, char) для виконання таких завдань:
■ Ініціалізація квадратної матриці;
■ Вивід матриці на екран;
■ Визначення максимального й мінімального елемента на головній діагоналі матриці;
■ Сортування елементів за зростанням окремо для кожного рядка матриці.*/
#pragma once
#include<iostream>
#include "Zagalne.h"

void Matruca();
void Kvadratna_matruca(int Ar[][5], int N);
void Kvadratna_matruca(double Ar[][5], int N);
void Kvadratna_matruca(char Ar[][5], int N);
void Vubir_dii();
void Switch_dii(int N);
void Matrica_int();
void Matrica_double();
void Matrica_char();
template<typename T>T Max_element_diagonal(T Ar[][5], int N);
template<typename T>T Min_element_diagonal(T Ar[][5], int N);
template<typename T>void Show_matruci(T Ar[][5], int N);
template<typename T>void Sortuvanna_za_zrostannam(T Ar[][5], int N);

template<typename T> T Max_element_diagonal(T Ar[][5], int N)
{
	T Max = Ar[0][0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Max < Ar[i][j] && i == j) {
				Max = Ar[i][j];
			}
		}
	}
	return Max;
}

template<typename T> T Min_element_diagonal(T Ar[][5], int N)
{
	T Min = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Min > Ar[i][j] && i == j) {
				Min = Ar[i][j];
			}
		}
	}
	return Min;
}

template<typename T> void Show_matruci(T Ar[][5], int N)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Show(Ar[i][j]);
			Show(' ');
		}
		Show('\n');
	}
	Show('\n');
}

template<typename T> void Sortuvanna_za_zrostannam(T Ar[][5], int N)
{
	T x;
	int a;
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			a = i;
			x = Ar[k][i];
			for (int j = i + 1; j < N; j++) {
				if (Ar[k][j] < x) {
					a = j;
					x = Ar[k][j];
				}
			}
			if (a != i) {
				Ar[k][a] = Ar[k][i];
				Ar[k][i] = x;
			}
		}
	}
}
