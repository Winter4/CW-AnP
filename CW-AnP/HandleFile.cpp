#define _CRT_SECURE_NO_WARNINGS
#include "HandleFile.h"

void HandleFile(int chosenMethod)
{
	MyArray array = {0};
	FormArray(&array, chosenMethod); // формируем массив

	// создаём файл
	FILE* file;
	char fileName[12];

	// вводим его имя
	printf("Enter the file name: ");
	scanf("%s", &fileName);

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
	if (file == NULL) {
		printf("File error!");
		return;
	}

	MyTask(file, (&array.number));
	PrintFile(file, array.number);
	fclose(file);

	printf("\n \n");
	system("pause");
}

void WriteArrayToFile(MyArray array, FILE* file)
{
	for (int i = 0; i < array.number; i++)
		fwrite(&array.items[i], sizeof(float), 1, file);
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
	
	printf("max - %.1f  min - %.1f \n", max, min);

	rewind(file);
	fpos_t nowPosition = 0;
	int i = 0;
	while (!feof(file)) {
		float a = 0; // буфер
		nowPosition = i * sizeof(float);
		
		fseek(file, nowPosition, SEEK_SET);
		fread(&a, sizeof(float), 1, file);

		if (a > min && a < max) {
			FileLinearShift(file, i, itemsNumber);
			i--;
		}

		i++;
	}
}

float ArithmeticMean(FILE* file)
{
	int i = 0;
	float sum = 0;
	rewind(file);
	while (!(feof(file))) {
		float tmp;
		fread(&tmp, sizeof(float), 1, file);

		sum += tmp;
		i++;
	}

	return sum / i;
}

float HalfOfMaxPlusMin(FILE* file)
{
	float max = INT_MIN, min = INT_MAX;

	rewind(file);
	while (!(feof(file))) {
		float tmp;
		fread(&tmp, sizeof(float), 1, file);

		if (tmp > max) max = tmp;
		if (tmp < min) min = tmp;
	}

	return (max + min) / 2;
}

void FileLinearShift(FILE* file, int itemToDelete, int* itemsNumber)
{	
	fpos_t nowPosition;
	float tmp = 0;

	for (int i = itemToDelete; i < *itemsNumber - 1; i++) {
		tmp = 0;
		nowPosition = i * sizeof(float); // позиция текущего элемента

		fseek(file, nowPosition + sizeof(float), SEEK_SET); // ставим курсор на позицию после текущего
		fread(&tmp, sizeof(float), 1, file); // считываем элемент после текущего

		fseek(file, nowPosition, SEEK_SET); // ставим курсор на позицию текущего
		fwrite(&tmp, sizeof(float), 1, file); // записываем в текущий элемент следующий элемент
	}
	
	(*itemsNumber)--;
}

void PrintFile(FILE* file, int itemsNumber)
{
	rewind(file);
	printf("\nThe file: \n");
	float tmp = 0;
	for (int i = 0; i < itemsNumber; i++) {
		fread(&tmp, sizeof(float), 1, file);
		printf("%8.1f", tmp);
	}
}