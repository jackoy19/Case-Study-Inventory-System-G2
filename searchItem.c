#include <stdio.h>
#include <stdlib.h>
#include "funcExist.c"

void searchItem()
{
    int Item_ID;
    printf("Input Item ID: ");
    scanf("%d", &Item_ID);
    if (!(Item_ID >= 11101 && Item_ID <= 69999))
    {
        printf("Item ID is invalid!\n");
        return;
    }
    if (funcExist(&Item_ID)) {
        printf("ITEM FOUND: proceed with something\n");
    } else {
        printf("Item ID does not exist!\n");
    }
}
