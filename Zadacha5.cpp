/*5. Написати гру «Бики та корови». Програма «загадує» чотиризначне число і гравець має вгадати його.
Після введення користувачем числа програма повідомляє, скільки цифр числа вгадано (бики) і
скільки цифр вгадано і стоїть на потрібному місці (корови).
Після відгадування числа на екран необхідно вивести кількість зроблених користувачем спроб.
У програмі необхідно використовувати рекурсію.*/
#include "Zadacha5.h"
using namespace std;
void Zagadane_chislo(int Ar[], int N);
void Show_chisla(int Ar[], int N);
int Buku(int Ar[], int N, int C, int b);
int Korovu(int Ar[], int N, int C, int k);
int Chislo(int Ar[], int N);
int Porivnanna(int Ar[], int N, int x, int b);

void Gra()
{
	const int N = 4;
	int Ar[N];

	cout << "Maemo zagadane chislo: ";
	Zagadane_chislo(Ar, N);

	int K = Chislo(Ar, N);

	Show_chisla(Ar, N);
	Show('\n');
	while(true) {
		int b = 0, k = 0;
		int a = 0;
		cout << "Vvedite choturuznachne chuslo: ";
		Vvod(a);
		b = Buku(Ar, N, a, b);
		k = Korovu(Ar, N, a, k);
		cout << "Vsogo vgadano cifr(buku): ";
		Show(b);
		Show('\n');
		cout << "Vsogo vgadano cifr i vonu stoiat na svoemy mistsi(korovu): ";
		Show(k);
		Show('\n');
		Show('\n');
		if (K == a)break;
	}
}

void Zagadane_chislo(int Ar[], int N)
{
	Random();
	for (int i = 0; i < N; i++) {
		Ar[i] = rand() % 8 + 1;
	}
}

void Show_chisla(int Ar[], int N)
{
	for (int i = 0; i < N; i++) {
		Show(Ar[i]);
	}
	Show('\n');
}

int Buku(int Ar[], int N, int C, int b)
{
	int x, y = C, j = 0, k = 0, n = 0;
	const int N2 = 4;
	int Ar2[N2];
	

	for (int i = 0; i < N; i++) {
		x = y % 10;
		y /= 10;

		for (int r = 0; r < N2; r++) {
			if (Ar2[r] == x) {
				n++;
			}
		}
		if (n != 0) {
			n = 0;
			continue;
		}

		for (int j = 0; j < N; j++) {
			if (Ar[j] == x) {
				Ar2[k] = Ar[j];
				b++;
				k++;
			}
		}
	}
	return b;

	/*for (int i = 0; i < k; i++) {

	}*/

	//b = Porivnanna(Ar, N, x, b);
	//return Buku(Ar, N, C /= 10, b);
}

int Korovu(int Ar[], int N, int C, int k)
{
	int x;
	if (C == 0)return k;
		x = C % 10;
		if (x == Ar[N - 1]) {
			k++;
		}
		N--;
		return Korovu(Ar, N, C /= 10, k);
}

int Chislo(int Ar[], int N)
{
	int K = 1000, Sum = 0, C = 0;
	for (int i = 0; i < N; i++) {
		C = Ar[i] * K;
		Sum += C;
		K /= 10;
	}
	return Sum;
}

int Porivnanna(int Ar[], int N, int x, int b)
{
	int j = 0;
	while (true) {
		if (j == N - 1)break;
		if (x == Ar[j]) {
			b++;
			return b;
		}
		j++;
	}
	return b;
}
