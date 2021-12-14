#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main() {	

	int *item_id, *item_quantity;
	char item_description[50], item_expirydate[50];
	char temp;
	char *itdp=item_description, *itep=item_expirydate;
	double *item_price;
	
	printf("Input Item ID: ");
	scanf("%d", &item_id);
		if ((item_id >= 11101) && (item_id <= 69999)) {
			if (funcExist == 1) {
				printf("Item ID already exists in inventory!");
			}
			else {
				printf("Input Item Description: ");
				scanf("%c", &temp);
				fgets(item_description, 50, stdin);
				item_description[strcspn(item_description, "\n")] = 0;
				printf("Input Quantity: ");
				scanf("%d", &item_quantity);
					if(item_quantity >= 1) {
						printf("Input Expiry Date: ");
						scanf("%c", &temp);
						fgets(item_expirydate, 50, stdin);
						item_expirydate[strcspn(item_expirydate, "\n")] = 0;
						printf("Input Item Price: ");
						scanf("%lf", &item_price);
							if(item_price > 0) {
								
								FILE *fp;
    							fp = fopen("inventory.csv","a+");

								fprintf(fp, "%d , %s , %d , %s , %lf\n", item_id, item_description, item_quantity, item_expirydate, item_price);
								
								printf("\nNew item has been added.");
								
								fclose(fp);
								
								return 0;
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
			
	return 0;
}

