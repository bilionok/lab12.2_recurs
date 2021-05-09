#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int Info; // створення псевдоніму типу

struct Elem
{
	Elem* link;
	Info info;
};

void enqueue(Elem*& first, Elem*& last, Info k, Info numb);
void check(Elem* first, Info& k);
void dequeue(Elem*& first, Elem*& last);

int main()
{
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
	srand((unsigned)time(NULL));
	Elem* first = NULL,
		* last = NULL;

	enqueue(first, last, 1, 10);

	Info k = 0;
	cout << "Непарні елементи: ";
	check(first, k); // Опрацювання черги
	cout << endl << endl;
	cout << "В списку є " << k << " непарних елементів";
	cout << endl << endl;
	cout << "Черга: ";
	dequeue(first, last); // Вивід та видалення черги
	cout << endl;

	return 0;
}
void enqueue(Elem*& first, Elem*& last, Info k, Info numb)
{
	Info num = 1 + rand() % 10;
	Elem* tmp = new Elem;
	tmp->info = num;
	tmp->link = NULL;
	if (last != NULL)
		last->link = tmp;
	last = tmp;
	if (first == NULL)
		first = tmp;
	if (k < numb) {
		k++;
		enqueue(first, last, k, numb);
	}

}

void dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->link;
	Info value = first->info;
	delete first;
	first = tmp;
	if (first == NULL)
		last = NULL;
	cout << value << " ";
	if (last != NULL) {
		dequeue(first, last);
	}
}

void check(Elem* first, Info& k)
{
	if (first != NULL) {
		if (first->info % 2 != NULL) {
			cout << first->info << " ";
			k++;
		}
		first = first->link;
		check(first, k);
	}
}