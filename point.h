#ifndef POINT_H
#define POINT_H

#include <iostream>



template<typename type = int> 
struct Point
{
public:
	type x;
	type y;


	Point(type x=0,type y=0): x(x), y(y) {} //konstruktor

	bool operator ==(const Point pnt2) const { return(this->x == pnt2.x && this->y == pnt2.y); }

};


#endif
