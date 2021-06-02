#include "Ofigure.h"
using namespace std;

Ofigure::Ofigure()
{
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			point.SetXY(i, 0);
		else
			point.SetXY(i - 2, 1);
		moved_figure.push_back(point);
	}
	moved_figure[0].SetStop(left);
	moved_figure[1].SetStop(right);
	moved_figure[2].SetStop(left_down);
	moved_figure[3].SetStop(right_down);
}

void Ofigure::ResetFigure()
{
	focus = nullptr;

	short int l = 0;
	vector<Point>::iterator i;
	for (i = moved_figure.begin(); i != moved_figure.end(); i++)
	{
		if (l < 2)
			i->SetXY(l, 0);
		else
			i->SetXY(l - 2, 1);
		l++;
	}
}




