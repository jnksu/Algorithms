// 实现头文件recursion中的算法 

#include "recursion.h" 
#include <stdio.h>
#include <stdlib.h>

//内部函数
static void swap(int * elem, int * elem1);
static   int partition(int * arr,   int start,   int end);
static void Merge(int * arr, int left, int mid, int right, int * temp);

//阶乘递归
long int factorial(int para)
{
	if (1 == para){
		return 0;
	}else{
		return para * factorial(para - 1);
	}
}

//斐波那契数列
long int Fibonacci(int para)
{
	if (para <= 1){
		return 0;
	}else{
		return Fibonacci(para - 1) + Fibonacci(para + 2);
	}
}

//Ackerman函数
long int Ackerman(int para, int para1)
{
	if (1 == para && 0 == para1){
		return 2;
	}else if(0 == para && para1 >= 0){
		return 1;
	}else if(para >= 2 && 0 == para1){
		return para + 2;
	}else if (para >= 1 && para1 >= 1){
		return Ackerman(Ackerman(para - 1, para1), para1 - 1);
	}else{
		return 0;
	}
}

//全排列问题
void Perm(int * arr,   int start,   int end)
{
	if (start == end){
		for (  int index = 0; index <= end; index++){
			printf("%d ", *(arr + index));
		}
		putchar('\n');
	}else{
		for (  int index = start; index <= end; index++){
			swap((arr + start), (arr + index));
			Perm(arr, start + 1, end);
			swap((arr + start), (arr + index));
		}
	}
}
//整数划分问题
int IntegerDivision(int num, int max)
{
	if (num < 1 || max < 1){
		return 0;
	}

	if (1 == num || 1 == max){
		return 1;
	}else if(num < max){
		return IntegerDivision(num, num);
	}else if (num == max){
		return IntegerDivision(num, max - 1) + 1;
	}else{
		return IntegerDivision(num, max - 1) + IntegerDivision(num - max, max);
	}
}

//二分搜索
int BinarySearch(int * arr, const int key,   int size)
{
	int start = 0;
	int end = size - 1;
	int mid = (start + end) / 2;

	while (start <= end){
		if (key == *(arr + mid)){
			return mid;
		}
		if (key > *(arr + mid)){
			start = mid + 1;
		}
		if (key < *(arr + mid)){
			end = mid - 1;
		}
	}

	return -1;
}

//合并排序
void MergeSort(int * arr, int left, int right, int * temp)
{
	//至少有2个元素
	if (left < right){
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid, temp);
		MergeSort(arr, mid + 1, right, temp);
		Merge(arr, left, mid, right, temp);
	}
}

//快速排序
void QuickSort(int arr[],   int start,   int end)
{
	if (start < end){
		  int loc = partition(arr, start, end);
		QuickSort(arr, start, loc - 1);
		QuickSort(arr, loc + 1, end);
	}
}

//交换元素
static void swap(int * elem, int * elem1)
{
	int temp = *elem;
	*elem = *elem1;
	*elem1 = temp;
}

//一次划分
static int partition(int arr[],   int start,   int end)
{
	int head_index = start;
	int tail_index = end + 1;
	int key = arr[start];
	//将小于key的元素交换到左边区域
	//将大于key的元素交换到右边区域
	for (;;){
		while (arr[++head_index] < key && head_index < end)
				continue;
		while (arr[--tail_index] > key)
				continue;
		if (head_index >= tail_index){
			break;
		}
		swap((arr + head_index), (arr + tail_index));
	}
	arr[start] = arr[tail_index];
	arr[tail_index] = key;

	return tail_index;
}

//将两个有序序列 [left, mid], [mid + 1, right] 合并
static void Merge(int * arr, int left, int mid, int right, int * temp)
{
	int index = left;
	int index1 = mid + 1;
	int index2 = 0;

	//比较并复制元素
	while (index <= mid && index1 <= right){
		if (arr[index] < arr[index1]){
			temp[index2++] = arr[index++];
		}
		else{
			temp[index2++] = arr[index1++];
		}
	}

	//将剩余元素复制到新的数组中
	while (index <= mid){
		temp[index2++] = arr[index++];
	}

	while (index1 <= right){
		temp[index2++] = arr[index1++];
	}

	//将合并好的数组重新放回原数组
	for (int index3 = 0; index3 < index2; index3++){
			arr[left + index3] = temp[index3];
	}
}
