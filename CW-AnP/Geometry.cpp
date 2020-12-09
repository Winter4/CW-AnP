#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Geometry.h"

HWND wnd;
HDC dc;

RECT windowSize; // размеры окна

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

	// количество прямых, которые можно провести через n точек
	int linesNumber = dotsNumber * (dotsNumber - 1) / 2;
	Line* lines = new Line[linesNumber];
	// массив всех возможных прямых через 2 точки
	Line chosenLine = MyTask(dots, circles, dotsNumber, circlesNumber, lines); // основная функция
	
	// __________________________________ Графика _____________________________

	Draw(dots, dotsNumber, circles, circlesNumber, lines, linesNumber);

	delete[] dots;
	delete[] circles;
	delete[] lines;
	
	printf("\n");
	system("pause");
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

Line MyTask(Dot* dots, Circle* circles, int dotsNumber, int circlesNumber, Line* lines)
{
	int minCrossedCircles = INT_MAX; // значение пересеченных окружностей для ответа

	Line chosenLine = { 0 };
	int linesCount = 0;
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

				// сохраняем две точки, через которые проходит прямая
				chosenLine = { dots[i].x, dots[i].y, dots[j].x, dots[j].y };
			}

			lines[linesCount] = { dots[i].x, dots[i].y, dots[j].x, dots[j].y };
			linesCount++;
		}

	printf("\n\nThe line which crosses the less circles passes dots: (%d; %d) and (%d; %d) \n", 
		chosenLine.x1, chosenLine.y1, chosenLine.x2, chosenLine.y2);
	printf("Crossed circles: %d", minCrossedCircles);

	return chosenLine;
}

// _______________________________ Графика _______________________________________

