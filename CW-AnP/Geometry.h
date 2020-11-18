/*#pragma once
#include <iostream>
#include "windows.h"
#include "math.h"

void Geometry();

struct Dot {
	int x; // ������� �����
	int y; // �������� �����
};

struct Circle {
	int x; // ������� ������
	int y; // �������� ������
	float r; // radius
};

struct Limits { // ������� ��������� �������
	int left;
	int right;
	int top;
	int bot;
};

struct Scale {
	float x;
	float y;
} scale;

// ������������ ������ ����� 
void formDots(Dot*, int);
// ������������ ������ �����������
void formCircles(Circle*, int);

// ������ ����� ����� � ���������� (��������� �) 
void enterDotsByKeyboard(Dot*, int); 
// �������� ������������� ������ �����(��������� �)
void randomDots(Dot*, int); 
// ����� ����� �� ����� � ����������� ����������� (��������� �)
void getDotsFromFile(Dot*, int);

// ������ ������ ����������� � ���������� (��. B)
void enterCirclesByKeyboard(Circle*, int);
// ����������� ���������� (��. B)
void randomCircles(Circle*, int);
// ����� ���������� �� ����� (��. B)
void getCirclesFromFile(Circle*, int);

void myTask(Dot*, Circle*, int, int);

// __________________________ ������� _____________________________

//void dot(HDC hDC, int x, int y, COLORREF Color);
void clearscreen(int red, int green, int blue);
void DrawAxis(Limits, Scale, int*, int*);
void DrawGrid(Limits, Scale, int, int);
// ��������� ������� ���������
void CalculateBorders(Limits*, Dot*, Circle*, int, int);
void Draw(Dot*, Circle*, int, int);
*/