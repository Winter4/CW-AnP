#pragma once

#include "ArrayForming.h"

//�������� �������
void HandleFile();
void HandleFile();
void HandleFile();
void HandleFile();
void HandleFile();

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