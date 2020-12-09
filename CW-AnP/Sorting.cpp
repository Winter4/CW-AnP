#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "conio.h"

#include "Sorting.h"

void Sorting()
{
	MyArray array = { 0 };
	FormArray(&array); // сформировать массив
	
	printf("\nChoose the method of array printing: ");
	printf("\n1 - Print all \n2 - Print by step \n");
	
	int choice;
	do {
		printf(" Your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			SortArray(array); // отсортировать массив (задание по варианту)
			printf("The array: \n");
			PrintArray(array);
			break;
		case 2:
			SortByStep(array);
			break;
		}
	} while (choice != 1 && choice != 2);

	delete[] array.items;

	printf("\n");
	system("pause");

	return;
}

// _______________________ Служебные функции ___________________________



void SwapTwoItems(float* item1, float* item2)
{
	float tmp = *item1; // temporary - временный
	*item1 = *item2;
	*item2 = tmp;
}

// _______________________ Задание по варианту _________________________

void SortArray(MyArray array) {
	int flag;
	do {
		flag = 0; 
		for (int i = 0; i < array.number / 2 - 1; i++)
			if (array.items[i + 1] > array.items[i]) {
				SwapTwoItems(&(array.items[i + 1]), &(array.items[i]));
				flag++;
			}

		for (int i = array.number / 2; i < array.number - 1; i++)
			if (array.items[i + 1] < array.items[i]) {           
				SwapTwoItems(&(array.items[i + 1]), &(array.items[i]));
				flag++;
			}
	} while (flag != 0);
}

void SortByStep(MyArray array)
{
	system("cls");
	printf("The array: \n");
	PrintArray(array);

	// сортировка
	int flag;
	int* swappedIndex = new int[array.number]; // какие индексы нужно закрасить
	int y = 2; // высота рисования в консоли
	
	do {
		flag = 0;
		int swapCounter = 0; // счётчик кол-ва обменов
		// обнуляем индексы
		for (int i = 0; i < array.number; i++)
			swappedIndex[i] = 0;

		for (int i = 0; i < array.number - 1; i++) {
			// сортировка первой половины
			if (i < array.number / 2 - 1) {
				if (array.items[i] < array.items[i + 1]) {
					// флаг параллельно отслеживает кол-во свапнутых элементов
					SwapTwoItems(&(array.items[i]), &(array.items[i + 1]));
					flag++;
					// счётчик инкрементируется в квадратных скобках [] !!
					swappedIndex[swapCounter++] = i; 
					swappedIndex[swapCounter++] = i + 1;
				}
			}
			else {
				// если взяли индекс из первой половины
				if (i == array.number / 2 - 1) 
					continue;

				// сортировка второй половины
				if (array.items[i] > array.items[i + 1]) {
					SwapTwoItems(&(array.items[i]), &(array.items[i + 1]));
					flag++;
					// счётчик инкрементируется в квадратных скобках [] !!
					swappedIndex[swapCounter++] = i;
					swappedIndex[swapCounter++] = i + 1;
				}
			}
		}

		PrintArray(array);

		HANDLE hStdout;
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD Buf;
		for (int i = 0; i < swapCounter; i++) {
			COORD coords = { swappedIndex[i] * 8 + 3, y };
			FillConsoleOutputAttribute(hStdout, 0x47, 5, coords, &Buf);
		}
		
		
		y++;
		_getch();
	} while (flag != 0);

	delete[] swappedIndex;
}

