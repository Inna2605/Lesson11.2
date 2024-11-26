//1. Написати функцію, що реалізує алгоритм лінійного пошуку заданого ключа в одновимірному масиві.
#include "Zadacha1.h"
using namespace std;

void Liniinui_posuk()
{
	int K, R;
	const int N = 30;
	int Ar[N];
	Randomnui_masuv(Ar, N);
	Show_masuv(Ar, N);
	cout << "Vvedite kluch dla posuky v masuvi: ";
	Vvod(K);
	R = Poshuk(Ar, N, K);
	if (R != -1) {
		cout << "\nZnaidenui element na pozusii ";
		Show(R + 1);
		cout << " za vvedenum kluchem ";
		Show(K);
		Show('\n');
	}
	else cout << "Elementa v masuvi ne znaideno za zadanum klychem: ";
	Show('\n');
}

int Poshuk(int Ar[], int N, int n)
{
	for (int i = 0; i < N; i++) {
		if (Ar[i] == n)	return i; 
	}
	return -1;
}
