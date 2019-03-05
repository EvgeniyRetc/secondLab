#include "stdint.h"
#include <iostream>
#include <fstream>

#define SORTED_FILE_FLAG false
#define GENERATED_FILE_FLAG true

void TestRandomVector() {
	//random vector
	int vector[10];
	GenerateRandomVector(vector, 10, 255);
	std::cout << "Test1: random vecror: " << std::endl;
	std::cout << "Before: " << std::endl;
	ShowVector(vector, 10);
	QuickSort(vector, 0, 10 - 1);
	std::cout << "After: " << std::endl;
	ShowVector(vector, 10);
}

void TestSortedVector(){
	//sorted vector
	int vector[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::cout << "Test2: sorted vector: " << std::endl;
	std::cout << "Before: " << std::endl;
	ShowVector(vector, 10);
	QuickSort(vector, 0, 10 - 1);
	std::cout << "After: " << std::endl;
	ShowVector(vector, 10);
}

void Test1not1Vector() {
	// -1, 1 numbers 
	int vector[10] = { -1, -1, -1, 1, 1, -1, 1, -1, -1, 1 };
	std::cout << "Test3: -1, 1 numbers : " << std::endl;
	std::cout << "Before: " << std::endl;
	ShowVector(vector, 10);
	QuickSort(vector, 0, 10 - 1);
	std::cout << "After: " << std::endl;
	ShowVector(vector, 10);
}

void TestReverseVector() {
	//reverse sorted vector
	int vector[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	std::cout << "Test4: reverse sorted vector: " << std::endl;
	std::cout << "Before: " << std::endl;
	ShowVector(vector, 10 - 1);
	QuickSort(vector, 0, 10 - 1);
	std::cout << "After: " << std::endl;
	ShowVector(vector, 10);
}

void TestEmptyVector(){
	//empty vector 
	int vector[1] = {};
	std::cout << "Test5: empty vector: " << std::endl;
	std::cout << "Before: " << std::endl;
	ShowVector(vector, 0);
	QuickSort(vector, 0, 0);
	std::cout << "After: " << std::endl;
	ShowVector(vector, 0);
}


void TestFunctions() {

	TestRandomVector();
	TestSortedVector();
	Test1not1Vector();
	TestReverseVector();
	TestEmptyVector();
}


int main()
{
	__declspec(dllexport) void QuickSort(int* unsortedVector, int first, int last)
		HINSTANCE qSortLib;
	qSortLib = LoadLibrary("qSortLibrary.dll");
	if (!qSortLib) {
		printf("Ошибка: не могу найти qSortLibrary.dll");
		return 0;
	}
	DllFunc = (void(*)(int* unsortedVector)(int first)(int last))GetProcAdress(qSortLib, "QuickSort");
	if (!DllFunc) {
		printf("Ошибка: не могу найти qSortLibrary.dll")
		return 0;
	}
	const uint32_t NUMBER_OF_ELEMENTS = 10; // длинна массива
	int vector[10];
	GenerateRandomVector(vector, NUMBER_OF_ELEMENTS, 255);
	WriteToWorkFile(vector, NUMBER_OF_ELEMENTS, GENERATED_FILE_FLAG);
	ReadFromFile(vector, NUMBER_OF_ELEMENTS, "genetaredVector.txt");
	QuickSort(vector, 0, NUMBER_OF_ELEMENTS - 1);
	WriteToWorkFile(vector, NUMBER_OF_ELEMENTS, SORTED_FILE_FLAG);
	TestFunctions();
	std::cout << std::endl;
	std::cout << "______________________\n";
	std::cout << "THE END\n";
}
//