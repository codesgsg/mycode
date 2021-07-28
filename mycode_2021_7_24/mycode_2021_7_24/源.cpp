#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i = 0;
	int a = 0;
	int n = 0;
	int ret = 1;
	int sum = 0;
	printf("阶乘计算,请输入一个数\n");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		ret = i * ret;
		sum = ret + sum;
	}
	//1*1
	//1*2
	//1*2*3
	//1*2*3*4
	//1*2*3*4*5
	printf("%d", sum);
	return 0;
}