#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Geometry.h"

HWND wnd;
HDC dc;

RECT windowSize; // размеры окна
	

HBRUSH backgroundBrush;

void Geometry() 
{
	
	printf("The <Geometry> task. \n");
	printf(" Please enter the amount of dots (A plenty): "); // ввод количества точек А
	int dotsNumber; // кол-во точек А
	do {
		scanf_s("%d", &dotsNumber);
	} while (dotsNumber < 2);

	Dot* dots; // массив точек А
	dots = new Dot[dotsNumber];
	FormDots(dots, dotsNumber); // формирование массива точек А

	// _______________________________________________________________________

	printf("\n\n Please enter the amount of circles: "); // ввод количества окружностей В
	int circlesNumber; // кол-во окружностей В
	do {
		scanf_s("%d", &circlesNumber);
	} while (circlesNumber < 1);

	Circle* circles; // массив окружностей B
	circles = new Circle[circlesNumber];
	FormCircles(circles, circlesNumber); // формирование массива окружностей В (вершины)

	MyTask(dots, circles, dotsNumber, circlesNumber); 
	
	// __________________________________ Графика _____________________________

	wnd = GetConsoleWindow(); // получаем окно
	MoveWindow(wnd, 50, 20, 1500, 800, NULL); // двигаем окно на экране

	// страж 
	if (!wnd) { 
		printf("Can't get hWnd of console!\n");
		system("pause");
		return;
	}

	dc = GetDC(wnd); // получаем дескриптор окна
	// страж
	if (!dc) {
		printf("Can't get device context!\n");
		system("pause");
		return;
	}
	
	// получаем размеры окна
	GetClientRect(wnd, &windowSize);

	Borders 
		graphBorders = CalcGraphBorders(dots, dotsNumber, circles, circlesNumber), // границы графика
		drawBorders = graphBorders; // границы отрисовки
	
	backgroundBrush = CreateSolidBrush(RGB(255, 255, 255));
	int key;
	do {
		Draw(graphBorders);
		key = _getch();

		switch (key) {
		case KB_RIGHT:
			drawBorders.x_min += DX;
			drawBorders.x_max += DX;
			break;

		case KB_LEFT:
			drawBorders.x_min -= DX;
			drawBorders.x_max -= DX;
			break;

		case KB_PLUS:
			if (drawBorders.x_min + DX != drawBorders.x_max - DX) {
				drawBorders.x_min += DX;
				drawBorders.x_max -= DX;
			}
			break;

		case KB_MINUS: 
			drawBorders.x_min -= DX;
			drawBorders.x_max += DX;
			break;

		case KB_HOME:
			drawBorders = graphBorders;
			break;
		}
	} while (key != KB_ESC);

	ReleaseDC(wnd, dc);
	return;

//	delete[] dots;
//	delete[] circles;
	
}

// __________________ Обработка точек ______________________

void FormDots(Dot* dots, int dotsNumber)
{
	printf("\nChoose the method of dots forming \n 1 - Enter by keyboard \n 2 - Random \n 3 - Get from the file");
	printf("\n Your choice: ");
	int choice;
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		EnterDotsByKeyboard(dots, dotsNumber);
		break;
	case 2:
		RandomDots(dots, dotsNumber);
		break;
	case 3:
		GetDotsFromFile(dots, dotsNumber);
		break;
	}
}

void EnterDotsByKeyboard(Dot* dots, int dotsNumber)
{
	printf("\n");
	for (int i = 0; i < dotsNumber; i++) {
		printf(" Dot %d: ", i + 1);
		scanf_s("%d%d", &dots[i].x, &dots[i].y);
	}
}

void RandomDots(Dot* dots, int dotsNumber)
{
	printf("\nDots:");
	for (int i = 0; i < dotsNumber; i++) {
		dots[i].x = -2.0 * dotsNumber + 2.0 * dotsNumber * rand() / RAND_MAX;
		dots[i].y = -2.0 * dotsNumber + 2.0 * dotsNumber * rand() / RAND_MAX;
		printf("\nDot %d: %d %d", i + 1, dots[i].x, dots[i].y);
	}
}