void Draw(Dot* dots, int dotsNumber, Circle* circles, int circlesNumber, Line* lines, int linesNumber)
{
	wnd = GetConsoleWindow(); // получаем окно
	MoveWindow(wnd, 50, 20, 1366, 768, NULL); // двигаем окно на экране

	// страж 
	if (!wnd) {
		printf("Can't get window of console!\n");
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

	HBRUSH backgroundBrush = CreateSolidBrush(RGB(255, 255, 255));; // кисть для фона
	HPEN backgroundPen = CreatePen(0, 0, RGB(255, 255, 255));

	// получаем размеры окна
	GetClientRect(wnd, &windowSize);

	Dot windowCenter; // реальная точка в центре экрана
	windowCenter.x = (windowSize.right - windowSize.left) / 2;
	windowCenter.y = (windowSize.bottom - windowSize.top) / 2;

	// границы, в которых лежат точки и окружности (прямые не в счёт)
	Borders drawBorders = CalcGraphBorders(dots, dotsNumber, circles, circlesNumber); // границы графика
	Parameter scale = CalcScale(drawBorders); // масштаб нереальные\реальные координаты

	int key = 0;
	do {
		system("cls");

		SelectObject(dc, backgroundBrush);
		SelectObject(dc, backgroundPen);
		Rectangle(dc, windowSize.left, windowSize.top, windowSize.right, windowSize.bottom);

		MakeGrid(drawBorders, MakeAxis(drawBorders, scale), scale);
		MakeElements(windowCenter, windowSize, dots, dotsNumber, circles, circlesNumber, drawBorders, lines, linesNumber);

		key = _getch();
	} while (key != KB_ESC);

	ReleaseDC(wnd, dc);
}

void MakeGrid(Borders drawBorders, Parameter axis, Parameter scale)
{
	HPEN gridPen = CreatePen(PS_DOT, 2, RGB(200, 200, 200));
	SelectObject(dc, gridPen);

	LOGFONT lFont = { 0 };
	lFont.lfHeight = 12;
	lFont.lfWeight = 900;
	lFont.lfWidth = 8;

	char S[25];
	strcpy((char*)lFont.lfFaceName, "Calibri");

	HFONT font = CreateFontIndirect(&lFont);

	SetTextColor(dc, RGB(0, 0, 0));
	SetBkColor(dc, RGB(255, 255, 255));

	TextOutA(dc, axis.y - DELTA, windowSize.top + DELTA - 8, (LPCSTR)"Y", 1);
	TextOutA(dc, windowSize.right - DELTA + 2, axis.x - 5, (LPCSTR)"X", 1);

	Parameter realCoords = { 0 };
	float dx = (drawBorders.x_max - drawBorders.x_min) / 10;

	for (float x = drawBorders.x_min; x <= drawBorders.x_max; x += dx) {
		realCoords.x = DELTA + scale.x * (x - drawBorders.x_min);

		MoveToEx(dc, realCoords.x, windowSize.top, 0);
		LineTo(dc, realCoords.x, windowSize.bottom);

		sprintf(S, "%.1f", x);
		TextOutA(dc, realCoords.x, axis.x + 8, (LPCSTR)S, strlen(S));
	}

	float dy = (drawBorders.y_max - drawBorders.y_min) / 10;
	for (float y = drawBorders.y_min + DELTA; y <= drawBorders.x_max; y += dy) {
		realCoords.y = windowSize.bottom - scale.y * (y - drawBorders.y_min) - DELTA;
;

		MoveToEx(dc, windowSize.left, realCoords.y, 0);
		LineTo(dc, windowSize.right + DELTA, realCoords.y);

		sprintf(S, "%.1f", y);
		TextOutA(dc, axis.y + 5, realCoords.y, (LPCSTR)S, strlen(S));
	}

	DeleteObject(gridPen);
	DeleteObject(font);
}

Parameter MakeAxis(Borders drawBorders, Parameter scale)
{
	HPEN axisPen = CreatePen(PS_SOLID, 2, RGB(70, 70, 70));
	SelectObject(dc, axisPen);

	Parameter axis = { 0 };
	if (drawBorders.x_min * drawBorders.x_max < 0)
		axis.y = fabs(drawBorders.x_min) * scale.x + DELTA;
	else
		if (drawBorders.x_min >= 0)
			axis.y = DELTA;
		else
			axis.y = windowSize.right - DELTA;

	if (drawBorders.y_min * drawBorders.y_max < 0)
		axis.x = windowSize.bottom - fabs(drawBorders.y_min) * scale.y - DELTA;
	else
		if (drawBorders.y_min >= 0)
			axis.x = windowSize.bottom - DELTA;
		else
			axis.x = DELTA;

	// ось X
	MoveToEx(dc, DELTA, axis.x, 0);
	LineTo(dc, windowSize.right - DELTA, axis.x);

	// ось Y
	MoveToEx(dc, axis.y, windowSize.top, 0);
	LineTo(dc, axis.y, windowSize.bottom);

	DeleteObject(axisPen);
	return axis;
}

void MakeElements(Dot windowCenter, RECT windowSize, Dot* dots, int dotsNumber, Circle* circles, int circlesNumber, Borders drawBorders, Line* lines, int linesNumber)
{
	HPEN linePen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	SelectObject(dc, linePen);
	Parameter scale = CalcScale(drawBorders);

	float dx = (drawBorders.x_max - drawBorders.x_min) / 200;

	Parameter realCoords = { 0 };
	// рисование прямых
	for (int i = 0; i < linesNumber; i++) {
		realCoords.x = windowSize.left + DELTA;
		// значение функции в левой\правой части графика
		// в этой строке - в левой части
		float func = (drawBorders.x_min - lines[i].x1) / (lines[i].y2 - lines[i].y1) * (lines[i].x2 - lines[i].x1) + lines[i].y1;
		realCoords.y = windowSize.bottom - (func - drawBorders.y_min) * scale.y - DELTA;
		MoveToEx(dc, realCoords.x, realCoords.y, 0);

		realCoords.x = windowSize.left + (drawBorders.x_max - drawBorders.x_min) * scale.x + DELTA;
		// в этой строке - в правой
		func = (drawBorders.x_max - lines[i].x1) / (lines[i].y2 - lines[i].y1) * (lines[i].x2 - lines[i].x1) + lines[i].y1;
		realCoords.y = windowSize.bottom - (func - drawBorders.y_min) * scale.y - DELTA;
		LineTo(dc, realCoords.x, realCoords.y);
	}

	HPEN dotPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(dc, dotPen);
	// рисование точек
	for (int i = 0; i < dotsNumber; i++) {
		realCoords.x = windowSize.left + (dots[i].x - drawBorders.x_min) * scale.x + DELTA;
		realCoords.y = windowSize.bottom - (dots[i].y - drawBorders.y_min) * scale.y - DELTA;

		MoveToEx(dc, realCoords.x, realCoords.y, 0);
		LineTo(dc, realCoords.x, realCoords.y);
	}

	SelectObject(dc, GetStockObject(NULL_BRUSH));
	for (int i = 0; i < circlesNumber; i++) {
		realCoords.x = windowSize.left + (circles[i].x - drawBorders.x_min) * scale.x + DELTA;
		realCoords.y = windowSize.bottom - (circles[i].y - drawBorders.y_min) * scale.y - DELTA;
		Ellipse(dc, realCoords.x - circles[i].r * scale.x, realCoords.y + circles[i].r * scale.y, realCoords.x + circles[i].r * scale.x, realCoords.y - circles[i].r * scale.y);
	}
}

Parameter CalcScale(Borders drawBorders)
{
	Parameter scale = { 0 };
	scale.x = (windowSize.right - 2 * DELTA) / (drawBorders.x_max - drawBorders.x_min);
	scale.y = (windowSize.bottom - 2 * DELTA) / (drawBorders.y_max - drawBorders.y_min);

	if (scale.x > scale.y) scale.y = scale.x;
	else scale.x = scale.y;

	return scale;
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