#include "stdint.h"
#include <iostream>
#include <fstream>
#include "LibraryReadWrite.h"

void WriteToWorkFile(int* dataIn, uint32_t lengthVector, bool choiceFileFlag) {
	std::ofstream out;
	if (choiceFileFlag) {
		out.open("genetaredVector.txt");
	}
	else {
		out.open("sortedVector.txt");
	}
	if (out.is_open())
	{
		for (uint32_t i = 0; i < lengthVector; i++) {
			out << dataIn[i] << std::endl;
		}
	}
	out.close();//закрываем файл
}

void ReadFromFile(int* vectorFromFile, uint32_t lengthVector, std::string fileName) {
	std::ifstream in(fileName);
	if (in.is_open()) {
		vectorFromFile = new int[lengthVector];
		for (uint32_t i = 0; i < lengthVector; i++) {
			in >> vectorFromFile[i];
		}
	}
	in.close(); //закрываем файл
}