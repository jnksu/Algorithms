#include "dynamic.h"

// 矩阵连乘问题 备忘录实现
extern const int L;
// 初始化记忆矩阵
// 参数 count_Mat 为矩阵个数
// 参数 memo 为记忆矩阵,例 memo[1][2] 为从 矩阵1 到 矩阵2 的最少数乘次数
// 参数 loc  为位置矩阵,例 Loc[1][2] 为从  矩阵1 到 矩阵2 的最佳断开位置
// 参数 src_mat	为要进行计算的矩阵,例 A1 30*35 A2 35*15 A3 15*5 A4 5*10 A5 10*20 A6 20*25 sr_mat[0-6]={30,35,15,5,10,20,25}
int MemoizedMatrixChain(int count_Mat, int(*memo)[L], int(*loc)[L], int * src_mat)
{
	// 初始化记忆矩阵
	for (int i = 1; i <= count_Mat; i++)
	{
		for (int ii = 1; ii <= count_Mat; ii++){
			memo[i][ii] = 0;
		}
	}

	return LookupChain(1, count_Mat, memo, loc, src_mat);
}

// 寻找断开位置,计算最少数乘次数
// 参数 sl 为起始位置
// 参数 el 为终止位置
// 参数 memo 为记忆矩阵,例 memo[1][2] 为从 矩阵1 到 矩阵2 的最少数乘次数
// 参数 loc  为位置矩阵,例 Loc[1][2] 为从  矩阵1 到 矩阵2 的最佳断开位置
// 参数 src_mat	为要进行计算的矩阵,例 A1 30*35 A2 35*15 A3 15*5 A4 5*10 A5 10*20 A6 20*25 sr_mat[0-6]={30,35,15,5,10,20,25}
int LookupChain(int sl, int el, int(*memo)[L], int(*loc)[L], int * src_mat)
{
	// 如果记忆矩阵中存在相应的解
	if (memo[sl][el] > 0) return memo[sl][el];

	// 只有一个矩阵的时候,数乘次数为0
	if (sl == el) return 0;
	
	// 当起始位置为断开位置时
	int  val = LookupChain(sl, sl, memo, loc, src_mat) + LookupChain(sl + 1, el, memo, loc, src_mat) + src_mat[sl - 1] * src_mat[sl] * src_mat[el];
	loc[sl][el] = sl;

	// 寻找最优解
	for (int i = sl + 1; i < el; i++){
		int temp = LookupChain(sl, i, memo, loc, src_mat) + LookupChain(i + 1, el, memo, loc, src_mat) + src_mat[sl - 1] * src_mat[i] * src_mat[el];
		if (temp < val){
			val = temp;
			loc[sl][el] = i;
		}
	}

	// 存储最优解到记忆矩阵中
	memo[sl][el] = val;
	// 返回最优解
	return val;
}

// 输出断开位置
void TraceBack(int sl, int el, int(*loc)[L])
{
	if (sl == el){
		printf("A%d", sl);
	}else{
		printf("(");
		TraceBack(sl, loc[sl][el], loc);	// 从开始位置到最佳断开位置
		TraceBack(loc[sl][el] + 1, el, loc);	//从最佳断开位置到结束位置
		printf(")");
	}
}
