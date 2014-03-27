/*
***Kacper Harasim
*** Projekt 1
*** Deklaracja klasy PQueue
*** INFO:
/ Implementacja oparta jest na kopcu binarnym. Wszystkie operacje poza ³¹czeniem kolejek odbywaj¹ siê w czasie O(lgN) gdzie N jest wielkoœci¹ kopca.
/ Operacja po³¹czenia(zdefiniowana w funkcji operatorowej +) jest zrealizowana w czasie O(N).
*** Data oddania: 13.03.2014r.
*/
class Pqueue
{
private:
	struct item{
		int key;
		int value;
	};
	int max_size; // Maksymalny rozmiar dla ktorego tworzona jest kolejka
	int N; // Aktualny rozmiar kolejki
	int low_bound = 85;
	int upp_bound = 95;
	item *pq; // wskaznik na struktury
	void fixUp(int k); // Kopcuje w dó³
	void fixDown(int k); // Naprawia kopcowanie w górê
	void swap(int a, int b); // Pomocnicza do zmieniania wartoœci
	bool less(int a, int b);
	void build_max_heap(); // Tworzy maksymalny kopiec. 
	void swap_with_min(int key, int value); // funkcja zamienia element wkladany z elementem o najmniejszym priorytecie(wyrzuca go z kolejki)
public:
	Pqueue(int size = 40);
	Pqueue(const int tab[], int rozmiar);
	~Pqueue();
	bool ifEmpty(); // Sprawdza czy kolejka jest pusta
	bool ifFull(); // Sprawdza czy jest pe³na.
	void insert(int key, int value);
	int deleteMax(); // Usuwa element o maksymalnym priorytecie i zwraca jego wartosc. 
	int max(); // Zwraca wartosc elementu o maksymalnym priorytecie. 
	int size(); // Zwraca rozmiar kolejki. 
	int msize(); // Zwraca pojemnosc kolejki. 
	void change_up(int val); // Zmienia upp bound kolejki
	void change_low(int val); // Zmienia low bound kolejki
	int check_up(); // Zwraca stosunek akt rozmiar/upp bound w procentach
	int check_low();	// Zwraca stosunek akt rozmiar/low bound w procentach 
	Pqueue operator +(Pqueue &cq); // Przeci¹¿ony operator dodawania.

};
