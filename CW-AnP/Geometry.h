#pragma once
#include <iostream>
#include "windows.h"
#include "math.h"
#include "conio.h"

// �������� �������
void Geometry();

// ______________________ ��������� _______________________

// �����
struct Dot {
	int x; // ������� �����
	int y; // �������� �����
};

// ���������� �� ������ � �������
struct Circle {
	int x; // ������� ������
	int y; // �������� ������
	float r; // radius
};

// ������, ���������� ����� 2 �����
struct Line {
	int x1;
	int y1;
	int x2;
	int y2;
};

// ������������ ������ ����� 
void FormDots(Dot*, int);
// ������������ ������ �����������
void FormCircles(Circle*, int);

// ������ ����� ����� � ���������� (��������� �) 
void EnterDotsByKeyboard(Dot*, int); 
// �������� ������������� ������ �����(��������� �)
void RandomDots(Dot*, int); 
// ����� ����� �� ����� � ����������� ����������� (��������� �)
void GetDotsFromFile(Dot*, int);

// ������ ������ ����������� � ���������� (��. B)
void EnterCirclesByKeyboard(Circle*, int);
// ����������� ���������� (��. B)
void RandomCircles(Circle*, int);
// ����� ���������� �� ����� (��. B)
void GetCirclesFromFile(Circle*, int);

Line MyTask(Dot*, Circle*, int, int, Line*);

// __________________________ ������� _____________________________

// �������
struct Borders {
	float x_min;
	float x_max;

	float y_min;
	float y_max;
};

// �������
struct Parameter {
	float x;
	float y;
};

HWND wnd;
HDC dc;

#define DELTA 25 // 1 �������� (���-��)
#define EDGE_HALF DELTA * 10 // �������� ��� ����� = 250

#define KB_RIGHT 77
#define KB_LEFT 75
#define KB_PLUS 43
#define KB_MINUS 45
#define KB_HOME 36
#define KB_ESC 27

// ���������� ������
void Draw(Dot*, int, Circle*, int, Line*, int);
// ���������� �����
void MakeGrid(Borders, Parameter axis, Parameter scale);
// ���������� ���
Parameter MakeAxis(Borders, Parameter scale);
// ���������� ��������
void MakeElements(Dot, RECT, Dot*, int, Circle*, int, Borders, Line*, int);

// ��������� �������
Parameter CalcScale(Borders);
// ��������� ������� ���������
Borders CalcGraphBorders(Dot*, int, Circle*, int);
