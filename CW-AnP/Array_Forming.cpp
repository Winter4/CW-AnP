#include "Array_Forming.h"

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
		printf("Enter the file name: "); 
		gets_s(fileName);

		file = fopen(fileName, "r");
	} while (file == NULL);

	int i = 0;
	while (i < array.number && !(feof(file))) { 
		fscanf(file, "%f", &array.items[i]);
		i++;
	}
	fclose(file);

	for (i; i < array.number; i++) // дозаполнение рандомом
		array.items[i] = FloatRandom(-2 * array.number, 2 * array.number);
	
	printf("\nThe array: \n"); // вывод
	for (int i = 0; i < array.number; i++)
		printf("Item %d: %.1f \n", i + 1, array.items[i]);
}

float FloatRandom(float leftBorder, float rightBorder)
{
	return (rightBorder - leftBorder) * rand() / RAND_MAX + leftBorder;
}