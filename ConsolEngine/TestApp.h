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

		// Максимально возможные размеры здания
		const short int max_building_width, max_building_height;

		// Коэфициент для обработки следующей фигуры
		short int speed_delay_next_figure = 1;

		// Флаг игры. Истина игра окончена. Ложь игра продолжается
		bool stop_game;

		// Строка отображающая: > Score : + очки
		string  score_text;

		// Количество полностью заполненых этажей
		short int floors_quantity = 0;

		// Очки
		unsigned short int score_number;

		// Коэфициент замедления отображения фигуры на экрание и буфер для этого коефициента
		short int speed_delay, buff_speed_delay;

		vector<Point>::iterator k;
		
		//Указатель на сегенрированный объект-фигуру и указатель на сгенерированный на следующий объект-фигуру
		Figure *figure = nullptr, *next_figure = nullptr;

		// Указатель на объект обработки здания
		Building *building = nullptr;

		// Указатели на вектор здания, вектор предыдущего здания, вектор перемещенной фигуры, вектор предыдущег оположения фигуры
		vector<Point> *p_building = nullptr, *p_pervious_building = nullptr;
		vector<Point> *p_moved_figure = nullptr, *p_figure = nullptr;

		// Генерация фигур
		Figure* CreateFigure();

		// Попытка поворота фигуры
		void TryTurn();

		// Проверка препядствие
		bool Check_Obstackle(short int &_newX, short int &_newY, short int &_oldX, short int &_oldY);

		// Удаление частей предыдущей фигуры
		void FillAfterFigure(Figure *_figure, short int _speed_factor, char _ch);

		// Изображение фигуры
		void DrawFigure(Figure *_figure, short int &_speed_factor);

	public:

		TestApp();
		~TestApp();
		virtual void KeyPressed(int btnCode);
		virtual void UpdateF(float deltaTime);
		void Frame();

		vector<Point> buf;
};
