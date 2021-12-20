#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

char fileName[] = "Inventory_ST_NoQuote_NoBOM.csv";

#include "funcExist.c"
#include "getLine.c"
#include "addInventoryItem.c"
#include "searchItem.c"
#include "updateItem.c"
#include "viewInvList.c"



int main(){
	
	char choice[4];
	int len;
	
	do{
		printf("MAIN MENU\n");
		printf("[A] Add Inventory Item\n");
		printf("[B] Update Inventory Item\n");
		printf("[C] View Inventory List\n");
		printf("[D] Search Inventory Item\n");
		printf("[X] Exit Program\n");
 		
 		printf("\nPlease input choice: ");
 		fflush(stdin);
 		// scanf(" %s", &choice[0]);

		fgets(choice,4,stdin);
		int len = strcspn(choice, "\r\n");
		
		if(len > 1 || choice == NULL){
			printf("\nPlease input valid choice!\n\n");
		} else {
			printf("\n");

			switch(toupper(choice[0])){
				case 'A': addInventoryItem();
					break;
				case 'B': updateItem();
					break;
				case 'C': viewInvList();
						printf("\n");
					break;
				case 'D': searchItem();
					break;
				case 'X': printf("TERMINATED");
					break;
				default: printf("Please input valid choice!\n\n");
					break;
			}
		}
	}
	while(toupper(choice[strcspn(choice,"\r\n") - 1]) != 'X' || strcspn(choice, "\r\n") > 1);	
}
