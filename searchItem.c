void searchItem()
{
    int Item_ID;
    char input[7];

    fflush(stdin);
    
    printf("Input Item ID: ");
    fgets(input,7,stdin);

    int len = strcspn(input, "\r\n");
    //check if number is being padded with invalid char
    if(len > 5) {
        printf("\nItem ID is invalid!\n\n");
        return;
    }
    //convert valid Item_ID string format input as int
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
