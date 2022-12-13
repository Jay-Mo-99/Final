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

int validatePIN(char pinNumber);

int main(int argc,char *argv[])
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

	//close the text file
	if (fclose(fp1) != 0)
	{
		printf("Error: Can't close the file");
		return 0;
	}
	
	//command line arguments
	int argNum = 1;
	printf("The command line contents:\n");
	printf("Command : %s\n", argv[0]);
	for (argNum = 1;argNum < argc;argNum++)
	{
		printf("Arg #%d : %s\n", argNum, argv[argNum]);
	}
	
	return 0;
}


/*
* FUNCTION :  validatePIN
*
* DESCRIPTION : This function checks the pin number has the right format.  
*
* PARAMETERS : char pinNumber
*
* RETURNS : int number

*/


int validatePIN(char pinNumber)
{
	printf("The valid format is ### ### ###.\n");
	return 0;
}