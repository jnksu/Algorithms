// ��̬�滮�㷨ͷ�ļ�
#ifndef DYNAMIC_H_
#define DYNAMIC_H_

// ����ʹ�õ�ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>

// ��������

// ��������
// ����Ԫ�ظ���
const int L = 7;
int LookupChain(int sl, int el, int (*memo)[L], int (*loc)[L], int * src_mat);
int MemoizedMatrixChain(int count_Mat, int (*memo)[L], int (*loc)[L], int * src_mat);
void TraceBack(int sl, int el, int (*loc)[L]);
#endif