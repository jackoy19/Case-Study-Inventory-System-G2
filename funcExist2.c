#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int funcExist2(int *itemId) {
    char item[6];
  	sprintf(item,"%d",*itemId); // converts int to char
    FILE *fptr = fopen("inventory.csv", "r"); 
    char line[120];
    int i = 1;
    while (!feof(fptr))  // loop until end of the file
    {
    	
        fgets(line, 120, fptr);  //store the whole line in variable line
        //below if compare if the Item_ID is matched on inventory
        if(strcmp(item,strtok(line,",")) == 0) {
            fclose(fptr);            
						return i;
        }
        i++;
    }
    //printf("Found in line %d\n", i);
    fclose(fptr);
    // printf("Item ID does not exist!");
    return 0;
}
