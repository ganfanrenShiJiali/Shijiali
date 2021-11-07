#include<stdio.h>
//动态规划：斐波那契数列
//低效算法
int Fib(int N)
{
	if (N <= 1)
		return 1;
	else
		return Fib(N - 2) + Fib(N - 1);
}
//线性算法
int Fibonacci(int N)
{
	int i, Last, NextToLast, Answer;

	if (N <= 1)
		return 1;
	Last = NextToLast = 1;
	for (i = 2; i <= N; i++)
	{
		Answer = Last + NextToLast;
		NextToLast = Last;
		Last = Answer;
	}
	return Answer;
}
void FibonacciPrint(int N)
{
	int i, Last, NextToLast, Answer;
	Last = NextToLast = 1;
	for (i = 0; i < N; i++)
	{
		if (i <= 1)
		{
			printf("%d  ", 1);
		}
		else
		{
			Answer = Last + NextToLast;
			printf("%d  ", Answer);
			NextToLast = Last;
			Last = Answer;
		}
	}
}
int main()
{
	int N = 10;
	int i;
	FibonacciPrint(N);
	return 0;
}
