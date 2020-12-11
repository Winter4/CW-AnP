#pragma once
#include <iostream>
#include "ArrayForming.h"

//�������� �������
void HandleFile(int);

// ������� ������ � ����
void WriteArrayToFile(MyArray, FILE*);
// ������� �� ��������
void MyTask(FILE*, int*);
// ����� ������� ��������������
float ArithmeticMean(FILE*);
// ����� (max + min) / 2
float HalfOfMaxPlusMin(FILE*);
// �������� �����; int itemToDelete - ����� ��������, ������� ����� �������,
// int* itemsNumber - ���������� ��������� �������
void FileLinearShift(FILE*, int, int*);

// ������� ���� �� �����
void PrintFile(FILE*);