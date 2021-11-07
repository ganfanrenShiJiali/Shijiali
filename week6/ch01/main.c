#include"head.h"
#include<stdio.h>
void Initialize(DisjSet S)
{
	int i;
	for (i = NumSets; i > 0; i--)
		//S[i] = -1;//按高度求并的设置
		S[i] = 0;//按大小求并
}
/*
	void SetUnion(DisjSet S, SetType Root1, SetType Root2)
	{
		S[Root2]=Root1;
	}
*/
//按高度求并
void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
	if (S[Root2] < S[Root1])//Root2 is deeper set
		S[Root1] = Root2;
	else
	{
		if (S[Root1] == S[Root2])
			S[Root1]--;//相等深度的树合并深度一定增加
		S[Root2] = Root1;
	}
}
SetType Find(ElementType X, DisjSet S)
{
	if (S[X] <= 0)
		return X;
	else
		return Find(S[X], S);
}
/*路径压缩进行不相交集Find操作
SetType Find(ElementType X, DisjSet S)
{
	if (S[X] <= 0)
		return X;
	else
		return S[X] = Find(S[X], S);
}*/
void print(DisjSet S)
{
	int i;
	for (i = 1; i <= NumSets; i++)
	{
		printf("%d  ", S[i]);
	}
}
int main()
{
	int *S = malloc(sizeof(ElementType)*NumSets);
	Initialize(S);
	SetUnion(S, 5, 6);
	SetUnion(S, 7, 8);
	SetUnion(S, 5, 7);
	SetUnion(S, 4, 5);
	printf("%d\n",Find(8, S));
	printf("%d\n", Find(6, S));
	print(S);
	return 0;
}
