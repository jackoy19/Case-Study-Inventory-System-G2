#include "getPositionSort.c"
#include "writeToLine.c"

void addInventoryItem()
{
	int item_id;
	char item_description[42], item_expirydate[50];
	char temp;
	char item_price[100] = "";
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
			printf("Input Item Description: ");
			// scanf("%c", &temp);
			fgets(item_description, 42, stdin);
			if(strcspn(item_description, "\n") > 40){
				goto inv;
			}

			item_description[strcspn(item_description, "\n")] = 0;
			printf("Input Quantity: ");
			scanf("%s", item_quantity);
			length = strlen(item_quantity);
			for (i = 0; i < length; i++)
				if (!isdigit(item_quantity[i]))
				{
					goto inv;
				}
			int itemquantity = atoi(item_quantity);
			if (itemquantity >= 0)
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
				scanf("%s", item_price);
				length = strlen(item_price);

				// returns false if position of period in the input is different
				if (!(strchr(input, '.') - strrchr(input, '.')) == 0)
				{
					goto inv;
				}

				for (i = 0; i < length; i++)
					if (!(isdigit(item_price[i]) || '.' == item_price[i]))
					{
						goto inv;
					}

				double itemprice = atof(item_price);
				if (itemprice > 0)
				{

					int lineNum = getPositionSort(&item_id); //get Line number position on inventory file

					FILE *fp;
					fp = fopen(fileName, "a+");

					char all[1000];
					snprintf(all, 256, "%d,%s,%d,%s,%.2lf\n", item_id, item_description, itemquantity, item_expirydate, itemprice);

					/* Write in the line number it returns, if Item Id to be added 
					  is highest number(lineNum returns 0) add on the bottom */
					if (lineNum > 0)
					{
						fclose(fp);
						writeToLine(all, &lineNum);
					}
					else
					{
						fprintf(fp, "\n%d,%s,%d,%s,%.2lf", item_id, item_description, itemquantity, item_expirydate, itemprice);
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
		printf("\nInput value is invalid.\n");
	}
}
