#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funcExist.c"
#include "getPositionSort.c"
#include "writeToLine.c"

int main()
{
	int item_id;
	char item_description[50], item_expirydate[50];
	char temp;
	double item_price;
	char input[6];
	char item_quantity[100] = "";
	int length, i;

	fflush(stdin);
	printf("Input Item ID: ");
	fgets(input, 7, stdin);
	item_id = atoi(input);

	if ((item_id >= 11101) && (item_id <= 69999))
	{
		if (funcExist(&item_id) > 0)
		{
			printf("\nItem ID already exists in inventory!\n\n");
		}
		else
		{
			{
			
			printf("Input Item Description: ");
			// scanf("%c", &temp);
			fgets(item_description, 50, stdin);
			item_description[strcspn(item_description, "\n")] = 0;
			printf("Input Quantity: ");
			scanf("%s", item_quantity);
			length = strlen (item_quantity);
    			for (i=0;i<length; i++)
				if (!isdigit(item_quantity[i]))
					{
           					goto inv;
           					exit(1);
       					}					
			}
			if (item_quantity >= 0)
			{
				printf("Input Expiry Date (yyyy-mm-dd or -): ");
				scanf("%c", &temp);
				fgets(item_expirydate, 50, stdin);
				item_expirydate[strcspn(item_expirydate, "\n")] = 0;
				printf("Input Item Price: ");
				scanf("%lf", &item_price);
				if (item_price > 0)
				{

					int lineNum = getPositionSort(&item_id);

					FILE *fp;
					fp = fopen("Inventory_ST_NoQuote_NoBOM.csv", "a+");
					
					char all[1000];
                    			snprintf(all,256,"%d,%s,%s,%s,%.2lf\n", item_id, item_description, item_quantity, item_expirydate, item_price);

					if (lineNum > 0)
					{
						fclose(fp);
						writeToLine(all,&lineNum);
					} else {
						fprintf(fp, "\n%d,%s,%s,%s,%.2lf", item_id, item_description, item_quantity, item_expirydate, item_price);
						fclose(fp);
					}
					printf("\nAn item has been succesfully added!\n");
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
		printf("Input value is invalid.\n");
	}
	return 0;
}
