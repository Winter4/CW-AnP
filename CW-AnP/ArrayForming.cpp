#define _CRT_SECURE_NO_WARNINGS
#include "ArrayForming.h"

void FormArray(MyArray* array)
{
	// ввод кол-ва элементов
	printf(" Enter the number of array items: ");
	scanf("%d", &array->number);

	array->items = new float[array->number];

	printf("\nChoose the method of array forming \n 1 - Enter by keyboard \n 2 - Random \n 3 - Get from the file");
	printf("\n Your choice: ");
	int choice;
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		EnterArrayByKeyboard(*array);
		break;
	case 2:
		RandomArray(*array);
		break;
	case 3:
		GetArrayFromFile(*array);
		break;
	}
}

void EnterArrayByKeyboard(MyArray array)
{
	printf("\n");
	for (int i = 0; i < array.number; i++) {
		printf(" Item %d: ", i + 1);
		scanf_s("%f", &array.items[i]);
	}
}

void RandomArray(MyArray array)
{
	for (int i = 0; i < array.number; i++) 
		array.items[i] = FloatRandom(-2 * array.number, 2 * array.number);

	printf("The array: \n");
	PrintArray(array);
	printf("\n");
}

void GetArrayFromFile(MyArray array)
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

	printf("The array: \n");
	PrintArray(array);
}

void PrintArray(MyArray array)
{
	for (int i = 0; i < array.number; i++)
		printf("%8.1f", array.items[i]);
	printf("\n");
}

float FloatRandom(float leftBorder, float rightBorder)
{
	return (rightBorder - leftBorder) * rand() / RAND_MAX + leftBorder;
}