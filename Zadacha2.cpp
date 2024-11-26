//2. Написати функцію, що реалізує алгоритм бінарного пошуку заданого ключа в одновимірному масиві.
#include "Zadacha2.h"

using namespace std;

void Binarnui_posyk()
{
	int K, S;
	const int N = 30;
	int Ar[N];
	Randomnui_masuv(Ar, N);
	Show_masuv(Ar, N);
	Show('\n');
	cout << "Vporadkovanui masuv:";
	Show('\n');
	Svudke_sortuvanna(Ar, N);
	Show_masuv(Ar, N);
	Show('\n');
	cout << "Vvedite kluch dla posuky v masuvi: ";
	Vvod(K);
	S = Poshuk_binarnui(Ar, N, K);
	if (S != -1) {
		cout << "\nZnaidenui element na pozusii ";
		Show(S + 1);
		cout << " za vvedenum kluchem ";
		Show(K);
		Show('\n');
	 }
	else cout << "Elementa v masuvi ne znaideno za zadanum klychem: ";
	Show('\n');
}

void Svudke_sortuvanna(int Ar[], int N)
{
	int x, c, i = 0, j = N - 1;
	c = Ar[N / 2];

	do {
		while (Ar[i] < c)i++;
		while (Ar[j] > c)j--;
		if (i <= j) {
			x = Ar[i];
			Ar[i] = Ar[j];
			Ar[j] = x;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)Svudke_sortuvanna(Ar, j);
	if (N > i)Svudke_sortuvanna(Ar + i, N - i);
}

int Poshuk_binarnui(int Ar[], int N, int K)
{
	int L = 0, P = N - 1, M;
	while (true) {
		M = (L + P) / 2;
		if (K < Ar[M]) {
			P = M - 1;
		}
		else if (K > Ar[M]) {
			L = M + 1;
		}
		else return M;
		if (L > P)return -1; 
	}
}
