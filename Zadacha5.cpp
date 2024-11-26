/*5. Написати гру «Бики та корови». Програма «загадує» чотиризначне число і гравець має вгадати його.
Після введення користувачем числа програма повідомляє, скільки цифр числа вгадано (бики) і
скільки цифр вгадано і стоїть на потрібному місці (корови).
Після відгадування числа на екран необхідно вивести кількість зроблених користувачем спроб.
У програмі необхідно використовувати рекурсію.*/
#include "Zadacha5.h"
#include "Windows.h"
using namespace std;
void Zagadane_chislo(int Ar[], int N);
int Buku(int Ar[], int N, int C, int b);
int Korovu(int Ar[], int N, int C, int k);
int Chislo(int Ar[], int N, int Ch, int R);
int Porivnanna(int Ar[], int N, int K);

void Gra()
{
	Random();
	const int N = 4;
	int Ar[N];
	int Ch = 0, R = 1, b = 0, k = 0, a = 0;
	cout << "Maemo zagadane chislo: ";
	Zagadane_chislo(Ar, N);
	int K = Chislo(Ar, N, Ch, R);
	Show(K);
	Show('\n');
	a = Porivnanna(Ar, N, K);
}

void Zagadane_chislo(int Ar[], int N)
{
	if (N == 0)return;
	Ar[N - 1] = rand() % 8 + 1;
	Zagadane_chislo(Ar, N-1);
}

int Buku(int Ar[], int N, int C, int b)
{
	int x, i = 0, k = 0, n = 0;
	const int N2 = 4;
	int Ar2[N2];
	

	while (true) {
		if (i == N)break;
		x = C % 10;
		C /= 10;
		int r = 0;
		while (true) {
			if (r == N2)break;
			if (Ar2[r] == x) {
				n++;
			}
			r++;
		}
		if (n != 0) {
			n = 0;
			continue;
		}
		int j = 0;
		while (true) {
			if (j == N)break;
			if (Ar[j] == x) {
				Ar2[k] = Ar[j];
				b++;
				k++;
			}
			j++;
		}
		i++;
	}
	return b;
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

int Chislo(int Ar[], int N, int Ch, int R)
{
	if (N == 0)return Ch;
	Ch += Ar[N - 1] * R;
	return Chislo(Ar, N - 1, Ch, R * 10);
}

int Porivnanna(int Ar[], int N, int K)
{
		int b = 0, k = 0, a = 0;
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
		if (K == a)return a;
	return Porivnanna(Ar, N, K);
}
