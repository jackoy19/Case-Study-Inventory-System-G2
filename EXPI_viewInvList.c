#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void EXPI_viewInvList()
{
    int lineOnFile = 1;
    FILE *fptr = fopen("Inventory_ST_NoQuote_NoBOM.csv", "r");
    char line[255];
    int i = 0;
    char details[5][120];

    //header
    printf("%-12s %-35s %-15s %-15s %-s\n", "Item ID", "Description", "Quantity", "Expiry Date", "Price");
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
       
        printf("%-12s %-35s %-15s %-15s %s", details[0],details[1],details[2],details[3],details[4]);
        i=0;
    }
    printf("\n");
    fclose(fptr);
}

// int main(void) {
//     EXPI_viewInvList();
//     return 0;
// }