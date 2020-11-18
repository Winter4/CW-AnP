#include <iostream>

struct Array { // структура массива
	float* items; // элементы
	int number; // кол-во элементов
};

//основная функция
void HandleFile();

// сформировать массив (parent)
void FormArray(Array*);
// ввести массив с клавиатуры (child 1)
void EnterArrayByKeyboard(Array);
// зарандомить массив (child 2)
void RandomArray(Array);
// флотовый рандом
float FloatRandom(float, float);

// занести массив в файл
void WriteArrayToFile(Array, FILE*);
// задание по варианту
void MyTask(FILE*, int*);
// найти среднее арифметичсекое
float ArithmeticMean(FILE*);
// найти (max + min) / 2
float HalfOfMaxPlusMin(FILE*);
// линейный сдвиг; itemToDelete - номер элемента, который нужно удалить,
// itemsNumber - количество элементов массива
void FileLinearShift(FILE*, int, int*);

// вывести файл на экран
void PrintFile(FILE*);