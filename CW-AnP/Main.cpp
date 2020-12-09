#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "time.h"

#include "Geometry.h"
#include "Sorting.h"
#include "HandleFile.h"

#define NUMPAD_UP 56
#define NUMPAD_DOWN 50
#define KB_ENTER 13

void PrintText(HDC dc, int x, int y, const char* s)
{
	LOGFONT lf = { 0 };
	HFONT font = CreateFontIndirect(&lf);;
	SetTextColor(dc, RGB(0, 0, 0));
	SetBkColor(dc, RGB(218, 165, 32));

	SelectObject(dc, font);
	TextOutA(dc, x, y, (LPCSTR)s, strlen(s));
	DeleteObject(font);
}

void DrawSmallTales(HDC dc, HBRUSH menuBrushLarge, HBRUSH menuBrushSmall, HBRUSH menuBrushChosen, int chosenTale, int dy)
{
	SelectObject(dc, menuBrushLarge);
	for (int i = 0; i < 3; i++)
		Rectangle(dc, 20, 20 + dy * i, 220, 80 + dy * i);
	DeleteObject(menuBrushLarge);

	SelectObject(dc, menuBrushChosen);
	Rectangle(dc, 20, 20 + dy * chosenTale, 220, 80 + dy * chosenTale);
	DeleteObject(menuBrushChosen);

	SelectObject(dc, menuBrushSmall);
	for (int i = 0; i < 3; i++)
		Rectangle(dc, 30, 30 + dy * i, 210, 70 + dy * i);
	DeleteObject(menuBrushSmall);
}

void DrawLargeTale(HDC dc, HBRUSH menuBrushChosen, HBRUSH menuBrushSmall)
{
	SelectObject(dc, menuBrushChosen);
	Rectangle(dc, 260, 30, 850, 130);
	DeleteObject(menuBrushChosen);

	SelectObject(dc, menuBrushSmall);
	Rectangle(dc, 280, 50, 830, 110);
	DeleteObject(menuBrushSmall);
}

int main() 
{
	setlocale(LC_ALL, "russian");
	HWND wnd = GetConsoleWindow();
	HDC dc = GetDC(wnd);

	HBRUSH menuBrushLarge = CreateSolidBrush(RGB(169, 169, 169));
	HBRUSH menuBrushSmall = CreateSolidBrush(RGB(230, 230, 230));
	HBRUSH menuBrushChosen = CreateSolidBrush(RGB(218, 165, 32));

	int dy = 60;
	int chosenTale = 0;
	int key;

	while (true) {
		system("cls");
		
		DrawSmallTales(dc, menuBrushLarge, menuBrushSmall, menuBrushChosen, chosenTale, dy);
		
		PrintText(dc, 60, 40 + dy * 0, "Сортировка");
		PrintText(dc, 60, 40 + dy * 1, "Работа с файлом");
		PrintText(dc, 60, 40 + dy * 2, "Геометрия");

		DrawLargeTale(dc, menuBrushChosen, menuBrushSmall);

		switch (chosenTale) {
		case 0:
			PrintText(dc, 290, 80, "Задана последовательность чисел длиной N. Первые N/2 чисел упорядочить");
			PrintText(dc, 290, 80, "по убыванию, а последние N/2 по возрастанию методом обмена.");
			break;

		case 1:
			PrintText(dc, 290, 60, "Удалить элементы, значения которых лежат на интервале между");
			PrintText(dc, 290, 80, "средним арифметическим значением и значением (max + min) / 2.");
			break;

		case 2:
			PrintText(dc, 290, 60, "На плоскости заданы множество точек А и множество окружностей В.");
			PrintText(dc, 290, 80, "Найти две такие различные точки из А, чтобы прямая, проходящая через них,");
			PrintText(dc, 290, 100, "пересекала наименьшее количество окружностей.");
			break;
		}

		do {
			key = _getch();
		} while (!(key == NUMPAD_UP || key == NUMPAD_DOWN || key == KB_ESC || key == KB_ENTER));

		if (key == KB_ENTER) {
			system("cls");
			switch (chosenTale) {
			case 0:
				Sorting();
				break;

			case 1:
				HandleFile();
				break;

			case 2:
				Geometry();
				break;
			}
		}
		else {
			switch (key) {
			case NUMPAD_UP:
				if (chosenTale == 0) chosenTale = 2;
				else chosenTale--;
				break;

			case NUMPAD_DOWN:
				if (chosenTale == 2) chosenTale = 0;
				else chosenTale++;
				break;

			case KB_ESC:
				return 0;
				break;
			}
		}
	}
	
	return 0;
}