#include <stdio.h>
//汉诺塔问题
//A,B,C三个柱子,A柱有N个从大到小排序的圆盘.把A柱N个原盘移动到C柱,规则:保持下边永远比上边大.一次移动一个.使用递归.

void TowerOfHanoi(int n,char a,char b,char c)
{
	if (n == 1)
	{
		printf("将盘子%d 从%c->%c\n",n,a,c);
	}
	else
	{
		TowerOfHanoi(n-1,a,c,b);
		printf("将盘子%d 从%c->%c\n", n, a, c);
		TowerOfHanoi(n - 1,b,a,c);
	}
}
//青蛙跳台阶
//设台阶数位N 跳1级 跳2级 2种
//N=1  1种跳法{1}  
//N=2  2种跳法{1,1}{2}
//N=3  3种跳法{1,1,1}{1,2}{2,1}
//N=4  5种跳法{1,1,1,1}{1,1,2}{1,2,1}{2,1,1}{2，2}
//N=5  8种跳法{1,1,1,1,1}{1,1,1,2}{1,1,2,1}{1,2,1,1}{2,1,1,1}{1,2,2}{2,1,2}{2,2,1}
//发现就是斐波那契数列 

int jump(int n)
{
	if (n <= 0)
		return 0;
	else if (n==1)
		return 1;
	else
		return jump(n - 1) + jump(n - 2);
}

int jump1(int n)
{
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		int a = 1;
		int b = 1;
		int c = 1;
		while (n > 2)
		{
			c = a + b;
			a = b;
			b = c;
			n--;
		}
		return c;
	}
	return n;
}

int jump2(int n)
{
	if (n <= 1)
		return 1;
	else
		return 2 * jump2(n - 1);
}

int jump3(int n,int m)
{
	if (n > m)
		return 2 * jump3(n - 1, m) - jump3(n - 1 - m, m);
	if (n <= 1)
		return 1;
	else
		return 2 * jump3(n - 1,n);
}
int main()
{
	//TowerOfHanoi(3,'A','B','C');
	/*for (int i = 0; i < 100; i++)
	{
		
	}*/
	//printf("%d  ", jump(40));
	printf("%d  ", jump2(4));
	printf("%d", jump3(4,2));
	return 0;
}


