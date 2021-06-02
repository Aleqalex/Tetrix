#pragma once
#include<vector>
#include "Figure.h"
class Sfigure :	public Figure{

public:
	Sfigure(short int _speed_factor);
	~Sfigure();
	void ResetFigure();
	void Turn();
	void TurnBack();
};

