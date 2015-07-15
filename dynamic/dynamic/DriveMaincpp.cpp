// 动态规划问题,驱动函数
#include "debug.h"
#include "dynamic.h"

extern const int L;
int main(int argc, char ** argv)
{
	int src_mat[L] = { 30, 35, 15, 5, 10, 20, 25 };
	int (*loc)[L] = (int (*)[L])malloc(L * L * sizeof(int));
	int (*memo)[L] = (int (*)[L])malloc(L * L * sizeof(int));

	if (NULL == memo || NULL == loc){
		return EXIT_FAILURE;
	}

	printf("矩阵最少计算次数为:%d\n", MemoizedMatrixChain(6,memo,loc,src_mat));
	printf("矩阵最优计算次序为:");
	TraceBack(1, L - 1, loc);
	putchar('\n');

	free(loc);
	free(memo);
	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
}
