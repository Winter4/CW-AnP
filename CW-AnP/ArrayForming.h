#pragma once
#include <iostream>

// структура массива
struct MyArray { 
	float* items; // элементы
	int number; // кол-во элементов
};

// сформировать массив (parent)
void FormArray(MyArray* array);

// ввести массив с клавиатуры (child 1)
void EnterArrayByKeyboard(MyArray array);
// зарандомить массив (child 2)
void RandomArray(MyArray array);
// считать массив из файла (child 3)
void GetArrayFromFile(MyArray array);

// вывести массив (в строку)
void PrintArray(MyArray);
// флотовый рандом
float FloatRandom(float leftBorder, float rightBorder);

// ___________________________________________________________
