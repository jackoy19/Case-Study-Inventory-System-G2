#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcExist.c"

void getLine(int *lineNum)
{
    int lineOnFile = 1;
    FILE *fptr = fopen("inventory.csv", "r");
    char line[255];
    int i = 0;
    char details[5][120];
//Reading of File
    while (!feof(fptr)) // loop until end of the file
    {
        fgets(line, 255, fptr);
        if (*lineNum == lineOnFile)
        {
            char *lineptr = strtok(line, ","); // Split the string by using comma delimeter
            for(;i<5;i++) {
                strcpy(details[i],lineptr);   //copy the each values on the details array
                lineptr = strtok(NULL, ",");
            }
            fclose(fptr);
            break;
        }
        lineOnFile++;
    }
    fclose(fptr);
//Displaying OUTPUT
    printf("Item ID: %s\n",details[0]);
    printf("Item Description: %s\n",details[1]);
    printf("Item Quantity: %s\n",details[2]);
    printf("Item Expiry Date: %s\n",details[3]);
    printf("Item Price: %s\n",details[4]);
}

void searchItem()
{
    int Item_ID;
    printf("Input Item ID: ");
    scanf("%d", &Item_ID);
    if (!(Item_ID >= 11101 && Item_ID <= 69999)) {
        printf("Item ID is invalid!\n");
        return;
    }
    int lineNum = funcExist(&Item_ID);
    if (lineNum > 0) {
        getLine(&lineNum);
    } else {
        printf("Item ID does not exist!\n");
    }
}

int main(void)
{
    searchItem();
    return 0;
}
