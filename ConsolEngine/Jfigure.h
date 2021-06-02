#pragma once
#include<vector>
#include "Figure.h"
class Jfigure :	public Figure{
public:
	Jfigure(short int _speed_factor);
	~Jfigure();
	void ResetFigure();
	void Turn();
	void TurnBack();
};

