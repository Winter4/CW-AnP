#include <iostream>

struct Array { // ��������� �������
	float* items; // ��������
	int number; // ���-�� ���������
};

//�������� �������
void HandleFile();

// ������������ ������ (parent)
void FormArray(Array*);
// ������ ������ � ���������� (child 1)
void EnterArrayByKeyboard(Array);
// ����������� ������ (child 2)
void RandomArray(Array);
// �������� ������
float FloatRandom(float, float);

// ������� ������ � ����
void WriteArrayToFile(Array, FILE*);
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