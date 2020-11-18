#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Sorting.h"

void Sorting()
{
	Array array;

	// ввод кол-ва элементов
	printf(" Enter the items number: "); 
	scanf("%d", &array.number);
	// выделение памяти под элементы
	array.items = new float[array.number];

	FormArray(array); // сформировать массив
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

// __________________________ Формирование массива _________________________

void FormArray(Array array)
{
	printf("\nChoose the method of array forming \n 1 - Enter by keyboard \n 2 - Random \n 3 - Get from the file");
	printf("\n Your choice: ");
	int choice;
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		EnterArrayByKeyboard(array);
		break;
	case 2:
		RandomArray(array);
		break;
	case 3:
		GetArrayFromFile(array);
	}
}

void EnterArrayByKeyboard(Array array)
{
	printf("\n");
	for (int i = 0; i < array.number; i++) {
		printf(" Item %d: ", i + 1);
		scanf_s("%f", &array.items[i]);
	}
}

void RandomArray(Array array)
{
	printf("\nThe array: \n");
	for (int i = 0; i < array.number; i++) {
		// (b - a) * rand() / RAND_MAX + a
		array.items[i] = FloatRandom(-2 * array.number, 2 * array.number);
		printf("Item %d: %.1f \n", i + 1, array.items[i]);
	}
}

void GetArrayFromFile(Array array)
{
	FILE* file;
	char fileName[12];
	do {
		printf("Enter the file name: "); // ввод имени файла
		gets_s(fileName);

		file = fopen(fileName, "r");
	} while (file == NULL);

	int i = 0;
	while (i < array.number && !(feof(file))) { // считывание из файла
		fscanf(file, "%f", &array.items[i]);
		i++;
	}
	fclose(file);

	for (i; i < array.number; i++) // дозаполнение рандомом
		array.items[i] = FloatRandom(-2 * array.number, 2 * array.number);
	
	printf("\nThe array: \n"); // вывод в консоль
	for (int i = 0; i < array.number; i++)
		printf("Item %d: %.1f \n", i + 1, array.items[i]);
}

// _______________________ Служебные функции ___________________________

void PrintAll(Array array)
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

float FloatRandom(float leftBorder, float rightBorder)
{
	return (rightBorder - leftBorder) * rand() / RAND_MAX + leftBorder;
}

// _______________________ Задание по варианту _________________________

void SortArray(Array array)
{
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

void PrintByStep(Array array)
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

