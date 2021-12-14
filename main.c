#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char choice = ' ';
	
	while(choice != 'X'){
		printf("MAIN MENU\n");
		printf("[A] Add Inventory Item\n");
		printf("[B] Update Inventory Item\n");
		printf("[C] View Inventory List\n");
		printf("[D] Search Inventory Item\n");
		printf("[X] Exit Program\n");
 		
 		switch(choice){
 			case 'A':
 				break;
 			case 'B':
 				break;
 			case 'C':
 				break;
 			case 'D':
 				break;
 			case 'X': printf("BYE");
			 	break;
			default:  printf("Please input valid choice!");
 				break;
		}
		scanf("%c", toupper(choice));
		printf("%c", choice);   

	}
}
