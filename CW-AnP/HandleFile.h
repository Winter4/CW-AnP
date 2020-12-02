#pragma once

#include <iostream>
#include "ArrayForming.h"

//�������� �������
void HandleFile();

// ������������ ������ (parent)
void FormArray(MyArray*);

// ������� ������ � ����
void WriteArrayToFile(MyArray, FILE*);
// ������� �� ��������
void MyTask(FILE*, int*);
// ����� ������� ��������������
float ArithmeticMean(FILE*);
// ����� (max + min) / 2
float HalfOfMaxPlusMin(FILE*);
// �������� �����; itemToDelete - ����� ��������, ������� ����� �������,
// itemsNumber - ���������� ��������� �������
void FileLinearShift(FILE*, int, int*);

// ������� ���� �� �����
void PrintFile(FILE*);