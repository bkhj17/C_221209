#include "String.h"
#include <stdio.h>
#include <string.h>

int String::GetStrLength(const char* str)
{
	int i = 0;
	for (; i < sizeof(str); i++) {
		if (str[i] == 0)
			break;
	}
	return i;
}

bool String::IsSameStr(char* str1, char* str2)
{
	if (GetStrLength(str1) != GetStrLength(str2))
		return false;

	for (int i = 0; i < strlen(str1); i++) {
		if (str1[i] != str2[i])
			return false;
	}

	return true;
}

void String::Run()
{

	char str[30] = "Hello World!";
	char str2[] = "Hello World!";

	printf("std : %s\n", str);
	printf("size : %d\n", sizeof(str));

	int strSize = sizeof(str);
	for (int i = 0; i < strSize; i++)
		printf("%c : %d\n", str[i], str[i]);
	
	printf("GetStrLength : %d\n", GetStrLength(str));
	printf("strlen : %d\n", GetStrLength(str));

	int cmp = strcmp(str, str2);
	if (cmp == 0) {
		printf("같다\n");
	}
	else if (cmp < 0) {
		printf("먼저께 더 앞\n");
	}
	else {
		printf("뒤에께 더 앞\n");
	}

	bool cmp2 = IsSameStr(str, str2);
	if(cmp2)
		printf("같다\n");
	else
		printf("다르다\n");
}
