#include "stdint.h"
#include "qSortLibrary.h"
void QuickSort(int* unsortedVector, int first, int last)
{

	int i = first, j = last; 		// ��������� ��������� �� �������� �����
	int pivot, temp;

	pivot = unsortedVector[(first + last) / 2];		// ����������� �������, �� ����� ����������� ������ ����� �������� ��������

	do {
		while (unsortedVector[i] < pivot) i++;
		while (unsortedVector[j] > pivot) j--;

		if (i <= j) {
			if (i < j) {
				temp = unsortedVector[i];
				unsortedVector[i] = unsortedVector[j];
				unsortedVector[j] = temp;
			}
			i++;
			if (j > 0) j--;
		}
	} while (i <= j);


	if (i < last) QuickSort(unsortedVector, i, last);
	if (first < j) QuickSort(unsortedVector, first, j);
}