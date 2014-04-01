
/*
***Kacper Harasim
*** Projekt 1
*** Definicje metod klasy PQueue
*** Data oddania: 13.03.2014r.
*/
#include <iostream>
#include "Pqueue.h"
#include <climits>
void Pqueue::fixUp(int k) // Naprawiamy w górê. k to indeks tablicy
{
	while (k > 1 && less(k / 2, k))
	{
		swap(k, k / 2);
		k = k / 2;
	}
}
void Pqueue::fixDown(int k) // Naprawiamy w dó³.
{

	while (2 * k <= N)
	{
		int i = 2 * k;
		if (i < N && less(i, i + 1))
			i++;
		if (!less(k, i))
			break;
		swap(k, i);
		k = i;
	}
}
void Pqueue::swap(int a, int b) // Zamieniamy miejscami dwie struktury
{
	item temp = pq[a];
	pq[a] = pq[b];
	pq[b] = temp;
}
bool Pqueue::less(int a, int b)
{
	if (pq[a].key < pq[b].key)
		return true;
	else if (pq[a].key == pq[b].key && pq[a].eld > pq[b].eld)
		return true;
	else
		return false;
}
void Pqueue::build_max_heap()
{
	for (int k = N / 2; k >= 1; k--)
		fixDown(k);
}
Pqueue::Pqueue(int size) // Skoñczona. Ew. b³êdy obs³u¿yæ!
{
	max_size = size;
	pq = new item[max_size + 1]; // Tworzymy tablicê struktur o rozmiarze max_size.
	N = 0;
	low_bound = 85;
	upp_bound = 95;
}

Pqueue::~Pqueue() // Skoñczony. 
{
	delete[] pq;
}
bool Pqueue::ifEmpty()
{
	return N == 0;
}
bool Pqueue::ifFull()
{
	return N == max_size;
}
void Pqueue::insert(int key, int value)
{
	if (N != max_size)
	{
		pq[++N].key = key;
		pq[N].eld = max_eld++;
		pq[N].value = value;
		fixUp(N); // przekazujemy aktualny rozmiar kolejki pqueue. Dodalismy na koniec. 
	}
	else
	{
		//std::cout <<"Nie mozna wykonac - kolejka nie posiada wolnych miejsc";
		std::cout << "Element zostanie nadpisany za element z minimalnym priorytetem";
		swap_with_min(key, value);
	}
}
int Pqueue::deleteMax()
{
	if (N != 0)
	{
		int max = pq[1].value;
		swap(1, N--);
		fixDown(1);
		return max;
	}
	else
		return INT_MIN;
}

int Pqueue::max()
{
	if (N != 0)
		return pq[1].value;
	else
		return INT_MIN;

}
int Pqueue::size() // Skoñczony
{
	return N;
}
int Pqueue::msize()
{
	return max_size;
}

// Zwraca prawdê jeœli 1 element jest mniejszy od drugiego. 
void Pqueue::change_up(int val)
{
	if (val>0 && val <= 100 && val>low_bound);
	upp_bound = val;
}
void Pqueue::change_low(int val)
{
	if (val >= 0 && val < 100 && val < upp_bound);
	low_bound = val;
}
int Pqueue::check_up()
{
	int ratio = 100 * (N) / (upp_bound);
	return ratio;
}
int Pqueue::check_low()
{
	int ratio = 100 * (N) / (low_bound);
	return ratio;
}


Pqueue Pqueue::operator +(Pqueue &cq)
{
	int key;
	int val;
	int zakres_n = this->N;
	int zakres_m = cq.N;
	const int new_size = this->max_size + cq.max_size;
	Pqueue newqueue(new_size); // tworzymy nowy obiekt. 
	std::cout << "Nowy rozmiar wyniosl " << new_size << std::endl;
	for (int i = 1; i <= (zakres_n); i++)
	{
		key = this->pq[i].key;
		val = this->pq[i].value;
		newqueue.insert(key, val);
	}
	for (int i = 1; i <= zakres_m; i++)
	{
		key = cq.pq[i].key;
		val = cq.pq[i].value;
		newqueue.insert(key, val);
	}
	return newqueue;
}

void Pqueue::swap_with_min(int key, int value)
{
	std::cout << "Brak miejsc - usuniety zostanie element o minimalnym priorytecie\n";
	int min = pq[1].key; // pierwszy
	int min_i;
	for (int i = 1; i <= N; i++) // W bloku szukamy elementu o minimalnym priorytecie.
	{
		if (pq[i].key < min)
		{
			min = pq[i].key;
			min_i = i; // indeks minimalnego elementu
		}
	}
	pq[min_i].key = key;
	pq[min_i].value = value; // Zmiana wartosci
	fixUp(min_i);
}


//FORMAT WCZYTYWANIA Z PLIKU:
//priorytet1_wartosc1:priorytet2_wartosc2: itd.


