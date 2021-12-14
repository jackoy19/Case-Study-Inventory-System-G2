#include <stdio.h>
#include <stdlib.h>

void searchItem()
{
    int Item_ID;
    printf("Input Item ID: ");
    scanf("%d", &Item_ID);
    if (!(Item_ID >= 11101 && Item_ID <= 69999))
    {
        printf("Item ID is invalid!");
        return;
    }
    funcExist(&Item_ID);
    printf("Success: %d", Item_ID);
}

int main(void)
{
    searchItem();
    return 0;
}