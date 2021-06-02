#pragma once
#include<utility>
#include<functional>
#include<algorithm>
#include<vector>
#include"Point.h"
#include "Figure.h"

using namespace std;

// ����������� �� ����� ������
class Building {

	// ������ �����
	short int width;

	// ������� ���������. ��������� �� ��� Y
	short int base;

	// ����������� ������
	vector<Point> building;

	// ������ ������������ ������. ����� ��� ������� ��� ��������� � ����������� ������
	vector<Point> pervious_building;

	// ������ �������� ������, ������� ��������� ���������
	vector<short int> floors;
	vector<Point>::iterator i;
public:
	Building(short int _width, short int _base) : width(_width), base(_base){};

	// ��������� ������ ���������
	void SetBase(short int _base){ base = _base; }

	// ��������� ������ ������
	short int GetWidth(){ return width; }

	// ���������� � ������ ����� ������
	void AddFigure(Figure* _figure, short int _speed_factor);

	// �������� �� ��������� ����������� ���/����
	void  CheckFloors();

	short int GetBuildingWidth(){ return width; }
	short int GetBuildingBase(){ return base; }
	vector<Point> *GetBuilding(){ return &building; }
	vector<Point> *GetPerviousBuilding(){ return &pervious_building; }

	// ������ ������ ��� ����������� ��������� ���������� ������/�����, ��������� ���������� ��������/����������� ������
	bool BuildingStrinkage(short int &_floors_quantity);

	// ��������� �������� ������� ������
	short int GetBuildingVertex();

	// �������� ���� ������ ������� ��� �������� ��������� �����������/�� ������/��
	void MoveFloors();


	// ������� ��� �������� ���� ���������� ������ ���� ��� ����� ��������� �� Y �� ������� �������� ��������� ����������� ������
	struct YIs : binary_function<Point, int, bool>
	{
		bool operator()(Point a, int b) const { return (int(a) == b); }
	};

};