void GetDotsFromFile(Dot* dots, int dotsNumber)
{
	FILE* file;
	char fileName[12];
	do {
		printf("Enter the file name: "); // ввод имени файла
		gets_s(fileName);

		file = fopen(fileName, "r");
	} while (file == NULL);

	int i = 0;
	while (i < dotsNumber && !(feof(file))) { // считывание из файла
		fscanf(file, "%d%d", &dots[i].x, &dots[i].y);
		i++;
	}
	fclose(file);

	// проверка на непарное число в файле
	if (dots[i - 1].y < -2000 || dots[i - 1].y > 2000) dots[i - 1].y = -2.0 * dotsNumber + 2.0 * dotsNumber * rand() / RAND_MAX;
	for (i; i < dotsNumber; i++) { // дозаполнение рандомом
		dots[i].x = -2.0 * dotsNumber + 2.0 * dotsNumber * rand() / RAND_MAX;
		dots[i].y = -2.0 * dotsNumber + 2.0 * dotsNumber * rand() / RAND_MAX;
	}

	printf("\nThe plenty of dots: \n"); // вывод в консоль
	for (int i = 0; i < dotsNumber; i++)
		printf("\nDot %d: %d %d", i + 1, dots[i].x, dots[i].y);
}

// ______________________ Обработка окружностей ___________________________

void FormCircles(Circle* circles, int circlesNumber)
{
	printf("\nChoose the method of circles forming \n 1 - Enter by keyboard \n 2 - Random \n 3 - Get from the file");
	printf("\n Your choice: ");
	int choice;
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		EnterCirclesByKeyboard(circles, circlesNumber);
		break;
	case 2:
		RandomCircles(circles, circlesNumber);
		break;
	case 3:
		GetCirclesFromFile(circles, circlesNumber);
		break;
	}
}

void EnterCirclesByKeyboard(Circle* circles, int circlesNumber)
{
	printf("\n");
	for (int i = 0; i < circlesNumber; i++) {
		printf(" Circle %d (x y r): ", i + 1);
		scanf_s("%d%d%f", &circles[i].x, &circles[i].y, &circles[i].r);
	}
}

void RandomCircles(Circle* circles, int circlesNumber)
{
	printf("\nCircles:");
	for (int i = 0; i < circlesNumber; i++) {
		circles[i].x = -2.0 * circlesNumber + 2.0 * circlesNumber * rand() / RAND_MAX;
		circles[i].y = -2.0 * circlesNumber + 2.0 * circlesNumber * rand() / RAND_MAX;
		circles[i].r = 2.0 * circlesNumber * rand() / RAND_MAX;
		printf("\nCircle %d: %d %d %.1f", i + 1, circles[i].x, circles[i].y, circles[i].r);
	}
}

void GetCirclesFromFile(Circle* circles, int circlesNumber)
{
	FILE* file;
	char fileName[12];
	do {
		printf("Enter the file name (data format: x y r): "); // ввод имени файла
		gets_s(fileName);

		file = fopen(fileName, "r");
	} while (file == NULL);

	int i = 0;
	while (i < circlesNumber && !(feof(file))) { // считывание из файла
		fscanf(file, "%d%d%f", &circles[i].x, &circles[i].y, &circles[i].r);
		i++;
	}
	fclose(file);

	// проверка на непарное число в файле
	if (circles[i - 1].y < -2000 || circles[i - 1].y > 2000) circles[i - 1].y = -2.0 * circlesNumber + 2.0 * circlesNumber * rand() / RAND_MAX;
	if (circles[i - 1].r < -2000 || circles[i - 1].r > 2000) circles[i - 1].r = 2.0 * circlesNumber * rand() / RAND_MAX;
	for (i; i < circlesNumber; i++) { // дозаполнение рандомом
		circles[i].x = -2.0 * circlesNumber + 2.0 * circlesNumber * rand() / RAND_MAX;
		circles[i].y = -2.0 * circlesNumber + 2.0 * circlesNumber * rand() / RAND_MAX;
	}

	printf("\nThe plenty of circles: \n"); // вывод в консоль
	for (int i = 0; i < circlesNumber; i++)
		printf("Circle %d: %d %d   %.1f \n", i + 1, circles[i].x, circles[i].y, circles[i].r);
}

// ______________________ Задание по варианту ___________________________

