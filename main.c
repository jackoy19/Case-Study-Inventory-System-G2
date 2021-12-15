#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcExist.c"
#include "getLine.c"
#include "searchItem.c"
#include "updateItem.c"

int main(){
	
	char choice = ' ';
	
	do{
		printf("MAIN MENU\n");
		printf("[A] Add Inventory Item\n");
		printf("[B] Update Inventory Item\n");
		printf("[C] View Inventory List\n");
		printf("[D] Search Inventory Item\n");
		printf("[X] Exit Program\n");
 		
 		printf("\nPlease input choice: ");
 		
 		scanf(" %c", &choice);
	
 		switch(choice){
 			case 'A':
 				break;
 			case 'B': updateItem();
 				break;
 			case 'C':
 				break;
 			case 'D': searchItem();
 				break;
 			case 'X': printf("BYE");
			 	break;
			default: printf("Please input valid choice!");
 				break;
		}
		
	}while(choice != 'X');
	
}
