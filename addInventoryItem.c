void addInventoryItem(){
    int item_id, item_quantity;
	char item_description[50], item_expirydate[50];
	char temp;
	char *itdp=item_description, *itep=item_expirydate;
	double item_price;
	char input[6];

	fflush(stdin);
	printf("Input Item ID: ");
	fgets(input,7,stdin);
	item_id = atoi(input);

		if ((item_id >= 11101) && (item_id <= 69999)) {
			if (funcExist(&item_id) > 0) {
				printf("\nItem ID already exists in inventory!\n\n");
			}
			else {
				printf("Input Item Description: ");
				scanf("%c", &temp);
				fgets(item_description, 50, stdin);
				item_description[strcspn(item_description, "\n")] = 0;
				printf("Input Quantity: ");
				scanf("%d", &item_quantity);
					if(item_quantity >= 0 && (item_quantity <= 1000000)) {
						printf("Input Expiry Date :");
						scanf("%c", &temp);
						fgets(item_expirydate, 50, stdin);
						item_expirydate[strcspn(item_expirydate, "\n")] = 0;
						printf("Input Item Price: ");
						scanf("%lf", &item_price);
							if(item_price > 0) {
								
								FILE *fp;
    							fp = fopen("inventory.csv","a+");

								fprintf(fp,"\n\"%d\",\"%s\",\"%d\",\"%s\",\"%.2lf\"", item_id, item_description, item_quantity, item_expirydate, item_price);
								
								printf("\nAn item has been succesfully added!\n");
								
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
			printf("Input value is invalid.\n");
		}
}