/*归并排序*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<errno.h>
typedef int ElementType;

void MSort(ElementType a[], ElementType TmpArray[], int Left, int Right);
void Merge(ElementType a[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd);
void Mergesort(ElementType a[], int N);
int *RandArray(int size, ElementType left, ElementType right)
{
	srand((unsigned)time(NULL));
	int i;
	ElementType *array = malloc(sizeof(ElementType)*size);
	for (i = 0; i < size; i++)
	{
		array[i] = rand() % (right - left + 1) + left;
	}
	return array;
}
/*MSort,分治分别排序左右两部分，然后合并*/
void MSort(ElementType a[], ElementType TmpArray[], int Left, int Right)
{
	int Center;
	if (Left < Right)
	{
		Center = (Left + Right) / 2;
		MSort(a, TmpArray, Left, Center);
		MSort(a, TmpArray, Center + 1, Right);
		Merge(a, TmpArray, Left, Center + 1, Right);
	}
}
void Merge(ElementType a[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd)
{
	int i, LeftEnd, NumElements, TmpPos;
	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElements = RightEnd - Lpos + 1;
	while (Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if (a[Lpos] <= a[Rpos])
			TmpArray[TmpPos++] = a[Lpos++];
		else
			TmpArray[TmpPos++] = a[Rpos++];
	}
	while (Lpos <= LeftEnd)
		TmpArray[TmpPos++] = a[Lpos++];
	while (Rpos <= RightEnd)
		TmpArray[TmpPos++] = a[Rpos++];
	for (i = 0; i < NumElements; i++,RightEnd--)
	{
		a[RightEnd] = TmpArray[RightEnd];
	}
}
void Mergesort(ElementType a[], int N)
{
	ElementType *TmpArray;
	TmpArray = malloc(sizeof(ElementType)*N);
	if (TmpArray != NULL)
	{
		MSort(a, TmpArray, 0, N - 1);
		free(TmpArray);
	}
	else
		perror("No space for tmp array!");
}
void printArray(ElementType a[], int n)
{
	int i;
	for (i = 0; i < n - 1; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("%d\n", a[i]);
}
int main()
{
	int size = 10;
	int *a = malloc(sizeof(int)*size);
	a = RandArray(size, 0, 100);
	printArray(a, size);
	Mergesort(a, size);
	printArray(a, size);
	return 0;
}
