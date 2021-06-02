#include "Sfigure.h"
#include<iterator>
#include<algorithm>
using namespace std;

Sfigure::Sfigure(short int _speed_factor)
{
	provision_one = new Provisions;
	provision_two = new Provisions;
	provision_three = new Provisions;
	provision_four = new Provisions;
	provision_one->next = provision_two;
	provision_two->next = provision_three;
	provision_three->next = provision_four;
	provision_four->next = provision_one;

	provision_one->previous = provision_four;
	provision_two->previous = provision_one;
	provision_three->previous = provision_two;
	provision_four->previous = provision_three;

	focus = provision_one;

	for (int i = 0; i < 4; i++)
	{		
		if (i < 2)
		{
			point.SetXY(i, 1);
			moved_figure.push_back(point);
		}
		else
		{
			point.SetXY(i - 1, 0);
			moved_figure.push_back(point);
		}		
	}

	moved_figure[0].SetStop(left_down);
	moved_figure[1].SetStop(right_down);
	moved_figure[2].SetStop(left);
	moved_figure[3].SetStop(right_down);

	point.SetXY(1, 1);
	point.SetStop(4);
	provision_one->provision->push_back(point);
	point.SetXY(0, 0);
	point.SetStop(4);
	provision_one->provision->push_back(point);
	point.SetXY(-1, 1);
	point.SetStop(-5);
	provision_one->provision->push_back(point);
	point.SetXY(-2, 0);
	point.SetStop(1);
	provision_one->provision->push_back(point);
	YMultiply(_speed_factor, provision_one->provision);

	point.SetXY(1, -2);
	point.SetStop(-2);
	provision_two->provision->push_back(point);
	point.SetXY(0, -1);
	point.SetStop(-1);
	provision_two->provision->push_back(point);
	point.SetXY(1, 0);
	point.SetStop(2);
	provision_two->provision->push_back(point);
	point.SetXY(0, 1);
	point.SetStop(-3);
	provision_two->provision->push_back(point);
	YMultiply(_speed_factor, provision_two->provision);

	point.SetXY(-2, 0);
	point.SetStop(1);
	provision_three->provision->push_back(point);
	point.SetXY(-1, 1);
	point.SetStop(-5);
	provision_three->provision->push_back(point);
	point.SetXY(0, 0);
	point.SetStop(4);
	provision_three->provision->push_back(point);
	point.SetXY(1, 1);
	point.SetStop(4);
	provision_three->provision->push_back(point);
	YMultiply(_speed_factor, provision_three->provision);

	point.SetXY(0, 1);
	point.SetStop(-3);
	provision_four->provision->push_back(point);
	point.SetXY(1, 0);
	point.SetStop(2);
	provision_four->provision->push_back(point);
	point.SetXY(0, -1);
	point.SetStop(-1);
	provision_four->provision->push_back(point);
	point.SetXY(1, -2);
	point.SetStop(-2);
	provision_four->provision->push_back(point);
	YMultiply(_speed_factor, provision_four->provision);
}

Sfigure::~Sfigure()
{
	delete provision_one;
	delete provision_two;
	delete provision_three;
	delete provision_four;
}

void Sfigure::Turn()
{
	vector<Point>::iterator i, j, l;
	i = figure.begin(); //предыдущие координаты для очистки на экране
	j = focus->provision->begin();
	l = moved_figure.begin();

	transform(i, i + 4, j, l, add());
	
	focus = focus->next;
}

void Sfigure::ResetFigure()
{
	focus = provision_one;

	short int l = 0;
	vector<Point>::iterator i;
	for (i = moved_figure.begin(); i != moved_figure.end(); i++)
	{
		if (l < 2)
		{
			i->SetXY(l, 1);

		}
		else
		{
			i->SetXY(l - 1, 0);
		}
		l++;
	}
}

void Sfigure::TurnBack()
{
	vector<Point>::iterator i, j, l;
	focus = focus->previous;

	i = figure.begin(); //предыдущие координаты для очистки на экране
	j = focus->provision->begin();
	l = moved_figure.begin();

	transform(i, i + 4, j, l, subtract());
}





