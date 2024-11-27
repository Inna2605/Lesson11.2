/*5. Написати гру «Бики та корови». Програма «загадує» чотиризначне число і гравець має вгадати його.
Після введення користувачем числа програма повідомляє, скільки цифр числа вгадано (бики) і
скільки цифр вгадано і стоїть на потрібному місці (корови).
Після відгадування числа на екран необхідно вивести кількість зроблених користувачем спроб.
У програмі необхідно використовувати рекурсію.*/
#include "Zadacha5.h"
#include "Windows.h"
using namespace std;
void Zagadane_chislo(int Ar[], int N);
int Buku(int Ar[], int Ar2[], int N, int C, int b);
int Korovu(int Ar[], int N, int C, int k);
int Chislo(int Ar[], int N, int Ch, int R);
int Porivnanna(int Ar[], int N, int K);
int Posyk_cifru(int Ar2[], int N, int x, int r);
int Kilkist_cifr(int Ar[], int Ar2[], int N, int x, int b);

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

int Buku(int Ar[], int Ar2[], int N, int C, int b)
{
	if (C == 0)return b;
	int x = C % 10;

	int r = Posyk_cifru(Ar2, N, x, 0);

	if (r != 0) {
		return Buku(Ar, Ar2, N, C / 10, b);
	}
	b = Kilkist_cifr(Ar, Ar2, N, x, b);

	return Buku(Ar, Ar2, N, C / 10, b);
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
	const int N2 = 4;
	int Ar2[N2]{ 0 };
	int b = 0, k = 0, a = 0;
	cout << "Vvedite choturuznachne chuslo: ";
	Vvod(a);
	b = Buku(Ar, Ar2, N, a, b);
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

int Posyk_cifru(int Ar2[], int N, int x, int r)
{
	if (N == 0)return r;
	if (Ar2[N - 1] == x) {
		r++;
	}
	return Posyk_cifru(Ar2, N - 1, x, r);
}

int Kilkist_cifr(int Ar[], int Ar2[], int N, int x, int b)
{
	if (N == 0)return b;
	if (Ar[N - 1] == x) {
		Ar2[b] = Ar[N - 1];
		b++;
	}
	return Kilkist_cifr(Ar, Ar2, N - 1, x, b);
}
