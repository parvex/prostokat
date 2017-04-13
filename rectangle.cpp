#include "rectangle.h"

using namespace std;
////////////////////////////////////
Rect::Rect(Point pnt1, Point pnt2)  //wpisanie wspolrzednych prostokata w odpowiedniej kolejnosci - prawy gorny topleft, lewy dolny - bottomright
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
////////////////////////////////////////!@#!@#!@#!@
Rect& Rect::operator +=(const Rect &rect2) //wpisywanie skrajnych wartosci do wspolrzednych prostokata sumy
{

	this->topleft.y = (this->topleft.y > rect2.topleft.y) ? (this->topleft.y) : (rect2.topleft.y);
	this->topleft.x = (this->topleft.x < rect2.topleft.x) ? (this->topleft.x) : (rect2.topleft.x);
	this->bottomright.y = (this->bottomright.y < rect2.bottomright.y) ? (this->bottomright.y) : (rect2.bottomright.y);
	this->bottomright.x = (this->bottomright.x > rect2.bottomright.x) ? (this->bottomright.x) : (rect2.bottomright.x);

	return (*this);
}
//////////////////////////////////////////////////!@#!!!!!!!!!
Rect Rect::operator +(const Rect &rect2) const //wpisywanie skrajnych wartosci do wspolrzednych prostokata sumy
{
	Rect sum = *this;
	sum += rect2;

    return sum;

}
////////////////////////////////////////
bool Rect::encloses(const Point &pnt) const//zawiera punkt jesli punkt znajduje sie pomiedzy wszystkimi skrajnymi punktami lezacy na boku nie nalezy
{
	return (pnt.x > topleft.x && pnt.x < bottomright.x && pnt.y > bottomright.y && pnt.y < topleft.y);
}
////////////////////////////////////////
Rect& Rect::operator -=(const Rect &rect2)
{

	//dobieramy przedzial x

	this->topleft.x = (this->topleft.x > rect2.topleft.x) ? (this->topleft.x) : (rect2.topleft.x);
	this->bottomright.x = (this->bottomright.x < rect2.bottomright.x) ? (this->bottomright.x) : (rect2.bottomright.x);

	if (this->topleft.x >= this->bottomright.x)
	{
		(*this) = { { 0,0 }, {0,0} };									//zwracamy prostokat pusty jesli przedzial jest pusty														//przedzial y
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
Rect Rect::operator -(const Rect &rect2) const
{
	Rect substract = *this;
	substract -= rect2;

	return substract;  //jesli istnieje czesc wspolna beda to wspolrzedne tego prostokata - moze byc to rowniez punkt
}
/////////////////////////////////////
bool Rect::encloses(const Rect &rect2) const // do poprawienia!!!!!!!! - powinno dzialac
{
	return (topleft.x <= rect2.topleft.x && topleft.y >= rect2.topleft.y && bottomright.x >= rect2.bottomright.x && bottomright.y <= rect2.bottomright.y); //zawiera sie gdy wszystkie wspolrzedne sie nie przekraczaja // mozna skrocic do jednego returna
}
////////////////////////////////////
bool Rect::crosses(const Rect &rect2) const//jak lezy w srodku to tez przecina, zmienic?
{
	Rect sub = (*this) - rect2;
	return (!(sub.topleft.x == sub.bottomright.x || sub.topleft.y == sub.bottomright.y)); //jesli prostokat czesci wspolnej jest pusty to nie precinaja sie
}

