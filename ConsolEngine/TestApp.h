// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#pragma once

#include<string>
#include "BaseApp.h"
#include"Point.h"
#include"Figure.h"
#include"Building.h"
#include"Ifigure.h"
#include"Ofigure.h"
#include"Tfigure.h"
#include"Sfigure.h"
#include"Zfigure.h"
#include"Jfigure.h"


class TestApp : public BaseApp
{
	typedef BaseApp Parent;

	private:
		short int mObj1XOld;
		short int mObj1YOld;
		short int mObj1X;
		short int mObj1Y;

		short int mObj2X;
		short int mObj2Y;

		bool mDirection;

		// ����������� ��������� ������� ������
		const short int max_building_width, max_building_height;

		// ���������� ��� ��������� ��������� ������
		short int speed_delay_next_figure = 1;

		// ���� ����. ������ ���� ��������. ���� ���� ������������
		bool stop_game;

		// ������ ������������: > Score : + ����
		string  score_text;

		// ���������� ��������� ���������� ������
		short int floors_quantity = 0;

		// ����
		unsigned short int score_number;

		// ���������� ���������� ����������� ������ �� ������� � ����� ��� ����� �����������
		short int speed_delay, buff_speed_delay;

		vector<Point>::iterator k;
		
		//��������� �� ��������������� ������-������ � ��������� �� ��������������� �� ��������� ������-������
		Figure *figure = nullptr, *next_figure = nullptr;

		// ��������� �� ������ ��������� ������
		Building *building = nullptr;

		// ��������� �� ������ ������, ������ ����������� ������, ������ ������������ ������, ������ ���������� ���������� ������
		vector<Point> *p_building = nullptr, *p_pervious_building = nullptr;
		vector<Point> *p_moved_figure = nullptr, *p_figure = nullptr;

		// ��������� �����
		Figure* CreateFigure();

		// ������� �������� ������
		void TryTurn();

		// �������� �����������
		bool Check_Obstackle(short int &_newX, short int &_newY, short int &_oldX, short int &_oldY);

		// �������� ������ ���������� ������
		void FillAfterFigure(Figure *_figure, short int _speed_factor, char _ch);

		// ����������� ������
		void DrawFigure(Figure *_figure, short int &_speed_factor);

	public:

		TestApp();
		~TestApp();
		virtual void KeyPressed(int btnCode);
		virtual void UpdateF(float deltaTime);
		void Frame();

		vector<Point> buf;
};
