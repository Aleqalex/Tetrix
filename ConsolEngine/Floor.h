#pragma once
#include<utility>
#include<functional>
#include<algorithm>
#include<vector>
#include"Point.h"
#include "Figure.h"

using namespace std;

class Floor {
	int floor_width;
	int floor_depth;
	vector<Point> floor;
	vector<Point> pervious_floor;
	vector<short int> q;
public:
	Floor();
	~Floor();
	void AddFigure(Figure *);
	void  CheckFloor(); // проверка на полностью заполненный ряд
	void SetFloor(int _width, int _depth) { floor_width = _width; floor_depth = _depth; } //кинуть в конструктор
	int GetFloorWidth(){ return floor_width; }
	int GetFloorDepth(){ return floor_depth; }
	vector<Point> GetFloor(){ return floor; }
	vector<Point> GetPerviousFloor(){ return pervious_floor; }
	bool FloorStrinkage();
	int GetFloorVertex();
	vector<short int> GetQ(){ return q; };

	void MoveFloor(vector<short int> &_rows);
	struct YIs : binary_function<Point, int, bool>
	{
		bool operator()(Point a, int b) const { return (int(a) == b); }
	};

};

