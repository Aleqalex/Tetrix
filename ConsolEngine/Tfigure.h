#pragma once
#include<vector>
#include "Figure.h"
class Tfigure :	public Figure{
public:
	Tfigure(short int _speed_factor);
	~Tfigure();
	void ResetFigure();
	void Turn();
	void TurnBack();
};

