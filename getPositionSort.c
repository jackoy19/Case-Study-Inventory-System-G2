#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getPositionSort(int* item_id){
    int lineOnFile = 1;
    FILE *fptr = fopen("Inventory_ST_NoQuote_NoBOM.csv", "r");
    
    char line[256];
    char item[6];

    while (!feof(fptr)) {
        fgets(line, 256, fptr);  //store all of line
        //below if compare if the Item_ID is matched on inventory
        char* lineptr = strtok(line, ",");
        strcpy(item,lineptr);

        int itemInFile = atoi(item);
        if(*item_id < itemInFile) {
            fclose(fptr);
            return lineOnFile;
        }
        lineOnFile++;
    }
    fclose(fptr);
    return 0;
}


// int main(){
//     int x = 62116;
//     int pos = getPositionSort(&x);
//     printf("%d\n",pos);
//     return 0;
// }