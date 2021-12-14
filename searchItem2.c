#include <stdio.h>
#include <stdlib.h>
#include "funcExist2.c"
#include "lineShow.c"

void searchItem2()
{
    int Item_ID;
    printf("Input Item ID: ");
    scanf("%d", &Item_ID);
    if (!(Item_ID >= 11101 && Item_ID <= 69999))
    {
        printf("Item ID is invalid!\n");
        return;
    }
    if (funcExist2(&Item_ID)) {
        //printf("ITEM FOUND: %d\n", funcExist2(&Item_ID));
        //printf("ITEM: %s\n", lineShow(funcExist2(&Item_ID)));
        lineShow(funcExist2(&Item_ID));
    } else {
        printf("Item ID does not exist!\n");
    }
}
