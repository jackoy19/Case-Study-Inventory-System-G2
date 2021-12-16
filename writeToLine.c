#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeToLine(char *myString, int *lineNum)
{
    FILE *fptr = fopen("Inventory_ST_NoQuote_NoBOM.csv", "r");
    FILE *ftemp = fopen("replace.tmp", "w");
    char path[100];

    char buffer[1000];
    int count = 0;
    /* fopen() return NULL if unable to open file in given mode. */
    if (fptr == NULL || ftemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(0);
    }
    /* Remove extra new line character from stdin */
    fflush(stdin);

    while ((fgets(buffer, 1000, fptr)) != NULL)
    {
        count++;
        
        if (count == *lineNum)
        {
            fprintf(ftemp,"%s",myString);
            fputs(buffer, ftemp);
        }
        else
            fputs(buffer, ftemp);
    }

    /* Close all files to release resource */
    fclose(fptr);
    fclose(ftemp);

    /* Delete original source file */
    remove("Inventory_ST_NoQuote_NoBOM.csv");

    /* Rename temporary file as original file */
    rename("replace.tmp", "Inventory_ST_NoQuote_NoBOM.csv");
}