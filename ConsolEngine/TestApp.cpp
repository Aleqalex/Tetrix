// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#include<vector>
#include<iterator>
#include"TestApp.h"
#include<ctime>
#include<random>

// вращение j-фигуры в самом начале дает зависание // баг не обнаружен

TestApp::TestApp() : Parent(24, 25), speed_delay(40), max_building_height(21), max_building_width(16), stop_game(false)
{
	score_number = 0;
	building = new Building(max_building_width, max_building_height * speed_delay);
	
	mDirection = true;
	mObj1XOld = mObj1X = 8;
	mObj1YOld = mObj1Y = 1;
	mObj2X = 19;
	mObj2Y = 3;

	for (int y = 0; y < 26; y++)
	{
		for (int x = 0; x < 25; x++)
		{
			if (x == 17 && y < 21)
			{
				SetChar(x, y, L'#');
			}
			if (x == 0 || x == 24)
			{
				SetChar(x, y, L'#');
			}
			else
			{
				if ((x != 0 || x != 17 || x != 24) && y < 21 && x < 17)
				{
					SetChar(x, y, 46);
				}					
			}
			if (y == 0 || y == 21 || y == 25)
			{
				SetChar(x, y, L'#');
			}
		}
	}

	score_text = "> Score : ";
	score_text += to_string(score_number);
	for (short int i = 0; i < score_text.length(); i++)
	{
		SetChar(i + 3, 23, score_text[i]);
	}

	figure = CreateFigure();
	figure->SetFigure(mObj1X, mObj1Y, speed_delay); //на самом деле set moved figure
	mObj1YOld = mObj1Y = 1* speed_delay;

	next_figure = CreateFigure();
	next_figure->SetFigure(mObj2X, mObj2Y,speed_delay_next_figure);
	DrawFigure(next_figure,speed_delay_next_figure);

	buff_speed_delay = speed_delay;
}

void TestApp::KeyPressed(int btnCode)
{
	if (btnCode == 119) //w
	{
		TryTurn();
	}
	else if (btnCode == 115) //s
	{
		FillAfterFigure(figure, speed_delay, 46);
		figure->YDevide(speed_delay, figure->GetMovedFigure());

		mObj1Y = mObj1Y / speed_delay;
		
		mObj1YOld = mObj1Y;
		speed_delay = 1;

		building->SetBase(max_building_height * speed_delay);
		figure->SetFigure(0, 0, speed_delay);
	}
	else if (btnCode == 97) //a
		mObj1X--;
	else if (btnCode == 100) //d
		mObj1X++;

		/*if (mObj1X < 0)
			mObj1X = 0;
		else if (mObj1X >= X_SIZE)
			mObj1X = X_SIZE - 1;

		if (mObj1Y < 0)
			mObj1Y = 0;
		else if (mObj1Y >= Y_SIZE * speed_delay)
			mObj1Y = Y_SIZE * speed_delay - 1;*/

}


void TestApp::UpdateF(float deltaTime)
{

	if (!stop_game)
	{
		figure->MoveFigure(mObj1X, mObj1Y, mObj1XOld, mObj1YOld);

		if (!Check_Obstackle(mObj1X, mObj1Y, mObj1XOld, mObj1YOld))
		{
			DrawFigure(figure, speed_delay);
			figure ->RemoveFigureTrack();

		}
		else
		{
			mObj1YOld = mObj1Y = 1;
			mObj1XOld = mObj1X = 8;
			building->AddFigure(figure, speed_delay);
			delete figure;

			if (speed_delay == 1)
			{
				speed_delay = buff_speed_delay;
				building->SetBase(max_building_height * speed_delay);
			}

			FillAfterFigure(next_figure, 1, ' ');
			figure = next_figure;
			figure->ResetFigure(); // это на самом деле reset moved figure

			figure->SetFigure(mObj1X, mObj1Y, speed_delay);
			mObj1YOld = mObj1Y = 1 * speed_delay;
			 // может быть баг так как после это строки следует вызвать DrawFigure()
			next_figure = CreateFigure();
			next_figure->SetFigure(mObj2X, mObj2Y, speed_delay_next_figure);
			DrawFigure(next_figure, speed_delay_next_figure);

			if (building->BuildingStrinkage(floors_quantity))
			{
				p_pervious_building = building->GetPerviousBuilding();
				for (k = p_pervious_building->begin(); k != p_pervious_building->end(); k++)
				{
					SetChar((*k).GetX(), (*k).GetY(), 46);
				}

				p_building = building->GetBuilding();
				for (k = p_building->begin(); k != p_building->end(); k++)
				{
					SetChar((*k).GetX(), (*k).GetY(), 10);
				}
				score_number += (100 * floors_quantity);
				score_text = to_string(score_number);
				for (int i = 0; i < score_text.length(); i++)
				{
					SetChar(i + 3 + 10, 23, score_text[i]);
				}
			}
		}

		mObj1XOld = mObj1X;
		mObj1YOld = mObj1Y;

		mObj1Y++;

		//mObj1Y += mObj2Y;
		//-----------------------------

		//SetChar(mObj2X, mObj2Y, L' ');
		/*mObj2Y++;
		if (mDirection)
		{
		mObj2X++;
		if (mObj2X == 30)
		mDirection = false;
		}
		else
		{
		mObj2X--;
		if (mObj2X == 10)
		mDirection = true;
		}*/
	}
}

