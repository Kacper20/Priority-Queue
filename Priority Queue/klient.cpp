/*
***Kacper Harasim
*** Projekt 1
*** Klient dla implementacji kolejki priorytetowej
*** Data oddania: 13.03.2014r.
*/

#include "Pqueue.h"
#include <iostream>
#include <climits>
#include <fstream>
void test(void);
void z_pliku(void);
void wlasna(void);
int main()
{
	std::cout << "Witaj w kliencie kolejki priorytetowej!\n";
	std::cout << "\t1 - Stworz wlasna kolejke\n";
	std::cout << "\t2 - Wczytaj kolejke z pliku\n";
	std::cout << "\t3 - Uruchom test laczacy kolejki\n";
	std::cout << "\t4 - Zakoncz\n";
	while (1)
	{
		int wybor;
		std::cin >> wybor;
		switch (wybor)
		{
		case 1:
			wlasna();
			break;
		case 2:
			z_pliku();
			break;
		case 3:
			test();
			break;
		case 4:
			return 0;
			break;
		}
		std::cout << "\n";
		std::cout << "\t1 - Stworz wlasna kolejke\n";
		std::cout << "\t2 - Wczytaj kolejke z pliku\n";
		std::cout << "\t3 - Uruchom test laczacy kolejki\n";
		std::cout << "\t4 - Zakoncz\n";

	}


}
void wlasna(void)
{
	int help_value;
	std::cout << "Podaj rozmiar kolejki, ktora chcesz utworzyc:\n";
	int wielkosc;
	std::cin >> wielkosc;
	Pqueue kol(wielkosc);
	std::cout << "Zostala utworzona kolejka o maksymalnym rozmiarze " << wielkosc << std::endl;
	int wyb = 0;
	while (wyb != 10)
	{
		std::cout << "1 - Wstaw do kolejki z priorytetem \t 2 - Sprawdz aktualny rozmiar\n";
		std::cout << "3 - Sprawdz czy pusta \t 4 - Czy pelna";
		std::cout << "\t5 - Usun maks element\n";
		std::cout << "6 - Czytaj maks\t 10 - Powrot\n";
		std::cin >> wyb;
		switch (wyb)
		{
		case 1:
			if (kol.ifFull())
			{
				std::cout << "Kolejka pelna, zastepujemy element o min priorytecie";
			}
			std::cout << "Podaj priorytet elementu\n";
			int prio;
			std::cin >> prio;
			std::cout << "Podaj wartosc elementu\n";
			int val;
			std::cin >> val;
			kol.insert(prio, val);
			std::cout << "\n";
			std::cout << "Maksymalny element to " << kol.max() << std::endl;
			std::cout << "Obecny rozmiar to " << kol.size() << std::endl;
			std::cout << "\n";
			break;
		case 2:
			std::cout << "Rozmiar kolejki wynosi " << kol.size() << std::endl;
			std::cout << "\n";
			break;

		case 3:
			if (kol.ifEmpty())
				std::cout << "Kolejka jest pusta\n\n";
			else
				std::cout << "Kolejka posiada elementy\n\n";
			break;
		case 4:
			if (kol.ifFull())
				std::cout << "Kolejka jest pelna\n\n";
			else
				std::cout << "Kolejka posiada wolne miejsca \n\n";
			break;
		case 5:
			help_value = kol.deleteMax();
			if (help_value == INT_MIN)
				std::cout << "Kolejka jest pusta, nie mozna niczego usunac\n\b";
			else
			{
				std::cout << "Usuniety zostal element " << help_value << std::endl;
				std::cout << "\n";
				if (kol.size() != 0)
					std::cout << "Maksymalny element to " << kol.max() << std::endl;
				std::cout << "Obecny rozmiar to " << kol.size() << std::endl;
				std::cout << "\n";
			}
		case 6:
			if (kol.size() == 0)
				std::cout << "Kolejka jest pusta, nie posiada maksymalnego elementu\n";
			else
				std::cout << "Maksymalny element to " << kol.max() << std::endl;

			break;

		case 10:
			return;
			break;
		}
	}
}
void test(void)
{
	std::cout << "Blok testowy\n";
	Pqueue k1(10);
	Pqueue k2(10);
	std::cout << "Kolejka 1 to priorytety : 0, 1, ..., 9\n";
	std::cout << "Kolejka 2 to priorytety : 10, 11, ..., 19\n";
	std::cout << "Wartosci elementow sa takie same jak priorytety\n";
	for (int i = 0; i<10; i++)
		k1.insert(i, i);
	for (int i = 10; i<20; i++)
		k2.insert(i, i);
	std::cout << "Maksymalny element kolejki 1 to " << k1.max() << "\nMa ona w tej chwili " << k1.size() << " elementow\n";
	std::cout << "Maksymalny element kolejki 2 to " << k2.max() << "\nMa ona w tej chwili " << k2.size() << " elementow\n";
	std::cout << "Za pomoca przeciazenia operatorow dodajemy 2 kolejke do 1\n";
	Pqueue suma = k1 + k2;
	std::cout << "maksymalny element teraz to " << suma.max() << "\nMa ona w tej chwili " << suma.size() << " elementow\n";
	std::cout << "Usuwamy maksymalny element...\n";
	suma.deleteMax();
	std::cout << "Teraz maksymalny element to " << suma.max() << " a rozmiar obecny kolejki to " << suma.size() << std::endl;
	std::cout << "\nTEST ZAKONCZONY\n";
}

