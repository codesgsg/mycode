#include <stdio.h>
//��ŵ������
//A,B,C��������,A����N���Ӵ�С�����Բ��.��A��N��ԭ���ƶ���C��,����:�����±���Զ���ϱߴ�.һ���ƶ�һ��.ʹ�õݹ�.

void TowerOfHanoi(int n,char a,char b,char c)
{
	if (n == 1)
	{
		printf("������%d ��%c->%c\n",n,a,c);
	}
	else
	{
		TowerOfHanoi(n-1,a,c,b);
		printf("������%d ��%c->%c\n", n, a, c);
		TowerOfHanoi(n - 1,b,a,c);
	}
}
//������̨��
//��̨����λN ��1�� ��2�� 2��
//N=1  1������{1}  
//N=2  2������{1,1}{2}
//N=3  3������{1,1,1}{1,2}{2,1}
//N=4  5������{1,1,1,1}{1,1,2}{1,2,1}{2,1,1}{2��2}
//N=5  8������{1,1,1,1,1}{1,1,1,2}{1,1,2,1}{1,2,1,1}{2,1,1,1}{1,2,2}{2,1,2}{2,2,1}
//���־���쳲��������� 

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


