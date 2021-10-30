/*快速排序*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int ElementType;
#define Cutoff 3

void Quicksort(ElementType a[], int N);
void QSort(ElementType a[], int Left, int Right);
ElementType madian3(ElementType a[], int Left, int Right);

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
//插入排序
void InsertionSort(ElementType a[], int N)
{
	int i,j;
	ElementType Tmp;
	for (i = 1; i <= N - 1; i++)
	{
		Tmp = a[i];
		for (j = i - 1; j >= 0&&a[j]>Tmp; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = Tmp;
	}
}
void Swap(ElementType *a, ElementType *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
//找到左位置、右位置以及中间位置的元素的中间值,即枢纽元，并返回
ElementType madian3(ElementType a[], int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if (a[Left] > a[Center])
		Swap(&a[Left], &a[Center]);
	if (a[Left] > a[Right])
		Swap(&a[Left], &a[Right]);
	if (a[Center] > a[Right])
		Swap(&a[Center], &a[Right]);
	Swap(&a[Center], &a[Right - 1]);
	return a[Right - 1];
}
/*快速排序的驱动例程*/
void Quicksort(ElementType a[], int N)
{
	QSort(a, 0, N - 1);
}
//快排实际例程
void QSort(ElementType a[], int Left, int Right)
{
	int i, j;
	ElementType Pivot;
	if (Left + Cutoff <= Right)
	{
		i = Left;
		j = Right - 1;
		Pivot = madian3(a, Left, Right);
		for (;;)
		{
			while (a[++i] < Pivot) {}
			while (a[--j] > Pivot) {}
			if (i < j)
				Swap(&a[i], &a[j]);
			else
				break;
		}
		Swap(&a[i], &a[Right - 1]);
		QSort(a, Left, i - 1);
		QSort(a, i + 1, Right);
	}
	else
		InsertionSort(a + Left, Right - Left + 1);
}
/*快速选择解决选择问题*/
void Qselect(ElementType a[],int k, int Left, int Right)
{
	int i, j;
	ElementType Pivot;

	if (Left + Cutoff <= Right)
	{
		i = Left;
		j = Right - 1;
		Pivot = madian3(a, Left, Right);
		for (;;)
		{
			while (a[++i] < Pivot) {}
			while (a[--j] > Pivot) {}
			if (i < j)
				Swap(&a[i], &a[j]);
			else
				break;
		}
		Swap(&a[i], &a[Right - 1]);
		if (k <= i)
			Qselect(a, k, Left, i - 1);
		else if(k>i+1)
			Qselect(a, k, i + 1, Right);
	}
	else
		InsertionSort(a + Left, Right - Left + 1);
}
void printArray(ElementType a[],int n)
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
	printArray(a,size);
	Quicksort(a, size);
	printArray(a,size);
	a = RandArray(size, 0, 100);
	printArray(a, size);
	int k = 6;
	Qselect(a, k, 0, size);
	printf("第%d个大的元素是：%d\n", k, a[k]);
	return 0;
}
