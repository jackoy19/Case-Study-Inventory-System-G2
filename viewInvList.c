#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void viewInvList()
{
	int lineOnFile = 1;
	FILE *fptr = fopen("Inventory_ST_NoQuote_NoBOM.csv", "r");
	char line[255];
	int i = 0;
	char details[5][120];
	int size;

	//header
	printf("%-9s %-39s %-9s %-19s %-s\n", "Item ID", "Description", "Quantity", "Expiry Date", "Price");
	
	//Checking if file is empty
    fseek(fptr, 0, SEEK_END); // put the pointer on end of file then check the size
    size = ftell(fptr); 
    if (size == 0) {
        printf("No Item in the inventory!\n");
		fclose(fptr);
		return;
    }
	fseek(fptr, 0, SEEK_SET); // reset pointer back to the start
	//Reading of File
	while (!feof(fptr)) // loop until end of the file
	{
		fgets(line, sizeof(line), fptr);

		char *lineptr = strtok(line, ","); // Split the string by using comma delimeter
		for (; i < 5; i++)
		{
			strcpy(details[i], lineptr); //copy the each values on the details array
			lineptr = strtok(NULL, ",");
		}
		//printing of item details
		printf("%-9s %-39s %-9s %-19s %-s", details[0], details[1], details[2], details[3], details[4]);
		i = 0;
	}
	printf("\n");
	fclose(fptr);
}