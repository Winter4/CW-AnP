#pragma once
#include "math.h"
#include <iostream>
#include "conio.h"

struct Array { // структура массива
	float* items; // элементы
	int number; // кол-во элементов
};

// задание сортировки
void Sorting();

// сформировать массив (parent)
void FormArray(Array);
// ввести массив с клавиатуры (child 1)
void EnterArrayByKeyboard(Array);
// зарандомить массив (child 2)
void RandomArray(Array);
// считать массив из файла (child 3)
void GetArrayFromFile(Array);

// вывести массив
void PrintAll(Array);
// свап двух значений
void SwapTwoItems(float*, float*);
// флотовый рандом
float FloatRandom(float, float);

// сортировка массива
void SortArray(Array);
// вывод по шагово
void PrintByStep(Array);

