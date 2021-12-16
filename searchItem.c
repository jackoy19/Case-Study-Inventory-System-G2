void searchItem()
{
    int Item_ID;
    char input[6];

    fflush(stdin);
    
    printf("Input Item ID: ");
    fgets(input,7,stdin);

    Item_ID = atoi(input);

    if (!(Item_ID >= 11101 && Item_ID <= 69999)) {
        printf("\nItem ID is invalid!\n\n");
        return;
    }
    int lineNum = funcExist(&Item_ID);
    if (lineNum > 0) {
        getLine(&lineNum);
    } else {
        printf("\nItem ID does not exist!\n\n");
    }
}
