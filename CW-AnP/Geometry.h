#pragma once

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

// �������
struct Scale {
	float x;
	float y;
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

void MyTask(Dot*, Circle*, int, int);

// __________________________ ������� _____________________________

// ������� ��������� �������
struct DrawArea {
	int left;
	int right;
	int top;
	int bot;
};

#define DX 20
#define DY 20

#define KB_RIGHT 77
#define KB_LEFT 75
#define KB_PLUS 43
#define KB_MINUS 45
#define KB_ESC 27

/*
HDC hDC;
HWND hWnd;
RECT Rect;
HPEN hPen, hOldPen;
HBRUSH hBrush, hOldBrush;
HFONT hFont, hOldFont;
LOGFONT Lf = { 0 };
*/

/*
//void dot(HDC hDC, int x, int y, COLORREF Color);
void clearscreen(int red, int green, int blue);
void DrawAxis(Limits, Scale, int*, int*);
void DrawGrid(Limits, Scale, int, int);
// ��������� ������� ���������
void CalculateBorders(Limits*, Dot*, Circle*, int, int);
void Draw(Dot*, Circle*, int, int);
*/