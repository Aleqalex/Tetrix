#pragma once
#include<vector>
#include"Point.h"
using namespace std;

// Абстрактный полиморфный класс фигур
class Figure {
protected:

	// Вспомогательный тип и объект хранящий описывание точки/кирпичика
	Point point;

	// Тип определяющий какие могут быть упоры у точки/кирпичика
	enum Stops { no, left_down, down, right_down, left_right, left_right_down, left, right };

	// Структура для двусвязного списка коэфициентов для вычисления нового положения фигуры при повороте/вращении или при возвращении/повороте фигуры в предыдущее положение
	struct Provisions{
		vector<Point> *provision = new vector<Point>();
		Provisions *next, *previous;
	} *focus = nullptr;

	Provisions *provision_one = nullptr, *provision_two = nullptr, *provision_three = nullptr, *provision_four = nullptr;

	// figure - координаты предыдущего положения и другая инф, moved_figure координаты перемещенной фигуры и др. инф.
	vector<Point> figure, moved_figure; 

public:	

	// Функтор для складывания точек
	struct add : binary_function<Point, Point, Point>{
		Point operator() (Point a, Point b) const { return a + b; }
	};

	// Функтор для вычитания точек
	struct subtract : binary_function<Point, Point, Point>{
		Point operator() (Point a, Point b) const { return a - b; }
	};

	// Виртаульный метод для поворота/ вращения фигур. Переопределятеся в классах определенных фигур, кроме о-фигуры
	virtual void Turn() = 0;

	// Виртаульный метод для поворота/ вращения фигур в предыдущее положение. Переопределятеся в классах определенных фигур, кроме о-фигуры
	virtual void TurnBack() = 0;

	// Виртаульный метод для сброса значений координат определенной фигура к начальным координатам. Переопределятеся в классах определенных фигур.
	virtual void ResetFigure() = 0;

	// Установка фигуры на заданных координатах, с учетом замедляющего скорость падения кофициента
	void SetFigure(short int _x, short int _y, short int _sp);

	// Перемещение фигуры на заданные координаты
	void MoveFigure(short int &_newX, short int &_newY, short int &_oldX, short int &_oldY);

	// Возврат предвигаемой фигуры по оси Х и изменеие занчения Х  
	void ReturnMovedFigure(short int &_newX, short int &_oldX);

	// Умножение всех Y в точках/кирпичиках на заданный коэфициент замедления падения фигуры
	void YMultiply(short int _a, vector<Point> *_figure_type);

	// Деление всех Y в точках/кирпичиках на заданный коэфициент замедления падения фигуры
	void YDevide(short int _a, vector<Point> *_figure_type);

	// Смещение значений предыдущего положения фигруы к текущему
	void RemoveFigureTrack(){ figure = moved_figure; }

	// Получение адреса вектора хранящей новые положения фигуры
	vector<Point> *GetMovedFigure();

	// Получение адреса вектора хранящей предыдущего положения фигуры
	vector<Point> *GetFigure();

	virtual ~Figure(){};
};
