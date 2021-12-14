#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int funcExist(int *itemId) {
    char item[6];
    sprintf(item,"%d",*itemId); // converts int to char
    FILE *fptr = fopen("inventory.csv", "r"); 
    char line[120];
    while (!feof(fptr))  // loop until end of the file
    {
        fgets(line, 120, fptr);  //store the whole line in variable line
        //below if compare if the Item_ID is matched on inventory
        if(strcmp(item,strtok(line,",")) == 0) {
            fclose(fptr);
            printf("Found");
            return 1;
        }
    }
    fclose(fptr);
    printf("Not Found");
    return 0;
}

int main(){
    int itemId;
    printf("Enter Item ID: ");
    scanf("%d", &itemId);
    funcExist(&itemId);
    return 0;
}

