#pragma once
#include<vector>
#include"Point.h"
using namespace std;

// ����������� ����������� ����� �����
class Figure {
protected:

	// ��������������� ��� � ������ �������� ���������� �����/���������
	Point point;

	// ��� ������������ ����� ����� ���� ����� � �����/���������
	enum Stops { no, left_down, down, right_down, left_right, left_right_down, left, right };

	// ��������� ��� ����������� ������ ������������ ��� ���������� ������ ��������� ������ ��� ��������/�������� ��� ��� �����������/�������� ������ � ���������� ���������
	struct Provisions{
		vector<Point> *provision = new vector<Point>();
		Provisions *next, *previous;
	} *focus = nullptr;

	Provisions *provision_one = nullptr, *provision_two = nullptr, *provision_three = nullptr, *provision_four = nullptr;

	// figure - ���������� ����������� ��������� � ������ ���, moved_figure ���������� ������������ ������ � ��. ���.
	vector<Point> figure, moved_figure; 

public:	

	// ������� ��� ����������� �����
	struct add : binary_function<Point, Point, Point>{
		Point operator() (Point a, Point b) const { return a + b; }
	};

	// ������� ��� ��������� �����
	struct subtract : binary_function<Point, Point, Point>{
		Point operator() (Point a, Point b) const { return a - b; }
	};

	// ����������� ����� ��� ��������/ �������� �����. ���������������� � ������� ������������ �����, ����� �-������
	virtual void Turn() = 0;

	// ����������� ����� ��� ��������/ �������� ����� � ���������� ���������. ���������������� � ������� ������������ �����, ����� �-������
	virtual void TurnBack() = 0;

	// ����������� ����� ��� ������ �������� ��������� ������������ ������ � ��������� �����������. ���������������� � ������� ������������ �����.
	virtual void ResetFigure() = 0;

	// ��������� ������ �� �������� �����������, � ������ ������������ �������� ������� ����������
	void SetFigure(short int _x, short int _y, short int _sp);

	// ����������� ������ �� �������� ����������
	void MoveFigure(short int &_newX, short int &_newY, short int &_oldX, short int &_oldY);

	// ������� ������������ ������ �� ��� � � �������� �������� �  
	void ReturnMovedFigure(short int &_newX, short int &_oldX);

	// ��������� ���� Y � ������/���������� �� �������� ���������� ���������� ������� ������
	void YMultiply(short int _a, vector<Point> *_figure_type);

	// ������� ���� Y � ������/���������� �� �������� ���������� ���������� ������� ������
	void YDevide(short int _a, vector<Point> *_figure_type);

	// �������� �������� ����������� ��������� ������ � ��������
	void RemoveFigureTrack(){ figure = moved_figure; }

	// ��������� ������ ������� �������� ����� ��������� ������
	vector<Point> *GetMovedFigure();

	// ��������� ������ ������� �������� ����������� ��������� ������
	vector<Point> *GetFigure();

	virtual ~Figure(){};
};
