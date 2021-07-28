#include <stdio.h>

int binsearch(int x, int v[], int n);
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11 };
	int n = 6;
	printf("%d", binsearch(sizeof(arr) / sizeof(int), arr, n));
	return 0;
}

int binsearch(int x, int v[], int n)
{
	int a = x/2;
	int b = 0;


	a = v[a] > n ? a/2 : a/2+a;

	a = v[a] > n ? a / 2 : a / 2 + a;

	return -1;
}

//int binsearch(int x,int v[],int n)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		if (v[i] == n)
//		{
//			return i;
//		}
//	}
//	return -1;
//}