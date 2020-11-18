/*#pragma once
#include <iostream>
#include "windows.h"
#include "math.h"

void Geometry();

struct Dot {
	int x; // абсциса точки
	int y; // ордината точки
};

struct Circle {
	int x; // абсциса центра
	int y; // ордината центра
	float r; // radius
};

struct Limits { // границы отрисовки графики
	int left;
	int right;
	int top;
	int bot;
};

struct Scale {
	float x;
	float y;
} scale;

// сформировать массив точек 
void formDots(Dot*, int);
// сформировать массив окружностей
void formCircles(Circle*, int);

// ввести масив точек с клавиатуры (множество А) 
void enterDotsByKeyboard(Dot*, int); 
// случайно сгенерировать массив точек(множество А)
void randomDots(Dot*, int); 
// взять точки из файла и зарандомить недостающие (множество А)
void getDotsFromFile(Dot*, int);

// ввести массив окружностей с клавиатуры (мн. B)
void enterCirclesByKeyboard(Circle*, int);
// зарандомить окружности (мн. B)
void randomCircles(Circle*, int);
// взять окружности из файла (мн. B)
void getCirclesFromFile(Circle*, int);

void myTask(Dot*, Circle*, int, int);

// __________________________ Графика _____________________________

//void dot(HDC hDC, int x, int y, COLORREF Color);
void clearscreen(int red, int green, int blue);
void DrawAxis(Limits, Scale, int*, int*);
void DrawGrid(Limits, Scale, int, int);
// вычислить границы отрисовки
void CalculateBorders(Limits*, Dot*, Circle*, int, int);
void Draw(Dot*, Circle*, int, int);
*/