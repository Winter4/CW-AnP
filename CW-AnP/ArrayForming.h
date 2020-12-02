#pragma once
#include <iostream>

// ��������� �������
struct MyArray { 
	float* items; // ��������
	int number; // ���-�� ���������
};

// ������������ ������ (parent)
void FormArray(MyArray* array);

// ������ ������ � ���������� (child 1)
void EnterArrayByKeyboard(MyArray array);
// ����������� ������ (child 2)
void RandomArray(MyArray array);
// ������� ������ �� ����� (child 3)
void GetArrayFromFile(MyArray array);

// �������� ������
float FloatRandom(float leftBorder, float rightBorder);

// ___________________________________________________________

void FormArray(MyArray* array)
{
	// ���� ���-�� ���������
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
	printf("\nThe array: \n");
	for (int i = 0; i < array.number; i++) {
		// (b - a) * rand() / RAND_MAX + a
		array.items[i] = FloatRandom(-2 * array.number, 2 * array.number);
		printf("Item %d: %.1f \n", i + 1, array.items[i]);
	}
}

void GetArrayFromFile(MyArray array)
{
	FILE* file;
	char fileName[12];
	do {
		printf("Enter the file name: "); // ���� ����� �����
		gets_s(fileName);

		file = fopen(fileName, "r");
	} while (file == NULL);

	int i = 0;
	while (i < array.number && !(feof(file))) { // ���������� �� �����
		fscanf(file, "%f", &array.items[i]);
		i++;
	}
	fclose(file);

	for (i; i < array.number; i++) // ������������ ��������
		array.items[i] = FloatRandom(-2 * array.number, 2 * array.number);

	printf("\nThe array: \n"); // ����� � �������
	for (int i = 0; i < array.number; i++)
		printf("Item %d: %.1f \n", i + 1, array.items[i]);
}

float FloatRandom(float leftBorder, float rightBorder)
{
	return (rightBorder - leftBorder) * rand() / RAND_MAX + leftBorder;
}