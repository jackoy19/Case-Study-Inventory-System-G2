#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcExist.c"
#include "getLine.c"
#define BUFFER_SIZE 1000

void updateItem(){
	
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

	/* File pointer to hold reference of input file */
    FILE *fptr = fopen("inventory.csv", "r");
    FILE *fTemp = fopen("replace.tmp", "w");
    char path[100];
    
    
    char buffer[BUFFER_SIZE];
    int count;
 
    /* Remove extra new line character from stdin */
    fflush(stdin);

    int item_id, item_quantity;
	char item_description[50], item_expirydate[50];
	char temp;
	char *itdp=item_description, *itep=item_expirydate;
	double item_price;
	
	printf("Input Item ID: ");
	scanf("%d", &item_id);
		if ((item_id >= 11101) && (item_id <= 69999)) {
			if ((funcExist(&item_id) > 0) && (item_id != Item_ID)) {
				printf("\nItem ID already exists in inventory!\n\n");
			}
			else {
				printf("Input Item Description: ");
				scanf("%c", &temp);
				fgets(item_description, 50, stdin);
				item_description[strcspn(item_description, "\n")] = 0;
				printf("Input Quantity: ");
				scanf("%d", &item_quantity);
					if(item_quantity >= 0) {
						printf("Input Expiry Date :");
						scanf("%c", &temp);
						fgets(item_expirydate, 50, stdin);
						item_expirydate[strcspn(item_expirydate, "\n")] = 0;
						printf("Input Item Price: ");
						scanf("%lf", &item_price);
							if(item_price > 0) {
								
								FILE *fp;
    							fp = fopen("inventory.csv","a+");

                                char all[1000];
                                snprintf(all, 1000, "\n%d,%c,%d,%c,%lf", item_id, item_description, item_quantity, item_expirydate, item_price);
                                printf(all);    
                                    //fgets(buffer, BUFFER_SIZE, all);
 
                                    count = 0;
                                    while ((fgets(buffer, BUFFER_SIZE, fptr)) != NULL)
                                    {
                                        count++;
                                        /* If current line is line to replace */
                                        if (count == lineNum)
                                            fputs(all, fTemp);
                                        else
                                            fputs(buffer, fTemp);
                                    }
                                    /* Close all files to release resource */
                                    fclose(fptr);
                                    fclose(fTemp);

                                    /* Delete original source file */
                                    remove("inventory.csv");
                                
                                    /* Rename temporary file as original file */
                                    rename("replace.tmp", "inventory.csv");
                                
                                    //printf("\nSuccessfully replaced '%d' line with '%s'.", lineNum, newline);

								printf("\nAn item has been successfully updated!");
								
								fclose(fp);
								
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
			printf("Input value is invalid.");
		}

    
}

int main(){
    updateItem();
    return 0;
}