void MyTask(Dot* dots, Circle* circles, int dotsNumber, int circlesNumber)
{
	int minCrossedCircles = INT_MAX; // значение пересеченных окружностей для ответа
	
	// структура прямой, проходящая через 2 точки, и которая будет в ответе
	struct Line { 		
		int x1;
		int y1;
		int x2;
		int y2;
	} line = { 0, 0, 0, 0 };

	for (int i = 0; i < dotsNumber; i++) // перебор прямых (т. 1)
		for (int j = i + 1; j < dotsNumber; j++) { // перебор прямых (т. 2)

			float // A, B, C - коф-ты уравнения прямой
				A = dots[j].y - dots[i].y,
				B = dots[i].x - dots[j].x,
				C = dots[i].y * dots[j].x - dots[j].y * dots[i].x;
			int crossedCircles = 0; // счетчик пересеченных окружностей

			for (int k = 0; k < circlesNumber; k++) { // перебор окружностей
				float distance = fabs(A * circles[k].x + B * circles[k].y + C) / sqrt(A * A + B * B);
				if (distance < circles[k].r)
					crossedCircles++;
			}

			if (crossedCircles < minCrossedCircles) {
				minCrossedCircles = crossedCircles; // сохраняем значение пер-ных окружностей

				line.x1 = dots[i].x; // сохраняем две точки, через которые проходит прямая
				line.y1 = dots[i].y;
				line.x2 = dots[j].x;
				line.y2 = dots[j].y;
			}
		}

	printf("\n\nThe line which crosses the less circles passes dots: (%d; %d) and (%d; %d) \n", line.x1, line.y1, line.x2, line.y2);
	printf("Crossed circles: %d", minCrossedCircles);
}

// _______________________________ Графика _______________________________________

void Draw(Borders drawBorders)
{
	system("cls");
	SelectObject(dc, backgroundBrush);
	Rectangle(dc, windowSize.left, windowSize.top, windowSize.right, windowSize.bottom);


}

void MakeGrid()
{
	HPEN gridPen = CreatePen(PS_DASH, 2, RGB(169, 169, 169));
}

Borders CalcGraphBorders(Dot* dots, int dotsNumber, Circle* circles, int circlesNumber)
{
	Borders example;
	example.x_max = example.y_max = INT_MIN;
	example.x_min = example.y_min = INT_MAX;

	for (int i = 0; i < dotsNumber; i++) {
		if (dots[i].x < example.x_min) example.x_min = dots[i].x;
		if (dots[i].x > example.x_max) example.x_max = dots[i].x;

		if (dots[i].y > example.y_max) example.y_max = dots[i].y;
		if (dots[i].y < example.y_min) example.y_min = dots[i].y;
	}

	for (int i = 0; i < circlesNumber; i++) {
		if (circles[i].x - circles[i].r < example.x_min) example.x_min = circles[i].x - circles[i].r;
		if (circles[i].x + circles[i].r > example.x_max) example.x_max = circles[i].x + circles[i].r;

		if (circles[i].y - circles[i].r < example.y_min) example.y_min = circles[i].x - circles[i].r;
		if (circles[i].y + circles[i].r > example.y_max) example.y_max = circles[i].x + circles[i].r;
	}

	return example;
}


