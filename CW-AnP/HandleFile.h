#pragma once

#include "ArrayForming.h"

//основная функция
void HandleFile();
void HandleFile();
void HandleFile();
void HandleFile();
void HandleFile();

// занести массив в файл
void WriteArrayToFile(MyArray, FILE*);
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