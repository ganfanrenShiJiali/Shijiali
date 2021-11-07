#include<stdio.h>
//递归程序
double Eval(int N)
{
	int i;
	double Sum;
	if (N == 0)
		return 1.0;
	else
	{
		Sum = 0.0;
		for (i = 0; i < N; i++)
			Sum += Eval(i);
		return 2.0*Sum / N + N;
	}
}
//使用动态规划来计算
double Eval(int N)
{
	int i, j;
	double Sum, Answer;
	double *C;
	
	C = malloc(sizeof(double)*(N + 1));
	if (C == NULL)
		perror("Out of space!");
	C[0] = 1.0;
	for (i = 1; i <= N; i++)
	{
		Sum = 0.0;
		for (j = 0; j < i; j++)
			Sum += C[j];
		C[i] = 2.0*Sum / i + i;
	}
	Answer = C[N];
	free(C);
	return Answer;
}
