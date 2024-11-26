/*1. Написати функцію, що реалізує алгоритм лінійного пошуку заданого ключа в одновимірному масиві.
2. Написати функцію, що реалізує алгоритм бінарного пошуку заданого ключа в одновимірному масиві.
3. Написати перевантажені функції (int, double, char) для виконання таких завдань:
■ Ініціалізація квадратної матриці;
■ Вивід матриці на екран;
■ Визначення максимального й мінімального елемента на головній діагоналі матриці;
■ Сортування елементів за зростанням окремо для кожного рядка матриці.
4. Написати рекурсивну функцію знаходження найбільшого спільного дільника двох цілих чисел.
5. Написати гру «Бики та корови». Програма «загадує» чотиризначне число і гравець має вгадати його.
Після введення користувачем числа програма повідомляє, скільки цифр числа вгадано (бики) і 
скільки цифр вгадано і стоїть на потрібному місці (корови). 
Після відгадування числа на екран необхідно вивести кількість зроблених користувачем спроб. 
У програмі необхідно використовувати рекурсію.*/
#include "Zagalne.h"
#include "Zadacha1.h"
#include "Zadacha2.h" 
#include "Zadacha3.h"
#include "Zadacha4.h"
#include "Zadacha5.h"

using namespace std;

void Random()
{
	srand(time(NULL));
}

void Randomnui_masuv(int Ar[], int N)
{
	Random();
	for (int i = 0; i < N; i++) {
		Ar[i] = rand() % 50 - 25;
	}
}

void Show_masuv(int Ar[], int N)
{
	for (int i = 0; i < N; i++) {
		Show(Ar[i]);
		Show(' ');
	}
	Show('\n');
}

void Switch_zadach(int N)
{
	switch (N) {
	case 1:Liniinui_posuk(); break;
	case 2:Binarnui_posyk(); break;
	case 3:Matruca(); break;
	case 4:Spilnui_dilnuk(); break;
	case 5:Gra(); break;
	case 6:break;
	default: Default;
	}
}

void Vubir_zadachi()
{
	cout << "Oberite zadachy:\n"
		<< "1. Liniinui posuk\n"
		<< "2. Binarnui posyk\n"
		<< "3. Matruca\n"
		<< "4. Spilnui dilnuk\n"
		<< "5. Gra \"Buku ta korovu\"\n"
		<< "6. Vuhid\n";
}
