#pragma once
#include <iostream>

// ��������� �������
struct MyArray { 
	float* items; // ��������
	int number; // ���-�� ���������
};

// ������������ ������ (parent)
void FormArray(MyArray* array);

// ������ ������ � ���������� (child 1)
void EnterArrayByKeyboard(MyArray array);
// ����������� ������ (child 2)
void RandomArray(MyArray array);
// ������� ������ �� ����� (child 3)
void GetArrayFromFile(MyArray array);

// �������� ������
float FloatRandom(float leftBorder, float rightBorder);

// ___________________________________________________________
