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

// масштаб
struct Scale {
	float x;
	float y;
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

void MyTask(Dot*, Circle*, int, int);

// __________________________ Графика _____________________________

#include "winuser.h"

struct Borders {
	float x_min;
	float x_max;

	float y_min;
	float y_max;
};

#define DX 20
#define DY 20

#define KB_RIGHT 77
#define KB_LEFT 75
#define KB_PLUS 43
#define KB_MINUS 45
#define KB_HOME 36
#define KB_ESC 27

// отрисовать график
void Draw(Borders);
// нарисовать сетку
void MakeGrid();

// вычислить границы отрисовки
Borders CalcGraphBorders(Dot*, int, Circle*, int);
// 




/*
//void dot(HDC hDC, int x, int y, COLORREF Color);
void clearscreen(int red, int green, int blue);
void DrawAxis(Limits, Scale, int*, int*);
void DrawGrid(Limits, Scale, int, int);
// вычислить границы отрисовки
void CalculateBorders(Limits*, Dot*, Circle*, int, int);
void Draw(Dot*, Circle*, int, int);
*/