void TestApp::Frame()
{

}

void TestApp::DrawFigure(Figure *_figure, short int &_speed_factor)
{
	vector<Point>::iterator i;
	p_moved_figure = _figure->GetMovedFigure();
	p_figure = _figure->GetFigure();

	if (!p_figure->empty())
	{
		for (i = p_figure->begin(); i != p_figure->end(); i++)
		{
			SetChar(i->GetX(), i->GetY() / _speed_factor, 46);
		}
	}

	for (i = p_moved_figure->begin(); i != p_moved_figure->end(); i++)
	{
		SetChar(i->GetX(), i->GetY() / _speed_factor, 10);
	}
}


bool TestApp::Check_Obstackle(short int &_newX, short int &_newY, short int &_oldX, short int &_oldY)
{
	bool flag = false;
	enum Stops { no, left_down, down, right_down, left_right, left_right_down, left, right };
	vector<Point>::iterator i;
	vector<Point> *p_moved_figure, *p_figure;

	p_moved_figure = figure->GetMovedFigure();

	if (_newX < _oldX)
	{
		for (i = p_moved_figure->begin(); i != p_moved_figure->end(); i++)
		{
			switch (i->GetStop())
			{
				case left_down:
				{
					if (GetChar(i->GetX(), i->GetY() / speed_delay) == L'#' || GetChar(i->GetX(), i->GetY() / speed_delay) == 10)
					{
						figure->ReturnMovedFigure(_newX, _oldX);
					}
					break;
				}
				case left_right:
				{
					if (GetChar(i->GetX(), i->GetY() / speed_delay) == L'#' || GetChar(i->GetX(), i->GetY() / speed_delay) == 10)
					{
						figure->ReturnMovedFigure(_newX, _oldX);
					}
					break;
				}
				case left:
				{
					if (GetChar(i->GetX(), i->GetY() / speed_delay) == L'#' || GetChar(i->GetX(), i->GetY() / speed_delay) == 10)
					{
						 figure->ReturnMovedFigure(_newX, _oldX);
					}
					break;
				}
				case left_right_down:
				{
					if (GetChar(i->GetX(), i->GetY() / speed_delay) == L'#' || GetChar(i->GetX(), i->GetY() / speed_delay) == 10)
					{
						figure->ReturnMovedFigure(_newX, _oldX);
					}
					break;
				}
			}
		}
	}
	
	if (_newX > _oldX)
	{
		for (i = p_moved_figure->begin(); i != p_moved_figure->end(); i++)
		{
			switch (i->GetStop())
			{
				case right_down:
				{
					if (GetChar(i->GetX(), i->GetY() / speed_delay) == L'#' || GetChar(i->GetX(), i->GetY() / speed_delay) == 10)
					{
						figure->ReturnMovedFigure(_newX, _oldX);
					}
					break;
				}
				case left_right:
				{
					if (GetChar(i->GetX(), i->GetY() / speed_delay) == L'#' || GetChar(i->GetX(), i->GetY() / speed_delay) == 10)
					{
						figure->ReturnMovedFigure(_newX, _oldX);
					}
					break;
				}
				case right:
				{
					if (GetChar(i->GetX(), i->GetY() / speed_delay) == L'#' || GetChar(i->GetX(), i->GetY() / speed_delay) == 10)
					{
						figure->ReturnMovedFigure(_newX, _oldX);
					}
					break;
				}
				case left_right_down:
				{
					if (GetChar(i->GetX(), i->GetY() / speed_delay) == L'#' || GetChar(i->GetX(), i->GetY() / speed_delay) == 10)
					{
						figure->ReturnMovedFigure(_newX, _oldX);
					}
					break;
				}
			}
		}
	}

	p_figure = figure->GetFigure();
	
	if ((!(_newY % speed_delay)) && (_newX == _oldX)) 
	{
		for (i = p_moved_figure->begin(); i != p_moved_figure->end(); i++)
			{
				switch (i->GetStop())
				{
					case left_down:
					{
						if (GetChar(i->GetX(), i->GetY() / speed_delay) == L'#' || GetChar(i->GetX(), i->GetY() / speed_delay) == 10)
						{
							flag = true;
						}
						break;
					}
					case down:
					{
						if (GetChar(i->GetX(), i->GetY() / speed_delay) == L'#' || GetChar(i->GetX(), i->GetY() / speed_delay) == 10)
						{
							flag = true;
						}
						break;
					}
					case right_down:
					{
						if (GetChar(i->GetX(), i->GetY() / speed_delay) == L'#' || GetChar(i->GetX(), i->GetY() / speed_delay) == 10)
						{
						   flag = true;
						}
						break;
					}
					case left_right_down:
					{
						if (GetChar(i->GetX(), i->GetY() / speed_delay) == L'#' || GetChar(i->GetX(), i->GetY() / speed_delay) == 10)
						{
							flag = true;
						}
						break;
					}
				}
		}
	}
	return flag;
}

