#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* This function Returns what line on the file it will be added, 
  returns 0 if Item iD is the highest number in inventory */
int getPositionSort(int* item_id){
    int lineOnFile = 1;
    FILE *fptr = fopen(fileName, "r");
    
    char line[256];
    char item[6];

    while (!feof(fptr)) {
        fgets(line, 256, fptr);  //store all of line
        
        //store item id on item var
        char* lineptr = strtok(line, ",");
        strcpy(item,lineptr);

        int itemInFile = atoi(item);
        //compare item ID to be added with each id on the inventory
        if(*item_id < itemInFile) {
            fclose(fptr);
            return lineOnFile;
        }
        lineOnFile++;
    }
    fclose(fptr);
    return 0;
}