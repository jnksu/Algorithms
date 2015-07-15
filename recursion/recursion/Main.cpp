//Çý¶¯³ÌÐò
#include "Debug.h"
#include <stdio.h>
#include <stdlib.h>
#include "recursion.h"

int main(int argc, char ** argv)
{
	int arr[] = {4,5,6,1,-12,789,-5,8782,0};
	int * temp = (int *)malloc(sizeof(int) * 9);
	
	MergeSort(arr, 0, 8, temp);

	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
}
