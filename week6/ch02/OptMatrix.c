#include<stdio.h>
#define Infinity 100000;
//找出矩阵乘法最优顺序的程序 TowDimArray是二维数组类型
void OptMatrix(const long C[], int N, TwoDimArray M, TowDimArray LastChange)
{
	int i, k, Left, Right;
	long ThisM;
	for (Left = 1; Left <= N; Left++)
		M[Left][Left] = 0;
	for (k = 1; k < N; k++)
	{
		for (Left = 1; Left <= N - k; Left++)
		{
			Right = Left + k;
			M[Left][Right] = Infinity;
			for (i = Left; i < Right; i++)
			{
				ThisM = M[Left][i] + M[i + 1][Right] + C[Left - 1] * C[i] * C[Right];
				if (ThisM < M[Left][Right])
					M[Left][Right] = ThisM;
				LastChange[Left][Right] = i;
			}
		}
	}
}
