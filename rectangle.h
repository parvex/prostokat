#ifndef RECT_H
#define RECT_H
#include "point.h"


template<class type = int> 
class Rect
{
private:
	Point<type> topleft;  //lewy gorny rog prostokata
	Point<type> bottomright;  //prawy dolny rog prostokata

public:

    //konstruktory

	Rect() : topleft({ 0,0 }), bottomright({ 0,0 }) {}
	Rect(Point<type> pnt1, Point<type> pnt2);
	Rect(const Rect &rect) : topleft(rect.topleft), bottomright(rect.bottomright) {}


	Rect& operator =(const Rect &rect2) { topleft = rect2.topleft; bottomright = rect2.bottomright; return *this; } //operator =
	Rect operator +(const Rect &rect2) const; //funkcja zwraca prostokat zawierajacy obydwa prostokaty uwaga sprawdzic czy nie zmienilo po sumowaniu
	Rect operator -(const Rect &rect2) const; //zwraca prostokat czesci wspolnej
	Rect& operator +=(const Rect &rect2);
	Rect& operator -=(const Rect &rect2);
	bool operator ==(const Rect &rect2) const { return this->topleft == rect2.topleft && this->bottomright == rect2.bottomright; } // to na pewno skrocic
	template<class U>
	friend std::ostream& operator<<(std::ostream& str, const Rect<U>& rect);


	const Point<type>& gettopleft() const {return topleft;}
   	const Point<type>& getbottomright() const {return bottomright;}
	bool encloses(const Point<type> &pnt) const; //zawiera punkt
	bool encloses(const Rect &rect2) const; //zawiera inny prostokat
	bool crosses(const Rect &rect2) const;  //przecina inny prostokat - razem z zawieraniem

};

//////////////////////////////////// IMPLEMENTATION
template<class type> 
Rect<type>::Rect(Point<type> pnt1, Point<type> pnt2)  //wpisanie wspolrzednych prostokata w odpowiedniej kolejnosci - prawy gorny topleft, lewy dolny - bottomright
{
	if (pnt1.y > pnt2.y)
	{
		topleft.y = pnt1.y;
		bottomright.y = pnt2.y;
	}
	else
	{
		bottomright.y = pnt1.y;
		topleft.y = pnt2.y;
	}

	if (pnt1.x > pnt2.x)
	{
		bottomright.x = pnt1.x;
		topleft.x = pnt2.x;
	}
	else
	{
		topleft.x = pnt1.x;
		bottomright.x = pnt2.x;
	}

}
////////////////////////////////////////////////////////////
template<class type>
Rect<type>& Rect<type>::operator +=(const Rect<type> &rect2) //wpisywanie skrajnych wartosci do wspolrzednych prostokata sumy
{

	this->topleft.y = (this->topleft.y > rect2.topleft.y) ? (this->topleft.y) : (rect2.topleft.y);
	this->topleft.x = (this->topleft.x < rect2.topleft.x) ? (this->topleft.x) : (rect2.topleft.x);
	this->bottomright.y = (this->bottomright.y < rect2.bottomright.y) ? (this->bottomright.y) : (rect2.bottomright.y);
	this->bottomright.x = (this->bottomright.x > rect2.bottomright.x) ? (this->bottomright.x) : (rect2.bottomright.x);

	return (*this);
}
//////////////////////////////////////////////////!@#!!!!!!!!!
template<class type>
Rect<type> Rect<type>::operator +(const Rect<type> &rect2) const //wpisywanie skrajnych wartosci do wspolrzednych prostokata sumy
{
	Rect sum = *this;
	sum += rect2;

	return sum;

}
////////////////////////////////////////
template<class type>
bool Rect<type>::encloses(const Point<type> &pnt) const//zawiera punkt jesli punkt znajduje sie pomiedzy wszystkimi skrajnymi punktami lezacy na boku nie nalezy
{
	return (pnt.x > topleft.x && pnt.x < bottomright.x && pnt.y > bottomright.y && pnt.y < topleft.y);
}
////////////////////////////////////////
template<class type>
Rect<type>& Rect<type>::operator -=(const Rect<type> &rect2)
{

	//dobieramy przedzial x

	this->topleft.x = (this->topleft.x > rect2.topleft.x) ? (this->topleft.x) : (rect2.topleft.x);
	this->bottomright.x = (this->bottomright.x < rect2.bottomright.x) ? (this->bottomright.x) : (rect2.bottomright.x);

	if (this->topleft.x >= this->bottomright.x)
	{
		(*this) = { { 0,0 },{ 0,0 } };									//zwracamy prostokat pusty jesli przedzial jest pusty														//przedzial y
		return (*this);
	}

	this->topleft.y = (this->topleft.y < rect2.topleft.y) ? (this->topleft.y) : (rect2.topleft.y);
	this->bottomright.y = (this->bottomright.y > rect2.bottomright.y) ? (this->bottomright.y) : (rect2.bottomright.y);

	if (this->bottomright.y >= this->topleft.y)
	{
		(*this) = { { 0,0 },{ 0,0 } };									//zwracamy prostokat pusty jesli przedzial jest pusty														//przedzial y
		return (*this);
	}

	return (*this);  //jesli istnieje czesc wspolna beda to wspolrzedne tego prostokata - moze byc to rowniez punkt
}
///////////////////////////////////////!@#!@#!@#!@
template<class type>
Rect<type> Rect<type>::operator -(const Rect<type> &rect2) const
{
	Rect substract = *this;
	substract -= rect2;

	return substract;  //jesli istnieje czesc wspolna beda to wspolrzedne tego prostokata - moze byc to rowniez punkt
}
/////////////////////////////////////
template<class type>
bool Rect<type>::encloses(const Rect<type> &rect2) const // do poprawienia!!!!!!!! - powinno dzialac
{
	return (topleft.x <= rect2.topleft.x && topleft.y >= rect2.topleft.y && bottomright.x >= rect2.bottomright.x && bottomright.y <= rect2.bottomright.y); //zawiera sie gdy wszystkie wspolrzedne sie nie przekraczaja // mozna skrocic do jednego returna
}
////////////////////////////////////
template<class type>
bool Rect<type>::crosses(const Rect<type> &rect2) const//jak lezy w srodku to tez przecina, zmienic?
{
	Rect sub = (*this) - rect2;
	return (!(sub.topleft.x == sub.bottomright.x || sub.topleft.y == sub.bottomright.y)); //jesli prostokat czesci wspolnej jest pusty to nie precinaja sie
}
/////////////////////////////////
template<class type = int>
inline std::ostream& operator<<(std::ostream& str, const Rect<type>& rect)
{
	str << '[' << rect.bottomright << ", " << rect.topleft << ']';
	return str;
}
#endif
