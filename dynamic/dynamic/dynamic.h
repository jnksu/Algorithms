// 动态规划算法头文件
#ifndef DYNAMIC_H_
#define DYNAMIC_H_

// 函数使用的头文件
#include <stdio.h>
#include <stdlib.h>

// 函数声明

// 矩阵链乘
// 矩阵元素个数
const int L = 7;
int LookupChain(int sl, int el, int (*memo)[L], int (*loc)[L], int * src_mat);
int MemoizedMatrixChain(int count_Mat, int (*memo)[L], int (*loc)[L], int * src_mat);
void TraceBack(int sl, int el, int (*loc)[L]);
#endif