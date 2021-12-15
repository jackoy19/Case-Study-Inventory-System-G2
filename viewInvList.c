#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
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

void viewInvList(){

    int xID = 0, xDesc = 10, xQty = 50, xExp = 60, xPri = 80;
	setx(xID); printf("Item ID");
    setx(xDesc); printf("Description");
    setx(xQty); printf("Quantity");
    setx(xExp); printf("Expiry Date");
    setx(xPri); printf("Price\n");

	FILE *fptr = fopen("inventory.csv", "r");
	if (fptr == NULL){
		perror("unable to open the file.");
		exit(1);
	}
	char line[80];
	char details[500][30];

	int counter = 0;
    int lineCounter = 0;
	while(fgets(line, sizeof(line), fptr))
	{
		char *token;
		
		token = strtok(line, ","); //value before comma
		strcpy(details[counter], token);
		
		while( token != NULL ) {
			strcpy(details[counter++],token);   //copy the each values on the details array
                token = strtok(NULL, ",");
        }
        lineCounter++;
	}
	int lineNumber = 0;
	for(int y = 1; y <= lineCounter; y++) {
		for(int counterX = 0; counterX < 5; counterX++) {
                if(counterX == 0){
					setxy(xID,y);
					printf("%s",details[lineNumber]);
					lineNumber++;
				}else if(counterX == 1){
					setxy(xDesc,y);
					printf("%s",details[lineNumber]);
					lineNumber++;
				}else if(counterX == 2){
					setxy(xQty,y);
					printf("%s",details[lineNumber]);
					lineNumber++;
				}else if(counterX == 3){
					setxy(xExp,y);
					printf("%s",details[lineNumber]);
					lineNumber++;
				}else{
					setxy(xPri,y);
					printf("%s",details[lineNumber]);
					lineNumber++;
				}
		}printf("\n");
	}
}