#include "test.h"
#include <Windows.h>
int Binary(int number)
{
	int count = 0;
	while (number)
	{
		number &= (number - 1);
		count++;
	}
	return count;
}

void getBinary(int number)
{
	for (int i = 30; i >=0; i-=2)
	{
		printf("Å¼Êý:%d ÆæÊý:%d\n", (number >> i) & 1,(number>>i+1)&1);
	}
}

void SwitchedDigital(int x,int y)
{
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
	printf("%d %d", x, y);
}

void printnumber(int* a,int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", *(a+i));
	}
}

void table(int n, int x)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%2d*%-2d=%3d   ", j, i, i * j);
		}
		printf("\n");
	}
}

void printone(int x)
{
	if (x > 9)
	{
		printone(x/10);
	}
	printf("%d ", x% 10);
}
void factorial(int number)
{
	int count = 1;
	for (int i = 1; i <= number; i++)
	{
		count *= i;
	}
	printf("%d\n", count);
}

int factoriald(int number)
{
	if (number > 1)
	{
		return number * factoriald(number - 1);
	}
	return 1;
}

int strlenex(char* s)
{
	int count = 0;
	while (*s++ != '\0')
	{
		count++;
	}
	return count;
}

int strlenexa(char* s)
{
	if (*s != '\0')
	{
		return strlenexa(s + 1)+1;
	}
	return 0;
}

void reverse_string(char* string)
{
	int size = strlenexa(string)-1;
	for (int i = 0; i < size/2; i++)
	{
		char x = *(string + i);
		*(string + i) = *(string + size - i);
		*(string + size - i) = x;
	}
}

void reverse_stringex(char* string)
{
	if (*(string + 1) != '\0')
	{
		char temp = string[0];
		int size = strlenexa(string) - 1;
		string[0] = string[size];
		string[size] = '\0';
		//if(strlenexa(string+1)>=2)
		reverse_stringex(string + 1);
		string[size] = temp;
		//string[size + 1] = '\0';
	}
}

int DigitSum(unsigned int n)
{
	if (n > 9)
	{
		return DigitSum(n / 10) + n % 10;
	}
	{
		return n;
	}
}

double equation(int n, int k)
{
	if (k == 0)
	{
		return  1;
	}
	else if (k<0)
	{
		return (1.0 / (equation(n, -k)));
	}
	else
	{
		return equation(n, k - 1) * n;
	}

}

int Fibonacci(int n)
{
	int a = 0;
	int b = 1;
	int count = 0;
	for (int i = 1; i < n; i++)
	{
		count = a + b;
		a = b;
		b = count;
	}
	return count;
}
int Fibonacciex(int n)
{
	return n<3?1:Fibonacciex(n - 1) + Fibonacciex(n - 2);
}

int addbit(int a)
{
	int sum = a;
	int b = a;
	for (int i = 1; i < 5; i++)
	{
		a = a * 10 + b;
		sum += a;
	}
	return sum;
}

void printimage(char* arr,int size)
{
	int mid = size / 2 - 1;
	int j = 0;
	char* x=arr+ mid;
	
	for (int i = 0; i <size-1; i++)
	{
		if (i <= mid)
		{
			*(x + j) = '*';
			*(x + j+1) = '\0';
			*(x - j) = '*';
			if (i < mid)
				j++;
		}
		else
		{
			*(x + j) = '\0';
			*(x - j) = ' ';
			j--;
		}
		printf("%s\n", arr);
	}

}
int main()
{
	char arr[30] = {0};
	int size = sizeof(arr) / sizeof(arr[0]);
	memset(arr, ' ', size - 1);
	printimage(arr,size);
	int a = 2;
	printf("%d", addbit(a));
	/*unsigned int n = 9721;
	printf("%d", DigitSum(n));*/
	printf("%f", equation(8, -2));
	printf("%d",Fibonacci(50));
	
	printf("%d\n", Binary(15));
	printf("%d\n", Binary(1999 ^ 2299));
	getBinary(15);
	SwitchedDigital(5,7);
	int arr[] = { 1,24,56,77,43,123,54,1111,4423,11 };
	printnumber(arr,sizeof(arr)/sizeof(arr[0]));
	table(11, 11);
	printone(123123);
	factorial(12);
	printf("%d\n", factoriald(12));
	char a[] = { "HELLaaabbbb"};
	printf("%d\n",strlenex(a));
	printf("%d\n", strlenexa(a));
	char arr[] = { "abcdef" };
	reverse_string(arr);
	printf("%s", arr);
	reverse_stringex(arr);
	printf("%s\n", arr);
	return 0;
}