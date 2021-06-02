#pragma once
#include<utility>
#include<functional>
#include<algorithm>
#include<vector>
#include"Point.h"
#include "Figure.h"

using namespace std;

// ѕостроенное из фигур здание
class Building {

	// Ўирина зани€
	short int width;

	// ”ровень основани€. —читаетс€ по оси Y
	short int base;

	// ѕосторенное здание
	vector<Point> building;

	// Ѕуффер посторенного здани€. Ќужен дл€ очистки при изменении в посторенном здании
	vector<Point> pervious_building;

	// ¬ектор значений этажей, которые полностью заполнены
	vector<short int> floors;
	vector<Point>::iterator i;
public:
	Building(short int _width, short int _base) : width(_width), base(_base){};

	// ”становка уровн€ основани€
	void SetBase(short int _base){ base = _base; }

	// ѕолучение ширины здани€
	short int GetWidth(){ return width; }

	// ƒобавление в здание новой фигуры
	void AddFigure(Figure* _figure, short int _speed_factor);

	// ѕроверка на полностью заполненный р€д/этаж
	void  CheckFloors();

	short int GetBuildingWidth(){ return width; }
	short int GetBuildingBase(){ return base; }
	vector<Point> *GetBuilding(){ return &building; }
	vector<Point> *GetPerviousBuilding(){ return &pervious_building; }

	// ”садка задни€ при обнаружении полностью заполненых этажей/р€дов, получение количества убранных/заполненных этажей
	bool BuildingStrinkage(short int &_floors_quantity);

	// ѕолучение значени€ вершины здани€
	short int GetBuildingVertex();

	// —мещение всех этажей сто€щих над убранным полностью заполненным/ми этажем/ми
	void MoveFloors();


	// ‘унктор дл€ удалени€ всех кирпичиков здани€ если они равны значени€м по Y из вектора значений полностью заполненных этажей
	struct YIs : binary_function<Point, int, bool>
	{
		bool operator()(Point a, int b) const { return (int(a) == b); }
	};

};