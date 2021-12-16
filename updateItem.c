#define BUFFER_SIZE 1000
void updateItem(){
	
	int Item_ID;
    char input[6];

    fflush(stdin);
    printf("Input Item ID: ");
    fgets(input,7,stdin);

    Item_ID = atoi(input);
    if (!(Item_ID >= 11101 && Item_ID <= 69999)) {
        printf("Item ID is invalid!\n");
        return;
    }
    int lineNum = funcExist(&Item_ID);
    if (lineNum > 0) {
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

    int item_id, item_quantity = 0;
	char item_description[50], item_expirydate[50];
	char temp;
	char *itdp=item_description, *itep=item_expirydate;
	double item_price;
	
	printf("Input Item ID: ");
	scanf("%d", &item_id);
		if ((item_id >= 11101) && (item_id <= 69999)) {
			if ((funcExist(&item_id) > 0) && (item_id != Item_ID)) {
				printf("\nItem ID already exists in inventory!\n\n");
				fclose(fptr);
				fclose(ftemp);
			}
			else {
				printf("Input Item Description: ");
				scanf("%c", &temp);
				fgets(item_description, 50, stdin);
				item_description[strcspn(item_description, "\n")] = 0;
				printf("Input Quantity: ");
				scanf("%d", &item_quantity);
					if(item_quantity >= 0) {
						printf("Input Expiry Date (yyyy-mm-dd or -): ");
						scanf("%c", &temp);
						fgets(item_expirydate, 50, stdin);
						item_expirydate[strcspn(item_expirydate, "\n")] = 0;
						printf("Input Item Price: ");
						scanf("%lf", &item_price);
							if(item_price > 0) {
								
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
                                
                                    //printf("\nSuccessfully replaced '%d' line with '%s'.", lineNum, newline);

								printf("\nAn item has been successfully updated!\n\n");
								return;
							}else{
								goto inv;
							}
					}else{
						goto inv;
					}
			}
		}
		else {
			inv:
            fclose(fptr);
            fclose(ftemp);
			printf("Input value is invalid.");
		}

    } else {
        printf("Item ID does not exist!\n");
    }

	
}