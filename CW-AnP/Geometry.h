#pragma once
#include <iostream>
#include "windows.h"
#include "math.h"
#include "conio.h"

// основная функция
void Geometry();

// ______________________ Геометрия _______________________

// точка
struct Dot {
	int x; // абсциса точки
	int y; // ордината точки
};

// окружность по центру и радиусу
struct Circle {
	int x; // абсциса центра
	int y; // ордината центра
	float r; // radius
};

// прямая, проходящая через 2 точки
struct Line {
	int x1;
	int y1;
	int x2;
	int y2;
};

// сформировать массив точек 
void FormDots(Dot*, int);
// сформировать массив окружностей
void FormCircles(Circle*, int);

// ввести масив точек с клавиатуры (множество А) 
void EnterDotsByKeyboard(Dot*, int); 
// случайно сгенерировать массив точек(множество А)
void RandomDots(Dot*, int); 
// взять точки из файла и зарандомить недостающие (множество А)
void GetDotsFromFile(Dot*, int);

// ввести массив окружностей с клавиатуры (мн. B)
void EnterCirclesByKeyboard(Circle*, int);
// зарандомить окружности (мн. B)
void RandomCircles(Circle*, int);
// взять окружности из файла (мн. B)
void GetCirclesFromFile(Circle*, int);

Line MyTask(Dot*, Circle*, int, int, Line*);

// __________________________ Графика _____________________________

#include "winuser.h"

// границы
struct Borders {
	float x_min;
	float x_max;

	float y_min;
	float y_max;
};

// масштаб
struct Parameter {
	float x;
	float y;
};

#define DELTA 25 // 1 клеточка (шир-дл)
#define EDGE_HALF DELTA * 10 // половина оси сетки = 250

#define KB_RIGHT 77
#define KB_LEFT 75
#define KB_PLUS 43
#define KB_MINUS 45
#define KB_HOME 36
#define KB_ESC 27

// отрисовать график
void Draw(Dot*, int, Circle*, int, Line*, int);
// нарисовать сетку
void MakeGrid(Borders, Parameter axis, Parameter scale);
// нарисовать оси
Parameter MakeAxis(Borders, Parameter scale);
// нарисовать элементы
void MakeElements(Dot, RECT, Dot*, int, Circle*, int, Borders, Line*, int);

// вычислить масштаб
Parameter CalcScale(Borders);
// вычислить границы отрисовки
Borders CalcGraphBorders(Dot*, int, Circle*, int);





/*
//void dot(HDC hDC, int x, int y, COLORREF Color);
void clearscreen(int red, int green, int blue);
void DrawAxis(Limits, Scale, int*, int*);
void DrawGrid(Limits, Scale, int, int);
// вычислить границы отрисовки
void CalculateBorders(Limits*, Dot*, Circle*, int, int);
void Draw(Dot*, Circle*, int, int);
*/
