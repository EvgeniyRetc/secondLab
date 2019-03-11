#include "stdint.h"
#include <iostream>
#include <fstream>
#include "LibraryReadWrite.h"
#include <windows.h> 
#include <locale>
#include "gtest/gtest.h"

#define SORTED_FILE_FLAG false
#define GENERATED_FILE_FLAG true
typedef void (*Q_SORT_FUNCTION)(int*, int, int);

void QsortFromDll(int* vector, int first, int last) {
	char* libPath = "D:/C++/secondLab/build/src/LibrarySort/Debug/qSortLibrary.dll";
	HINSTANCE qSortLib;
	qSortLib = LoadLibrary(libPath);
	if (!qSortLib) {
		std::cout << "Ошибка: не могу найти qSortLibrary.dll" << std::endl;
		return;
	}

	Q_SORT_FUNCTION DllQuickSort = (void(*)(int*, int, int))GetProcAddress(qSortLib, "QuickSort");
	if (!DllQuickSort) {
		std::cout << "Ошибка: не могу найти qSortLibrary.dll" << std::endl;
		return;
	}
	DllQuickSort(vector, first, last);
	FreeLibrary(qSortLib);
}

void TestRandomVector() {
	//random vector
	int vector[10];
	GenerateRandomVector(vector, 10, 255);
	std::cout << "Test1: random vecror: " << std::endl;
	std::cout << "Before: " << std::endl;
	ShowVector(vector, 10);
	QsortFromDll(vector, 0, 10 - 1);
	std::cout << "After: " << std::endl;
	ShowVector(vector, 10);
}

void TestSortedVector(){
	//sorted vector
	int vector[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::cout << "Test2: sorted vector: " << std::endl;
	std::cout << "Before: " << std::endl;
	ShowVector(vector, 10);
	QsortFromDll(vector, 0, 10 - 1);
	std::cout << "After: " << std::endl;
	ShowVector(vector, 10);
}

void Test1not1Vector() {
	// -1, 1 numbers 
	int vector[10] = { -1, -1, -1, 1, 1, -1, 1, -1, -1, 1 };
	std::cout << "Test3: -1, 1 numbers : " << std::endl;
	std::cout << "Before: " << std::endl;
	ShowVector(vector, 10);
	QsortFromDll(vector, 0, 10 - 1);
	std::cout << "After: " << std::endl;
	ShowVector(vector, 10);
}

void TestReverseVector() {
	//reverse sorted vector
	int vector[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	std::cout << "Test4: reverse sorted vector: " << std::endl;
	std::cout << "Before: " << std::endl;
	ShowVector(vector, 10 - 1);
	QsortFromDll(vector, 0, 10 - 1);
	std::cout << "After: " << std::endl;
	ShowVector(vector, 10);
}

void TestEmptyVector(){
	//empty vector 
	int vector[1] = {};
	std::cout << "Test5: empty vector: " << std::endl;
	std::cout << "Before: " << std::endl;
	ShowVector(vector, 0);
	QsortFromDll(vector, 0, 0);
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


int main(){
	setlocale(LC_ALL, "Russian");
	char buffer[256];
	GetCurrentDirectory(sizeof(buffer), buffer);
	const uint32_t NUMBER_OF_ELEMENTS = 10; // длинна массива
	int vector[10];
	GenerateRandomVector(vector, NUMBER_OF_ELEMENTS, 255);
	WriteToWorkFile(vector, NUMBER_OF_ELEMENTS, GENERATED_FILE_FLAG);
	ReadFromFile(vector, NUMBER_OF_ELEMENTS, "genetaredVector.txt");
	QsortFromDll(vector, 0, NUMBER_OF_ELEMENTS - 1);
	WriteToWorkFile(vector, NUMBER_OF_ELEMENTS, SORTED_FILE_FLAG);
	TestFunctions();
	std::cout << std::endl;
	std::cout << "______________________\n";
	std::cout << "THE END\n";
}
//