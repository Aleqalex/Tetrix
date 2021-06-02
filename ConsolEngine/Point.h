#pragma once
class Point {
	short int x, y;
	enum Stops { no, left_down, down, right_down, left_right, left_right_down, left, right } stop;
public:
	Point();
	void SetStop(short int _stop);
	void SetStop(Stops _stop);
	Stops GetStop();
	//int GetIntStop(){ return stop; }
	void SetXY(short int _x, short int _y);
	void SetX(short int _x);
	void SetY(short int _y);
	short int GetX();
	short int GetY();
	void AddToX(short int _a);
	void AddToY(short int _a);
	void IncY();
	void IncX();
	void DecrmY();
	void MultiplyToY(short int _a);
	void DevideYBy(short int _a);
	
	Point operator+(Point &point);
	//Point operator*(short int _a);
	Point operator-(Point &point);
	//Point operator /(short int a);

	bool operator == (Point &point);

	bool operator < (Point a);// возможно не надо
	bool operator > (Point a);// возможно не надо
	//bool operator == (Point a);// возможно не надо
	bool operator != (Point a);// возможно не надо

	/*friend bool operator <(Point a, Point b);
	friend bool operator == (Point a, Point b);
	friend bool operator >(Point a, Point b);
	friend bool operator != (Point a, Point b);*/
	//friend bool operator != (Point a, Point b);

	//Point operator = (int a);// возможно не надо

	operator int() const;
};