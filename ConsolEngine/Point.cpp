#include"Point.h"

Point::Point()
{
	x = 0; y = 0; stop = no;
}

Point Point::operator+(Point &point)
{
	Point tmp;

	tmp.x = x + point.x;
	tmp.y = y + point.y;
	tmp.stop = Stops(stop + point.stop);
	return tmp;
}

/*Point Point::operator*(short int _a)
{
	y = y * _a;
	return *this;
}*/

Point Point::operator-(Point &point) // возможно не надо
{
	Point tmp;
	tmp.x = x - point.x;
	tmp.y = y - point.y;
	tmp.stop = Stops(stop - point.stop);
	return tmp;
}

bool Point::operator== (Point &a)
{
	return (x == a.x && y == a.y);
}


/*bool Point::operator< (Point a)
{
	return (y < a.y && x < a.x);
}

bool Point::operator>(Point a)
{
	return (y > a.y && x > a.x);
}

bool Point::operator == (Point a)
{
	return (y == a.y && x == a.x);
}

bool Point::operator != (Point a)
{
	return (y != a.y && x != a.x);
}*/

void Point::SetStop(short int _stop)
{
	stop = Stops(_stop);
}

void Point::SetStop(Stops _stop)
{
	stop = _stop;
}

Point::Stops Point::GetStop()
{
	return stop;
}

void Point::SetXY(short int _x, short  int _y)
{
	x = _x, y = _y;
}

void Point::SetX(short int _x)
{
	x = _x;
}

void Point::SetY(short int _y)
{
	y = _y;
}

short int Point::GetX()
{
	return x;
}

short int Point::GetY()
{
	return y;
}

void Point::AddToX(short int _a)
{
	x = x + _a;
}

void Point::AddToY(short int _a)
{
	y = y + _a;
}

void Point::IncY()
{
	y++;
}

void Point::IncX()
{
	x++;
}
void Point::DecrmY()
{
	y--;
}

/*Point Point::operator = (int a)
{
	this->y = a;
	this->x = 0; // возможно не надо
	return *this;
}*/

Point::operator int() const
{
	return this->y;
};

/*bool operator <(Point a, Point b)
{
	return (a.x + a.y) < (b.x + b.y);
}

bool operator ==(Point a, Point b)
{
	return (a.x + a.y) == (b.x + b.y);
}

bool operator >(Point a, Point b)
{
	return (a.x + a.y) > (b.x + b.y);
}

bool operator !=(Point a, Point b)
{
	return (a.x + a.y) != (b.x + b.y);
}*/

bool Point::operator <(Point a)
{
	return (x + y) < (a.x + a.y);
}

bool  Point::operator >(Point a)
{
	return (x + y) > (a.x + a.y);
}

/*bool  Point::operator ==(Point a)
{
	return (x + y) == (a.x + a.y);
}*/

bool  Point::operator != (Point a)
{
	return (x + y) != (a.x + a.y);
}

/*Point Point::operator /(short int a)
{
	return y / a;
}*/

void Point::MultiplyToY(short int _a)
{
	y = y*_a;
}


void Point::DevideYBy(short int _a)
{
	y = y/_a;
}


