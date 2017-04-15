#ifndef POINT_H
#define POINT_H

#include <iostream>

template<class type> 
struct Point;

template<class type = int>
std::ostream& operator<<(std::ostream& str, const Point<type> pnt);



template<class type = int> 
struct Point
{
public:
	type x;
	type y;


	Point(type x=0,type y=0): x(x), y(y) {} //konstruktor

	bool operator ==(const Point pnt2) const { return(this->x == pnt2.x && this->y == pnt2.y); }
	template<class U>
	friend std::ostream& operator<<(std::ostream& str, const Point<U> pnt);

};
////////////////////////////

template<class type>
inline std::ostream& operator<<(std::ostream& str, const Point<type> pnt)
{
	str << '(' << pnt.x << ',' << pnt.y << ')';
	return str;
}




#endif