/*
void clearscreen(int red, int green, int blue)
{
	hBrush = CreateSolidBrush(RGB(red, green, blue));
	SelectObject(hDC, hBrush);

	Rectangle(hDC, Rect.left, Rect.top, Rect.right + DX, Rect.bottom);

	DeleteObject(hBrush);
}

void DrawAxis(Limits limits, Scale scale, int* Osx, int* Osy)
{
	if (limits.left * limits.right < 0)
		*Osy = fabs(limits.left) * scale.x + DX;
	else
		if (limits.left >= 0)
			*Osy = DX;
		else
			*Osy = Rect.right - DX;

	if (limits.bot * limits.top < 0)
		*Osx = Rect.bottom - fabs(limits.bot) * scale.y - DY;
	else
		if (limits.bot >= 0)
			*Osx = Rect.bottom - DY;
		else
			*Osx = DY;

	hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));

	MoveToEx(hDC, DX, *Osx, NULL);
	LineTo(hDC, Rect.right - DX, *Osx);

	MoveToEx(hDC, *Osy, DY, NULL);
	LineTo(hDC, *Osy, Rect.bottom - DY);

	DeleteObject(hPen);
}

void DrawGrid(Limits limits, Scale scale, int Osx, int Osy)
{
	hPen = CreatePen(PS_DOT, 1, RGB(255, 0, 255));

	Lf.lfHeight = 12;
	Lf.lfWeight = 900;
	Lf.lfWidth = 8;

	CHAR S[25];

	strcpy((char*)Lf.lfFaceName, "Calibri");

	hFont = CreateFontIndirect(&Lf);

	SetTextColor(hDC, RGB(0, 0, 0));
	SetBkColor(hDC, RGB(255, 255, 255));

	TextOutA(hDC, Osy - 20, Rect.top + DY - 8, (LPCSTR)"Y", 1);
	TextOutA(hDC, Rect.right - DX + 2, Osx - 5, (LPCSTR)"X", 1);

	// строим саму сетку
	float y;
	int x_real, y_real;
	float dx = (limits.right - limits.left) / 10;
	RECT d;

	for (float x = limits.left; x <= limits.right; x += dx) {
		x_real = DX + scale.x * (x - limits.left);

		MoveToEx(hDC, x_real, Rect.top, NULL);
		LineTo(hDC, x_real, Rect.bottom);

		sprintf(S, "%.1f", x);
		TextOutA(hDC, x_real, Osx + 8, (LPCSTR)S, strlen(S));
	}

	float dy = (limits.top - limits.bot) / 10;
	for (y = limits.bot; y < limits.top + dy; y += dy) {

		y_real = Rect.bottom - scale.y * (y - limits.bot) - DY;

		MoveToEx(hDC, Rect.left, y_real, NULL);
		LineTo(hDC, Rect.right + DX, y_real);

		sprintf(S, "%.1f", y);
		TextOutA(hDC, Osy + 5, y_real, (LPCSTR)S, strlen(S));
	}

	DeleteObject(hPen);
	DeleteObject(hFont);
}

void CalculateBorders(Limits* limits, Dot* dots, Circle* circles, int dotsAmount, int circlesAmount)
{
	for (int i = 0; i < dotsAmount; i++) {
		if (dots[i].x < (*limits).left) (*limits).left = dots[i].x;
		if (dots[i].x > (*limits).right) (*limits).right = dots[i].x;

		if (dots[i].y > (*limits).top) (*limits).top = dots[i].y;
		if (dots[i].y < (*limits).bot) (*limits).bot = dots[i].y;
	}
	for (int i = 0; i < circlesAmount; i++) {
		if (circles[i].x - circles[i].r < (*limits).left) (*limits).left = circles[i].x - circles[i].r;
		if (circles[i].x + circles[i].r > (*limits).right) (*limits).right = circles[i].x + circles[i].r;

		if (circles[i].y - circles[i].r < (*limits).bot) (*limits).bot = circles[i].x - circles[i].r;
		if (circles[i].y + circles[i].r > (*limits).top) (*limits).top = circles[i].x + circles[i].r;
	}
}

void Draw(Dot* dots, Circle* circles, Limits limits, int dotsAmount, int circlesAmount)
{
	int Osx, Osy;
	int x_real, y_real;

	scale.x = (Rect.right - 2 * DX) / (limits.right - limits.left);
	scale.y = (Rect.bottom - 2 * DY) / (limits.top - limits.bot);

	SelectObject(hDC, hOldPen);

	system("cls");
	//clearscreen(255, 255, 255);
	DrawAxis(limits, scale, &Osx, &Osy);
	DrawGrid(limits, scale, Osx, Osy);

	float dx = (limits.right - limits.left) / 200;

	// цвет линий, стиль линий
	hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
	hOldPen = (HPEN)SelectObject(hDC, hPen);

	x_real = Rect.left + (x - leftLim) * x_scale + DX;
	y_real = Rect.bottom - (y - y_min) * y_scale - DY;

	MoveToEx(hDC, x_real, y_real, NULL); // начало графика

	// строим график
	do {
		x += dx;
		y = f(x);

		x_real = Rect.left + (x - leftLim) * x_scale + DX;
		y_real = Rect.bottom - (y - y_min) * y_scale - DY;

		LineTo(hDC, x_real, y_real);
	} while (x < rightLim - dx);

	DeleteObject(hPen);
}
*/