#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
public:
	int x;
	int y;


	Point(int x=0,int y=0): x(x), y(y) {} //konstruktor

//	Point& operator =(int tab[2]) { x = tab[0]; y = tab[1]; return *this;}
	bool operator ==(const Point pnt2) const { return(this->x == pnt2.x && this->y == pnt2.y); }
//	bool operator ==(const int tab[2]) const { return (this->x == tab[0] && this->y == tab[1]);} //testowy //za dluga return warunek moze byc

};


#endif
