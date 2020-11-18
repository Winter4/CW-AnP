#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "time.h"

#include "Geometry.h"
#include "Sorting.h"
#include "HandleFile.h"

int main() 
{
	srand(time(0));
	//Geometry();
	//Sorting();
	HandleFile();

	printf("\n");
	system("pause");
	return 0;
}