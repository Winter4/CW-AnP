#define _CRT_SECURE_NO_WARNINGS

#include "HandleFile.h"

void HandleFile()
{
	Array array = {0};
	FormArray(&array); // формируем массив

	// создаём файл
	FILE* file;
	char fileName[12];

	// вводим его имя
	printf("Enter the file name: ");
	gets_s(fileName);

	// открываем файл для записи, записываем массив в файл
	file = fopen(fileName, "wb");
	WriteArrayToFile(array, file);
	fclose(file);

	// открываем файл для чтения и записи
	file = fopen(fileName, "rb+");
	MyTask(file, (&array.number));
	PrintFile(file);
	fclose(file);

	printf("\n");
	system("pause");
}

void FormArray(Array* array)
{
	printf(" Enter the number of array items: ");
	scanf("%d", &array->number);
	(*array).items = new float[(*array).number];

	printf("\nChoose the method of array forming \n 1 - Enter by keyboard \n 2 - Random");
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

float FloatRandom(float leftBorder, float rightBorder)
{
	return (rightBorder - leftBorder) * rand() / RAND_MAX + leftBorder;
}

void WriteArrayToFile(Array array, FILE* file)
{
	for (int i = 0; i < array.number; i++)
		fprintf(file, "%8.1f\t", array.items[i]);
}

void MyTask(FILE* file, int* itemsNumber)
{
	float arithmeticMean = ArithmeticMean(file);
	float halfOfMaxPlusMin = HalfOfMaxPlusMin(file);

	// предполагаем, что они не могут быть равны
	if (arithmeticMean > halfOfMaxPlusMin) {
		for (int i = 0; i < *itemsNumber; i++) {
			float a = 0;

			fseek(file, i * 8, SEEK_SET);
			fscanf(file, "%f", a);
			if (a > halfOfMaxPlusMin && a < arithmeticMean) {
				FileLinearShift(file, i, itemsNumber);
				i--;
			}
		}
	}
	else {
		for (int i = 0; i < *itemsNumber; i++) {
			float a = 0;

			fseek(file, i * 8, SEEK_SET);
			fscanf(file, "%f", a);
			if (a > arithmeticMean && a < halfOfMaxPlusMin) {
				FileLinearShift(file, i, itemsNumber);
				i--;
			}
		}
	}
}

float ArithmeticMean(FILE* file)
{
	int i = 0;
	float sum = 0;
	while (!(feof(file))) {
		float tmp;
		fscanf(file, "%f", &tmp);

		sum += tmp;
		i++;
	}

	return sum / i;
}

float HalfOfMaxPlusMin(FILE* file)
{
	float max = INT_MIN, min = INT_MAX;
	while (!(feof(file))) {
		float tmp;
		fscanf(file, "%f", &tmp);

		if (tmp > max) max = tmp;
		if (tmp < min) min = tmp;
	}

	return (max + min) / 2;
}

void FileLinearShift(FILE* file, int itemToDelete, int* itemsNumber)
{
	fpos_t nowPosition = 0;

	for (int i = itemToDelete; i < *itemsNumber; i++, nowPosition += 8) {
		nowPosition = i * 8.0;
		float a;

		fseek(file, nowPosition + 8, SEEK_SET);
		fscanf(file, "%f", &a);
		fseek(file, nowPosition, SEEK_SET);
		fprintf(file, "%8.2f", a);
	}
	(*itemsNumber)--;
}

void PrintFile(FILE* file)
{
	rewind(file);
	printf("\nThe file: \n");
	while (!(feof(file))) {
		float a;
		fscanf(file, "%f", &a);
		printf("%.1f\t");
	}
}