#include <stdio.h>
#include <math.h>

void susu(int mid, int max)
{
	if (mid > max)
	{
		printf("请输入正确的范围");
		return;
	}
	if (max < 2)
	{
		printf("无");
		return;
	}
	if (mid < 2)
	{
		mid = 2;
	}
	for (; mid <= max; mid++)
	{
		int i = 0;
		for (i = 2; i <= sqrt(mid); i++)
		{
			if (mid % i == 0)
			{
				break;
			}
		}
		if (i > sqrt(mid))
		{
			printf("%d ", mid);
		}
	}
}
void runnian(int mid,int max)
{
	for (; mid <= max; mid++)
	{
		if ((mid % 4 == 0 && mid % 100 != 0)||(mid%400==0))
		{
			printf("%d ", mid);
		}

	}
}

int Binary_Search(int n,int arr[],int size)
{
	int mid = 0;
	int max = size;
	for(mid=0;mid<=max;)
	{
		int i =(max+mid) / 2;
		if((arr[i]<n?mid=i+1:arr[i]>n?max=i-1:-1000)==-1000)	
			return i;
	}
	return -1;
}

void ADD_One(int* num)
{
	(*num)++;
}
int main()
{
	susu(-99999,999);
	runnian(0, 2000);
	int arr[] = { 2,6,9,11,15,17,44,88,222,444,886,2121 ,8899};
	int num=Binary_Search(0,arr,sizeof(arr)/sizeof(arr[0])-1);
	printf("%d", num);
	int i = -999;
	ADD_One(&i);
	ADD_One(&i);
	ADD_One(&i);
	printf("%d", i);
	return 0;
}