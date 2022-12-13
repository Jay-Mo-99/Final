/*
* Filename: 		exam.cpp
* Project:			exam
* Programmer:		Jay Mo
* Date:     		December 13, 2022
* Description:  	This program reads the pin numbers of the file.
					It verifies that the numbers are in the correct format,and outputs the numbers of valid pin and invalid.
					This program uses File Input Option, Phone Number Pointer Option and Console Output Option.

*/



#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validatePIN(char *pinNumber);

int main(int argc,char *argv[])
{
	const int size = 21;
	FILE* fp1;
	char name[21][size];
	int numRead = 0;
	char* realname;

	//Open the file for get the pin name
	fp1 = fopen("pin.out.txt", "rt");
	if (fp1 == NULL)
	{
		printf("Error : Can't open file.");
		return 0;
	}

	for(int i = 0;i < 21;i++)
	{
		while(fgets(name[i], sizeof(name[i]), fp1) == NULL);
		realname = strtok(name[i],"\n");
	}

	//close the text file
	if (fclose(fp1) != 0)
	{
		printf("Error: Can't close the file");
		return 0;
	}
	
	//command line arguments
	int argNum = 1;

	for (argNum = 1;argNum < argc;argNum++)
	{
		printf("Arg #%d : %s\n", argNum, argv[argNum]);
	}

	//valid the pin number

	int validNumber = 0;
	int invalidNumber = 0;
	
	for (int i = 0;i < size;i++)
	{
		validatePIN(name[i]);
		if (validatePIN(name[i]) == 1)
		{
			validNumber++;
			printf("%s matched the format\n", name[i]);
		}
		else
		{
			invalidNumber++;
			printf("%s did not match the format\n", name[i]);
		}

	}

	printf("Wendy's: valid: %d, invalid: %d", validNumber, invalidNumber);

	return 0;
}



/*
* FUNCTION :  validatePIN
*
* DESCRIPTION : This function checks the pin number has the right format.  
*
* PARAMETERS : char pinNumber
*
* RETURNS : return 1, when the pin number has the right format. The other returns 0

*/



int validatePIN(char *pinNumber)
{
	if (strlen(pinNumber) == 12)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}