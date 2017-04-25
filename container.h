#ifndef CONTAINER_H
#define CONTAINER_H

#include "rectangle.h"




template <class type = int>
class Container
{
private:
	unsigned limit;  //maxymalna pojemnosc bufora
	unsigned position; //indeks aktualnej pozycji bufora
	unsigned amount;
	Rect<type>* bufor;

public:
	Container(int lim = 4) : limit(lim), position(0), amount(0) { bufor = new Rect<type>[limit]; }//konstruktor
	~Container() { delete bufor; }

	Container& operator += (const Rect<type> &rect); //dodaje nowy prostokat
	Rect<type>& operator [] (int n); //zwraca referencje elementu liczac od najstarszego modulo ilosc dodanych elementow
	const Rect<type>& operator [] (int n) const;
	Container& add(const Rect<type> &rect); //dodaje nowy prostokat
	void resize(unsigned lim); //zmienia maxymalny rozmiar, jesli nowy rozmiar jest wiekszy to tylko zwieksza limit, jesli jest mniejszy to usuwa nadmiarowe elementy
	void remove(unsigned n);

	Rect<type> border() const;

	unsigned size() const { return amount; }
	unsigned max() const { return limit; }




};
//*************************IMPLEMENTATION

template <class type>
Container<type>& Container<type>::operator +=(const Rect<type>& rect)
{

	(*this).add(rect);


	return *this;
}

template <class type>
Container<type>& Container<type>::add(const Rect<type>& rect)
{
	bufor[position] = rect;
	++position;
	position %= limit;

	if (amount < limit)
		amount++;

	return *this;
}

template<class type>
Rect<type>& Container<type>::operator [] (int n) 
{
	 if (amount == limit)
		 return bufor[(n + position) % amount]; 
	 else 
		 return bufor[n % amount];  

}

template<class type>
const Rect<type>& Container<type>::operator [] (int n) const
{
	if (amount == limit)
		return bufor[(n + position) % amount];
	else
		return bufor[n % amount];
}

template<class type>
void Container<type>::resize(unsigned lim)
{

	Rect<type>* holder = new Rect<type>[lim];

	for (unsigned i = 0; i < lim && i < amount; i++)
	{
		holder[i] = (*this)[i];
	}
	delete bufor;
	limit = lim;
	if (amount >= lim) //zmniejszamy wiec ilosc staje sie limitem, a pozycja jest liczona od 0, bo przepisujemy tablice poczawszy od najstarszego
	{
		amount = lim;
		position = 0;
	}
	else
	{
		position = amount; //jesli powiekszamy, to element po ostatnim staje sie pozycja
	}
	bufor = holder;

}

template<class type> // 0 1 2x 3 4 <- 5 6 7 8 9 // 0 1 2 3 4 5 6 7 8 X
inline void Container<type>::remove(unsigned n)
{
	if (amount == 0)
		return;
	unsigned index;
	if (amount < limit)
		index = n % amount;
	else
		index = (n + position) % amount;

	Rect<type>* holder = new Rect<type>[limit]; //pomocnicza tablica
	unsigned j = position;
	for (unsigned i = 0; i < amount-1; i++, j++) //przepisywanie tablicy w odpowiedniej kolejnosci bez usuwanego elementu
	{
		j = j % amount;
		if (j == index) //jesli natrafiamy na usuwany element to go pomijamy
			j++;

		holder[i] = bufor[j];
	}
	delete bufor;
	bufor = holder;
	--amount;
	position = amount;

}

template<class type>
Rect<type> Container<type>::border() const//zwraca maxa ze wszystkich moze zmienic na wydajniejsza funkcje?
{
	if (amount == 0)
		return Rect<type>({ {0,0},{0,0} });

	Rect<type> border(bufor[0]);
	for (unsigned i = 1; i < amount; i++)
	{
		border += bufor[i];
	}
	return border;
}


template<class type>
inline std::ostream & operator<< (std::ostream & str, const Container<type>& cont)
{
	for (unsigned i = 0; i < cont.size(); i++)
	{
		str << i+1 << ". " << cont[i] << std::endl;
	}
	return str;
}
#endif