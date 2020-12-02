#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "conio.h"

#include "Sorting.h"

void Sorting()
{
	MyArray array = { 0 };

	FormArray(&array); // сформировать массив
	SortArray(array); // отсортировать массив (задание по варианту)
	printf ("\nThe array has been sorted.");
	
	printf("\nChoose the method of array printing: ");
	printf("\n1 - Print all \n2 - Print by step \n");
	
	int choice;
	do {
		printf(" Your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			PrintAll(array);
			break;
		case 2:
			PrintByStep(array);
			break;
		}
	} while (choice != 1 && choice != 2);

	printf("\n");
	system("pause");

	delete[] array.items;
}

// _______________________ Служебные функции ___________________________

void PrintAll(MyArray array)
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

void SortArray(MyArray array)
{
	// передать диапазон и флаг, в какую сторону
	// 0 - n/2; n/2 + 1 - n
	int flag;
	do {
		flag = 0; // обнуляем флаг перед заходом на цикл
		for (int i = 0; i < array.number / 2 - 1; i++)
			if (array.items[i + 1] > array.items[i]) {
				SwapTwoItems(&(array.items[i + 1]), &(array.items[i]));
				flag++;
			}

		for (int i = array.number / 2; i < array.number - 1; i++)
			if (array.items[i + 1] < array.items[i]) {           // по возрастанию
				SwapTwoItems(&(array.items[i + 1]), &(array.items[i]));
				flag++;
			}
	} while (flag != 0);
}

void PrintByStep(MyArray array)
{
	printf("\nPress 'N' button (next) to print one item; \nPress 'S' button (skip) to print all items. \nThe array: ");
	int key = 0, i = 0;
	printf("\n");
	while (i < array.number) {
		key = _getch();

		switch (key) {
		case 110: // клавиша N
			printf("Item %d: %.1f \n", i, array.items[i++]);
			break;
		case 115: // клавиша S
			for (i; i < array.number; i++)
				printf("Item %d: %.1f \n", i + 1, array.items[i]);
			break;
		}
	}
}

