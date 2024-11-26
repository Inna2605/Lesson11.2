//4. Написати рекурсивну функцію знаходження найбільшого спільного дільника двох цілих чисел.
#include "Zadacha4.h"
using namespace std;

int Dilnuk(int N1, int N2, int D);
int Perevirka_na_chotnost (int N1, int N2, int D);
int Znahodzenna_dilnukiv(int N1, int N2, int D, int Y, int X);

void Spilnui_dilnuk()
{
	int n1, n2, D = 1;
	cout << "Vvedite dva cilux chisla: ";
	Vvod(n1);
	Vvod(n2);
	Show('\n');
	D = Dilnuk(n1, n2, D);

	cout << "Naibilsui dilnuk dla dvyx chisel ";
	Show(n1);
	cout << " ta ";
	Show(n2);
	cout << " maemo ";
	Show(D);
	Show('\n');
}

int Dilnuk(int N1, int N2, int D)
{
	int x = 0, l = 0, y = 0;
	if (N1 > N2) {
		l = N1;
		N1 = N2;
		N2 = l;
	}
	else if (N1 == N2){
		return N1; 
	}
	else {
		int i = 0;
			x = Znahodzenna_dilnukiv(N1, N2, i, y, x);
		return x;
	}
}

int Perevirka_na_chotnost(int N1, int N2, int i)
{
	int n = 0;
	if (N1 % i == 0 && N2 % i == 0) {
		return i;
	}
	return n;
}

int Znahodzenna_dilnukiv(int N1, int N2, int i, int y, int x)
{
	if (i == N1) return x;
	i++;
	y = Perevirka_na_chotnost(N1, N2, i);
	if (y != 0) {
		x = y;
	}
	return Znahodzenna_dilnukiv(N1, N2, i, y, x);
}