void z_pliku(void)
{

	int help_value;
	Pqueue kol(200); // nowa kolejka
	int klucz;
	int wartosc;
	std::fstream plik;
	plik.open("test");

	while (plik >> klucz)
	{
		plik >> wartosc;
		kol.insert(klucz, wartosc);
	}
	std::cout << "Zostala utworzona kolejka o maksymalnym rozmiarze 200" << std::endl;
	int wyb = 0;
	while (wyb != 10)
	{
		std::cout << "1 - Wstaw do kolejki z priorytetem \t 2 - Sprawdz aktualny rozmiar\n";
		std::cout << "3 - Sprawdz czy pusta \t 4 - Czy pelna";
		std::cout << "\t5 - Usun maks element\n";
		std::cout << "6 - Czytaj maks\t 10 - Powrot\n";
		std::cin >> wyb;
		switch (wyb)
		{
		case 1:
			if (kol.ifFull())
			{
				std::cout << "Kolejka pelna, zastepujemy element o min priorytecie\n";
			}
			std::cout << "Podaj priorytet elementu\n";
			int prio;
			std::cin >> prio;
			std::cout << "Podaj wartosc elementu\n";
			int val;
			std::cin >> val;
			kol.insert(prio, val);
			std::cout << "\n";
			std::cout << "Maksymalny element to " << kol.max() << std::endl;
			std::cout << "Obecny rozmiar to " << kol.size() << std::endl;
			std::cout << "\n";
			break;
		case 2:
			std::cout << "Rozmiar kolejki wynosi " << kol.size() << std::endl;
			std::cout << "\n";
			break;

		case 3:
			if (kol.ifEmpty())
				std::cout << "Kolejka jest pusta\n\n";
			else
				std::cout << "Kolejka posiada elementy\n\n";
			break;
		case 4:
			if (kol.ifFull())
				std::cout << "Kolejka jest pelna\n\n";
			else
				std::cout << "Kolejka posiada wolne miejsca \n\n";
			break;
		case 5:
			help_value = kol.deleteMax();
			if (help_value == INT_MIN)
				std::cout << "Kolejka jest pusta, nie mozna niczego usunac\n";
			else
			{
				std::cout << "Usuniety zostal element " << help_value << std::endl;
				std::cout << "\n";
				if (kol.size() != 0)
					std::cout << "Maksymalny element to " << kol.max() << std::endl;
				std::cout << "Obecny rozmiar to " << kol.size() << std::endl;
				std::cout << "\n";
			}
			break;

		case 10:
			return;
			break;
		}
	}
}


