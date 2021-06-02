#pragma once
#include<vector>
#include<functional>
#include "Figure.h"
class Ifigure : public Figure
{	
public:
	Ifigure(short int _speed_factor);
	~Ifigure();
	void Turn();
	void TurnBack();
	void ResetFigure();
};