void TestApp::FillAfterFigure(Figure *_figure, short int _speed_factor, char _ch)
{
	vector<Point>::iterator i;
	p_moved_figure = _figure->GetMovedFigure();
	
	for (i = p_moved_figure->begin(); i != p_moved_figure->end(); i++)
	{
		SetChar((*i).GetX(), ((*i).GetY()/ _speed_factor), _ch);
	}
}


TestApp::~TestApp()
{
	delete figure;
	delete next_figure;
	delete building;
}

Figure* TestApp::CreateFigure()
{
	static Figure* tmp_p_figure;
	if (building->GetBuildingVertex() != 1)
	{
		srand(time(0));
		switch (rand() % 6)
		{
			case 0:
			{
					  return tmp_p_figure = new Ifigure(speed_delay);
			}
			case 1:
			{
					  return tmp_p_figure = new Jfigure(speed_delay);
			}
			case 2:
			{
					  return tmp_p_figure = new Ofigure;
			}
			case 3:
			{
					  return tmp_p_figure = new Sfigure(speed_delay);
			}
			case 4:
			{
					  return tmp_p_figure = new Tfigure(speed_delay);
			}
			case 5:
			{
					  return tmp_p_figure = new Zfigure(speed_delay);
			}
		}
	}
	else
	{
		stop_game = true;
		return tmp_p_figure;
	}
}

void TestApp::TryTurn()
{
	Point buf_point;
	bool flg = false;
	vector<Point>::iterator i, j;
	vector<Point> *p_mf, *p_bld;
	p_bld = building->GetBuilding();
	p_mf = figure->GetMovedFigure();

	figure->Turn();
	
	if (!building->GetBuilding()->empty())
	{
		for (j = p_bld->begin(); j != p_bld->end(); j++)
		{
			for (i = p_mf->begin(); i != p_mf->end(); i++)
			{
				buf_point = (*i);
				buf_point.DevideYBy(speed_delay);
				if (buf_point == (*j))
				{
					flg = true;
					break;
				}
			}
		}
	}

	for (i = p_mf->begin(); i != p_mf->end(); i++)
	{
		if (GetChar(i->GetX(), i->GetY()/ speed_delay) == L'#')
		{
			flg = true;
			break;
		}
	}
	if (flg)
	{
		figure->RemoveFigureTrack();
		figure->TurnBack();
		figure->RemoveFigureTrack();
	}
}
