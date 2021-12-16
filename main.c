#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funcExist.c"
#include "getLine.c"
#include "addInventoryItem.c"
#include "searchItem.c"
#include "updateItem.c"
#include "viewInvList.c"
#include "EXPI_viewInvList.c" // EXPERIMENTAL

int main(){
	
	char choice[3];
	
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
		fgets(choice,2,stdin);
		
		if(strlen(choice)> 1 || choice == NULL){
			printf("\nPlease input valid choice!\n\n");
		}else{
			switch(toupper(choice[0])){
 			case 'A': addInventoryItem();
 				break;
 			case 'B': updateItem();
 				break;
 			case 'C': EXPI_viewInvList();
			 		  printf("\n");
 				break;
 			case 'D': searchItem();
 				break;
			case 'X': printf("TERMINATED\n");
			 	break;
			default: printf("\nPlease input valid choice!\n\n");
 				break;
			}
		}	
	}
	while(toupper(choice[0]) != 'X');	
}
