#pragma once
#include<vector>
#include "Figure.h"
class Zfigure :	public Figure {
public:
	Zfigure(short int _speed_factor);
	~Zfigure();
	void ResetFigure();
	void Turn();
	void TurnBack();
};

