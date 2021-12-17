#define BUFFER_SIZE 1000
void updateItem()
{

    int Item_ID;
    char input[6];

    fflush(stdin);
    printf("Input Item ID: ");
    fgets(input, 7, stdin);

    Item_ID = atoi(input);
    if (!(Item_ID >= 11101 && Item_ID <= 69999))
    {
        printf("Item ID is invalid!\n");
        return;
    }
    int lineNum = funcExist(&Item_ID);
    if (lineNum > 0)
    {
        getLine(&lineNum);
        /* File pointer to hold reference of input file */
        FILE *fptr = fopen("Inventory_ST_NoQuote_NoBOM.csv", "r");
        FILE *ftemp = fopen("replace.tmp", "w");
        char path[100];

        char buffer[BUFFER_SIZE];
        int count;
        /* fopen() return NULL if unable to open file in given mode. */
        if (fptr == NULL || ftemp == NULL)
        {
            /* Unable to open file hence exit */
            printf("\nUnable to open file.\n");
            printf("Please check whether file exists and you have read/write privilege.\n");
            exit(EXIT_SUCCESS);
        }

        /* Remove extra new line character from stdin */
        fflush(stdin);

        int item_id;
        char item_description[41], item_expirydate[50];
        char temp;
        char *itdp = item_description, *itep = item_expirydate;
        double item_price;
        char item_quantity[100] = "";
        int length, i;

        printf("Input Item ID: ");
        scanf("%d", &item_id);
        if ((item_id >= 11101) && (item_id <= 69999))
        {
            if ((funcExist(&item_id) > 0) && (item_id != Item_ID))
            {
                printf("\nItem ID already exists in inventory!\n\n");
                fclose(fptr);
                fclose(ftemp);
            }
            else
            {
                printf("Input Item Description: ");
                scanf("%c", &temp);
                fgets(item_description, 41, stdin);
                item_description[strcspn(item_description, "\n")] = 0;
                printf("Input Quantity: ");
                scanf("%s", item_quantity);
                length = strlen(item_quantity);
                for (i = 0; i < length; i++)
                {
                    if (!isdigit(item_quantity[i]))
                    {
                        goto inv;
                        exit(1);
                    }
                }
                if (item_quantity >= 0)
                {
                    printf("Input Expiry Date (yyyy-mm-dd or -): ");
                    // scanf("%c", &temp);
                    fflush(stdin);
                    fgets(item_expirydate, 50, stdin);
                    item_expirydate[strcspn(item_expirydate, "\n")] = 0;
                    length = strlen(item_expirydate);
                    if (length != 1 && length != 10) {
                        goto inv;
                    }
                    if(length == 1 && item_expirydate[0] == '-'){
                        goto jump;
                    }
                    for (i = 0; i < length; i++)
                    {
                        if (i == 4 || i == 7)
                        {
                            if (item_expirydate[i] != '-')
                            {
                                goto inv;
                            }
                        }
                        else if (i <= 3 || i <= 9)
                        {
                            if (! (isdigit(item_expirydate[i]) ) )
                            {
                                goto inv;
                            }
                        }
                    }
                    jump:
                    printf("Input Item Price: ");
                    scanf("%lf", &item_price);
                    if (item_price > 0)
                    {

                        char all[1000];
                        snprintf(all, 1000, "%d,%s,%d,%s,%.2lf\n", item_id, item_description, item_quantity, item_expirydate, item_price);

                        count = 0;
                        while ((fgets(buffer, BUFFER_SIZE, fptr)) != NULL)
                        {
                            count++;
                            /* If current line is line to replace */
                            if (count == lineNum)
                                fputs(all, ftemp);
                            else
                                fputs(buffer, ftemp);
                        }

                        /* Close all files to release resource */
                        fclose(fptr);
                        fclose(ftemp);

                        /* Delete original source file */
                        remove("Inventory_ST_NoQuote_NoBOM.csv");

                        /* Rename temporary file as original file */
                        rename("replace.tmp", "Inventory_ST_NoQuote_NoBOM.csv");

                        // printf("\nSuccessfully replaced '%d' line with '%s'.", lineNum, newline);

                        printf("\nAn item has been successfully updated!\n\n");
                        return;
                    }
                    else
                    {
                        goto inv;
                    }
                }
                else
                {
                    goto inv;
                }
            }
        }
        else
        {
        inv:
            fclose(fptr);
            fclose(ftemp);
            printf("\nInput value is invalid.\n");
        }
    }
    else
    {
        printf("Item ID does not exist!\n");
    }
}