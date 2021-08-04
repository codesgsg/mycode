#include "test.h"

char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* p = dest;
	while ((*dest++) = (*src++))
	{
		
	}
	return p;
}

int main()
{
	char* (*p)(char*, const char*) = my_strcpy;
	char* (*pp[4])(char*, const char*) = { my_strcpy,my_strcpy, my_strcpy, my_strcpy };

	char arr1[20] = { 0 };
	char arr2[] = "abcdefg";
	char arr3[] = "123456";
	printf("%s\n", (*p)(arr1, arr2));
	printf("%s\n",(*pp[0])(arr1, arr3));
}