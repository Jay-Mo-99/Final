/*
* Filename: 		exam.cpp
* Project:			exam.cpp
* Programmer:		Jay Mo
* Date:     		December 13, 2022
* Description:  	This program uses File Input Option.

*/

#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	const int size = 254;
	FILE* fp1;
	char name[21][size] = {" "};
	int numRead = 0;
	char* realname;

	//Open the file for get the pin name
	fp1 = fopen("pinName.txt", "rt");
	if (fp1 == NULL)
	{
		printf("Error : Can't open file.");
		return 0;
	}



	for(int i = 0;i < 21;i++)
	{
		fgets(name[i], sizeof(name[i]), fp1);
		realname = strtok(name[i],"\n");
		printf("The pin number : %s\n", name[i]);
	}


}