#include "Building.h"


void Building::AddFigure(Figure* _figure, short int _speed_factor)
{
	vector<Point> *p_figure = _figure->GetFigure();
	_figure->YDevide(_speed_factor, p_figure);
	building.insert(building.end(), p_figure->begin(), p_figure->end());
	pervious_building = building;
	CheckFloors();
}

void Building::CheckFloors()
{
	short int l = base, vertex;
	vertex = GetBuildingVertex();
	for (l; l >= vertex; --l)
	{
		if (width == count_if(building.begin(), building.end(), bind2nd(YIs(), l)))
		{
			floors.push_back(l);
		}
	}
}

bool Building::BuildingStrinkage(short int &floors_quantity)
{
	if (!floors.empty())
	{
		vector<short int>::iterator j = floors.begin();
		vector<Point>::iterator new_end;

		for (j; j != floors.end(); j++)
		{
			new_end = remove_if(building.begin(), building.end(), bind2nd(YIs(), (*j)));
			building.erase(new_end, building.end());
		}
		floors_quantity = floors.size();
		MoveFloors();
		floors.erase(floors.begin());
		return true;
	}
	else
	{
		return false;
	}
}

short int Building::GetBuildingVertex()
{
	if (!building.empty())
	{
		i = min_element(building.begin(), building.end());

		return (*i).GetY();
	}
	else
	{
		return 0;
	}
}

void Building::MoveFloors()
{
	vector<short int>::reverse_iterator j;
	for (i = building.begin(); i != building.end(); i++)
	{
		for (j = floors.rbegin(); j != floors.rend(); j++)
		{
			if ((*i).GetY() < (*j))
			{
				(*i).IncY();
			}
		}
	}
}

