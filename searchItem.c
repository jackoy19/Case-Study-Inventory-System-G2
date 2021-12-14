#include <stdio.h>
#include <stdlib.h>
#include "funcExist.c"
#include "getLine.c"

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