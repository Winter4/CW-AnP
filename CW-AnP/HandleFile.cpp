#define _CRT_SECURE_NO_WARNINGS
#include "HandleFile.h"

// fwrite
// fread

void HandleFile()
{
	
	MyArray array = {0};
	FormArray(&array); // формируем массив

	// создаём файл
	FILE* file;
	char fileName[12];

	// вводим его имя
	printf("Enter the file name: ");
	scanf("%s", &fileName);
	printf("%s", fileName);
	system("pause");
	// открываем файл для записи, записываем массив в файл
	file = fopen(fileName, "wb");
	if (file == NULL) {
		printf("File error!");
		return;
	}
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

void WriteArrayToFile(MyArray array, FILE* file)
{
	//for (int i = 0; i < array.number; i++)
		//fprintf(file, "%8.1f\t", array.items[i]);
		fwrite(array.items, sizeof(float), array.number, file);
}

void MyTask(FILE* file, int* itemsNumber)
{
	float arithmeticMean = ArithmeticMean(file);
	float halfOfMaxPlusMin = HalfOfMaxPlusMin(file);

	float max, min;
	// предполагаем, что они не могут быть равны
	if (arithmeticMean > halfOfMaxPlusMin) {
		max = arithmeticMean;
		min = halfOfMaxPlusMin;
	}
	else {
		max = halfOfMaxPlusMin;
		min = arithmeticMean;
	}

	// fwrite fread
	
	for (int i = 0; i < *itemsNumber; i++) {
		float a = 0;

		fseek(file, i * 8, SEEK_SET);
		fread(&a, sizeof(float), 1, file);
		//fscanf(file, "%f", a);
		if (a > min && a < max) {
			FileLinearShift(file, i, itemsNumber);
			i--;
		}
	}
}

float ArithmeticMean(FILE* file)
{
	int i = 0;
	float sum = 0;
	while (!(feof(file))) {
		float tmp;
		//fscanf(file, "%f", &tmp);
		fread(&tmp, sizeof(float), 1, file);

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
		//fscanf(file, "%f", &tmp);
		fread(&tmp, sizeof(float), 1, file);

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
		//fscanf(file, "%f", &a);
		fread(&a, sizeof(float), 1, file);
		fseek(file, nowPosition, SEEK_SET);
		//fprintf(file, "%8.2f", a);
		fwrite(&a, sizeof(float), 1, file);
	}
	(*itemsNumber)--;
}

void PrintFile(FILE* file)
{
	rewind(file);
	printf("\nThe file: \n");
	while (!(feof(file))) {
		float a;
		//fscanf(file, "%f", &a);
		fread(&a, sizeof(float), 1, file);
		printf("%.1f\t", a);
	}
}