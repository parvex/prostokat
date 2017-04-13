#ifndef RECT_H
#define RECT_H
#include "point.h"


class Rect
{
private:
	Point topleft;  //lewy gorny rog prostokata
	Point bottomright;  //prawy dolny rog prostokata

public:

    //konstruktory

	Rect() : topleft({ 0,0 }), bottomright({ 0,0 }) {}
	Rect(Point pnt1, Point pnt2);
	Rect(const Rect &rect) { topleft = rect.topleft; bottomright = rect.bottomright; }


	Rect& operator =(const Rect &rect2) { topleft = rect2.topleft; bottomright = rect2.bottomright; return *this; } //operator =
	Rect operator +(const Rect &rect2) const; //funkcja zwraca prostokat zawierajacy obydwa prostokaty uwaga sprawdzic czy nie zmienilo po sumowaniu
	Rect operator -(const Rect &rect2) const; //zwraca prostokat czesci wspolnej
	Rect& operator +=(const Rect &rect2);
	Rect& operator -=(const Rect &rect2);
	bool operator ==(const Rect &rect2) const { return this->topleft == rect2.topleft && this->bottomright == rect2.bottomright; } // to na pewno skrocic


	Point gettopleft() const {return topleft;}
   	Point getbottomright() const {return bottomright;}
	bool encloses(const Point &pnt) const; //zawiera punkt
	bool encloses(const Rect &rect2) const; //zawiera inny prostokat
	bool crosses(const Rect &rect2) const;  //przecina inny prostokat - razem z zawieraniem

};

#endif
