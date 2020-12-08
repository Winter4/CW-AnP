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
			PrintArray(array);
			break;
		case 2:
			SortByStep(array);
			break;
		}
	} while (choice != 1 && choice != 2);

	printf("\n");
	system("pause");

	delete[] array.items;
}

// _______________________ Служебные функции ___________________________

void PrintArray(MyArray array)
{
	printf("\nThe array: \n");
	for (int i = 0; i < array.number; i++) 
		printf("Item %d: %.1f \n", i + 1, array.items[i]);
}

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
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD Buf;
	COORD coords = { 0, 0 };
	

	// сортировка
	int flag;
	do {
		flag = 0; 
		for (int i = 0; i < array.number - 1; i++) {
			if (i < array.number / 2) {
				if (!(array.items[i] < array.items[i + 1]))
					continue;
			}
			else {
				if (!(array.items[i] > array.items[i + 1]))
					continue;
			}
			SwapTwoItems(&(array.items[i]), &(array.items[i + 1]));


			coords.Y = 22;
			coords.X = (array.items[i]);
			printf("%.1f ", array.items[i]);
			FillConsoleOutputAttribute(hStdout, 0x47, 3, coords, &Buf);
		}
			
	} while (flag != 0);
}

