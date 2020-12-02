#pragma once
#include <iostream>
#include "Struct.h"

#include "math.h"
#include "conio.h"

// �������� ������
float FloatRandom(float leftBorder, float rightBorder)
{
	return (rightBorder - leftBorder) * rand() / RAND_MAX + leftBorder;
}

// ������ ������ � ����������
void EnterArrayByKeyboard(MyArray array)
{
	printf("\n");
	for (int i = 0; i < array.number; i++) {
		printf(" Item %d: ", i + 1);
		scanf_s("%f", &array.items[i]);
	}
}

// ����������� ������
void RandomArray(MyArray array)
{
	printf("\nThe array: \n");
	for (int i = 0; i < array.number; i++) {
		// (b - a) * rand() / RAND_MAX + a
		array.items[i] = FloatRandom(-2 * array.number, 2 * array.number);
		printf("Item %d: %.1f \n", i + 1, array.items[i]);
	}
}