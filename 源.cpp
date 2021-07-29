#include <stdio.h>

//µ›πÈµ˜”√∫Ø ˝
//void xx(int x)
//{
//	
//	if (x > 9)
//	{
//		xx(x/10);
//	}
//	printf("%d ", x%10);
//	
//}


//√∞≈›≈≈–Ú
int Bubble_Sort(int arr[],int size)
{
	int i = 0;
	int k = 0;
	for (i = 1; i < size; i++)
	{
		int num = 0;
		for (k = 0; k < size - i;k++)
		{
			if (arr[k] > arr[k + 1])
			{
				num = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = num;
			}
		}
	}
	return 0;
}

int main()
{
	int arr[] = { 555,3,144,6,9999,123,444,777,5,1,9,0,5555,123123,321,4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Bubble_Sort(arr, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}