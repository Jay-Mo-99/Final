#pragma warning(disable:4996)
#include <stdio.h>

int main(void)
{
	const int size = 21;
	FILE* fp1;
	char name[size];


	//Open the file for get the pin name
	fp1 = fopen("pinName.txt", "rt");
	if (fp1 == NULL)
	{
		printf("Error : Can't open file.");
		return 0;
	}

}