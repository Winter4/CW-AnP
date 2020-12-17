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

void DrawSmallTales(HDC dc, int chosenTale, int dy, const char* msg1, const char* msg2, const char* msg3)
{
	HBRUSH menuBrushLarge = CreateSolidBrush(RGB(169, 169, 169));
	HBRUSH menuBrushSmall = CreateSolidBrush(RGB(230, 230, 230));
	HBRUSH menuBrushChosen = CreateSolidBrush(RGB(218, 165, 32));

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

	PrintText(dc, 60, 40 + dy * 0, msg1);
	PrintText(dc, 60, 40 + dy * 1, msg2);
	PrintText(dc, 60, 40 + dy * 2, msg3);
}

void DrawLargeTale(HDC dc)
{
	HBRUSH menuBrushLarge = CreateSolidBrush(RGB(169, 169, 169));
	HBRUSH menuBrushSmall = CreateSolidBrush(RGB(230, 230, 230));
	HBRUSH menuBrushChosen = CreateSolidBrush(RGB(218, 165, 32));

	SelectObject(dc, menuBrushChosen);
	Rectangle(dc, 260, 30, 850, 150);
	DeleteObject(menuBrushChosen);

	SelectObject(dc, menuBrushSmall);
	Rectangle(dc, 280, 50, 830, 130);
	DeleteObject(menuBrushSmall);
}

int main() 
{
	srand(time(0));
	setlocale(LC_ALL, "russian");
	HWND wnd = GetConsoleWindow();
	HDC dc = GetDC(wnd);

	

	int dy = 60;
	int chosenTask = 0, chosenMethod = 0;
	int key = 0;

	while (key != KB_ESC) {
		system("cls");
		
		DrawSmallTales(dc, chosenTask, dy, "Сортировка", "Бинарные файлы", "Геометрия");
		DrawLargeTale(dc);

		switch (chosenTask) {
		case 0:
			PrintText(dc, 290, 63, "Задана последовательность чисел длиной N. Первые N/2 чисел упорядочить");
			PrintText(dc, 290, 83, "по убыванию, а последние N/2 по возрастанию методом обмена.");
			break;

		case 1:
			PrintText(dc, 290, 63, "Удалить элементы, значения которых лежат на интервале между");
			PrintText(dc, 290, 83, "средним арифметическим значением и значением (max + min) / 2.");
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

		if (key != KB_ENTER) {
			switch (key) {
			case NUMPAD_UP:
				if (chosenTask == 0) chosenTask = 2;
				else chosenTask--;
				break;

			case NUMPAD_DOWN:
				if (chosenTask == 2) chosenTask = 0;
				else chosenTask++;
				break;
			}
		}
		else {
			while (key != KB_ESC) {
				system("cls");

				DrawSmallTales(dc, chosenMethod, dy, "Ввод с клавиатуры", "Рандом", "Ввод с файла");
				do {
					key = _getch();
				} while (!(key == NUMPAD_UP || key == NUMPAD_DOWN || key == KB_ESC || key == KB_ENTER));

				if (key != KB_ENTER) {
					switch (key) {
					case NUMPAD_UP:
						if (chosenMethod == 0) chosenMethod = 2;
						else chosenMethod--;
						break;

					case NUMPAD_DOWN:
						if (chosenMethod == 2) chosenMethod = 0;
						else chosenMethod++;
						break;
					}
				}
				else {
					system("cls");
					switch (chosenTask) {
					case 0:
						Sorting(chosenMethod + 1);
						break;

					case 1:
						HandleFile(chosenMethod + 1);
						break;

					case 2:
						Geometry(chosenMethod + 1);
						break;
					}
				}
			}
			chosenMethod = chosenTask = 0;
			key = NULL;
		}
	}
	
	return 0;
}