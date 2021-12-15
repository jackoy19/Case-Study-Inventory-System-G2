#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

COORD c = {0, 0};

void setx (int x)
{
 c.X = x; // Set X and Y coordinates
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setxy (int x, int y)
{
 c.Y = y;
 c.X = x; // Set X and Y coordinates
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main() {

	setx(0); printf("Item ID");
    setx(10); printf("Description");
    setx(60); printf("Quantity");
    setx(70); printf("Expiry Date");
    setx(90); printf("Price\n");

	FILE *fptr = fopen("inventory.csv", "r");
	if (fptr == NULL){
		perror("unable to open the file.");
		exit(1);
	}
	char line[80];
	char details[1000][30];
	int xID = 0, xDesc = 10, xQty = 60, xExp = 70, xPri = 90;
	
	int counter = 0;
	while(fgets(line, sizeof(line), fptr))
	{
		char *token;
		
		token = strtok(line, ","); //value before comma
		strcpy(details[counter], token);
		
		while( token != NULL ) {
			strcpy(details[counter++],token);   //copy the each values on the details array
                token = strtok(NULL, ",");
        }
	}
	for(int x = 1; x <= counter; x++) {
		for(int counterX = 0; counterX < 5; counterX++) {
                if(counterX == 0){
					setxy(xID,counter);
					printf("%s",details[x]);
				}else if(counterX == 1){
					setxy(xDesc,counter);
					printf("%s",details[x]);
				}else if(counterX == 2){
					setxy(xQty,counter);
					printf("%s",details[x]);
				}else if(counterX == 3){
					setxy(xExp,counter);
					printf("%s",details[x]);
				}else{
					setxy(xPri,counter);
					printf("%s\n",details[x]);
				}
		}
	}
}
