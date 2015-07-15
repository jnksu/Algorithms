#include "dynamic.h"

// ������������ ����¼ʵ��
extern const int L;
// ��ʼ���������
// ���� count_Mat Ϊ�������
// ���� memo Ϊ�������,�� memo[1][2] Ϊ�� ����1 �� ����2 ���������˴���
// ���� loc  Ϊλ�þ���,�� Loc[1][2] Ϊ��  ����1 �� ����2 ����ѶϿ�λ��
// ���� src_mat	ΪҪ���м���ľ���,�� A1 30*35 A2 35*15 A3 15*5 A4 5*10 A5 10*20 A6 20*25 sr_mat[0-6]={30,35,15,5,10,20,25}
int MemoizedMatrixChain(int count_Mat, int(*memo)[L], int(*loc)[L], int * src_mat)
{
	// ��ʼ���������
	for (int i = 1; i <= count_Mat; i++)
	{
		for (int ii = 1; ii <= count_Mat; ii++){
			memo[i][ii] = 0;
		}
	}

	return LookupChain(1, count_Mat, memo, loc, src_mat);
}

// Ѱ�ҶϿ�λ��,�����������˴���
// ���� sl Ϊ��ʼλ��
// ���� el Ϊ��ֹλ��
// ���� memo Ϊ�������,�� memo[1][2] Ϊ�� ����1 �� ����2 ���������˴���
// ���� loc  Ϊλ�þ���,�� Loc[1][2] Ϊ��  ����1 �� ����2 ����ѶϿ�λ��
// ���� src_mat	ΪҪ���м���ľ���,�� A1 30*35 A2 35*15 A3 15*5 A4 5*10 A5 10*20 A6 20*25 sr_mat[0-6]={30,35,15,5,10,20,25}
int LookupChain(int sl, int el, int(*memo)[L], int(*loc)[L], int * src_mat)
{
	// �����������д�����Ӧ�Ľ�
	if (memo[sl][el] > 0) return memo[sl][el];

	// ֻ��һ�������ʱ��,���˴���Ϊ0
	if (sl == el) return 0;
	
	// ����ʼλ��Ϊ�Ͽ�λ��ʱ
	int  val = LookupChain(sl, sl, memo, loc, src_mat) + LookupChain(sl + 1, el, memo, loc, src_mat) + src_mat[sl - 1] * src_mat[sl] * src_mat[el];
	loc[sl][el] = sl;

	// Ѱ�����Ž�
	for (int i = sl + 1; i < el; i++){
		int temp = LookupChain(sl, i, memo, loc, src_mat) + LookupChain(i + 1, el, memo, loc, src_mat) + src_mat[sl - 1] * src_mat[i] * src_mat[el];
		if (temp < val){
			val = temp;
			loc[sl][el] = i;
		}
	}

	// �洢���Ž⵽���������
	memo[sl][el] = val;
	// �������Ž�
	return val;
}

// ����Ͽ�λ��
void TraceBack(int sl, int el, int(*loc)[L])
{
	if (sl == el){
		printf("A%d", sl);
	}else{
		printf("(");
		TraceBack(sl, loc[sl][el], loc);	// �ӿ�ʼλ�õ���ѶϿ�λ��
		TraceBack(loc[sl][el] + 1, el, loc);	//����ѶϿ�λ�õ�����λ��
		printf(")");
	}
}
