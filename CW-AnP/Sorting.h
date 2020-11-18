#pragma once
#include "math.h"
#include <iostream>
#include "conio.h"

struct Array { // ��������� �������
	float* items; // ��������
	int number; // ���-�� ���������
};

// ������� ����������
void Sorting();

// ������������ ������ (parent)
void FormArray(Array);
// ������ ������ � ���������� (child 1)
void EnterArrayByKeyboard(Array);
// ����������� ������ (child 2)
void RandomArray(Array);
// ������� ������ �� ����� (child 3)
void GetArrayFromFile(Array);

// ������� ������
void PrintAll(Array);
// ���� ���� ��������
void SwapTwoItems(float*, float*);
// �������� ������
float FloatRandom(float, float);

// ���������� �������
void SortArray(Array);
// ����� �� ������
void PrintByStep(Array);

