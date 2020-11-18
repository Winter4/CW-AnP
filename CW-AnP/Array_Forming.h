#include <iostream>

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
// флотовый рандом
float FloatRandom(float, float);
