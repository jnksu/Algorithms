// ʵ��ͷ�ļ�recursion�е��㷨 

#include "recursion.h" 
#include <stdio.h>
#include <stdlib.h>

//�ڲ�����
static void swap(int * elem, int * elem1);
static   int partition(int * arr,   int start,   int end);
static void Merge(int * arr, int left, int mid, int right, int * temp);

//�׳˵ݹ�
long int factorial(int para)
{
	if (1 == para){
		return 0;
	}else{
		return para * factorial(para - 1);
	}
}

//쳲���������
long int Fibonacci(int para)
{
	if (para <= 1){
		return 0;
	}else{
		return Fibonacci(para - 1) + Fibonacci(para + 2);
	}
}

//Ackerman����
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

//ȫ��������
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
//������������
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

//��������
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

//�ϲ�����
void MergeSort(int * arr, int left, int right, int * temp)
{
	//������2��Ԫ��
	if (left < right){
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid, temp);
		MergeSort(arr, mid + 1, right, temp);
		Merge(arr, left, mid, right, temp);
	}
}

//��������
void QuickSort(int arr[],   int start,   int end)
{
	if (start < end){
		  int loc = partition(arr, start, end);
		QuickSort(arr, start, loc - 1);
		QuickSort(arr, loc + 1, end);
	}
}

//����Ԫ��
static void swap(int * elem, int * elem1)
{
	int temp = *elem;
	*elem = *elem1;
	*elem1 = temp;
}

//һ�λ���
static int partition(int arr[],   int start,   int end)
{
	int head_index = start;
	int tail_index = end + 1;
	int key = arr[start];
	//��С��key��Ԫ�ؽ������������
	//������key��Ԫ�ؽ������ұ�����
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

//�������������� [left, mid], [mid + 1, right] �ϲ�
static void Merge(int * arr, int left, int mid, int right, int * temp)
{
	int index = left;
	int index1 = mid + 1;
	int index2 = 0;

	//�Ƚϲ�����Ԫ��
	while (index <= mid && index1 <= right){
		if (arr[index] < arr[index1]){
			temp[index2++] = arr[index++];
		}
		else{
			temp[index2++] = arr[index1++];
		}
	}

	//��ʣ��Ԫ�ظ��Ƶ��µ�������
	while (index <= mid){
		temp[index2++] = arr[index++];
	}

	while (index1 <= right){
		temp[index2++] = arr[index1++];
	}

	//���ϲ��õ��������·Ż�ԭ����
	for (int index3 = 0; index3 < index2; index3++){
			arr[left + index3] = temp[index3];
	}
}
