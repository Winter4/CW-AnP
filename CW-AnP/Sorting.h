#pragma once

#include <iostream>

#include "math.h"
#include "conio.h"

#include "ArrayForming.h"

// ������� ����������
void Sorting();

// ������������ ������ (parent)
void FormArrayMini(MyArray*);
// ������� ������ �� ����� (child 3)
void GetArrayFromFile(MyArray);

// ������� ������
void PrintAll(MyArray);
// ���� ���� ��������
void SwapTwoItems(float*, float*);
// �������� ������

// ���������� �������
void SortArray(MyArray);
// ����� �� ������
void PrintByStep(MyArray);

