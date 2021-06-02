#pragma once
#include<algorithm>
#include<vector>
#include"Figure.h"
#include"Ifigure.h"
#include"Ofigure.h"
#include"Tfigure.h"
#include"Sfigure.h"
#include"Zfigure.h"
#include"Jfigure.h"
#include<ctime>
#include<random>
using namespace std;

void Figure::SetFigure(short int _x, short int _y, short int _sp)
{
	vector<Point>::iterator i;
	for (i= moved_figure.begin(); i != moved_figure.end(); i++)
	{
		(*i).AddToX(_x);
		(*i).AddToY(_y);
		(*i).MultiplyToY(_sp);
	}
	if (!figure.empty())
	{
		figure.erase(figure.begin(), figure.end());
	}	
}

void Figure::MoveFigure(short int &_newX, short int &_newY, short int &_oldX, short int &_oldY)
{
	vector<Point>::iterator i;
	for (i = moved_figure.begin(); i != moved_figure.end(); i++)
	{
		(*i).AddToX(_newX - _oldX);
		(*i).AddToY(_newY - _oldY);
	}

}

void Figure::ReturnMovedFigure(short int &_newX, short int &_oldX) // изменяем все X нового положения фигуры на предыдущее
{
	vector<Point>::iterator i;
	for (i = moved_figure.begin(); i != moved_figure.end(); i++)
	{
		(*i).AddToX(_oldX - _newX);
	}
	_newX = _oldX;
}

vector<Point> *Figure::GetFigure()
{
	return &figure;
}

vector<Point> *Figure::GetMovedFigure()
{
	return &moved_figure; 
}

void Figure::YMultiply(short int _a, vector<Point> *_figure_type)
{
	vector<Point>::iterator i;
	for (i = _figure_type->begin(); i != _figure_type->end(); i++)
	{
		(*i).MultiplyToY(_a);
	}
}

void Figure::YDevide(short int _a, vector<Point> *_figure_type)
{
	vector<Point>::iterator i;
	for (i = _figure_type->begin(); i != _figure_type->end(); i++)
	{
		(*i).DevideYBy(_a);
	}
}







