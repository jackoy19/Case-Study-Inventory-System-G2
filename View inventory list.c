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
	char details[100][500];
	int xID = 0, xDesc = 10, xQty = 60, xExp = 70, xPri = 90;
	int counter = 1;
	while(fgets(line, sizeof(line), fptr))
	{
		char *token;
		
		token = strtok(line, ","); //value before comma
		
		while(token!= NULL) {
			for(; counter <=5; counter++){
				switch(counter){
				case 1: setx(xID);
						printf("%s", token);
						token = strtok(NULL, ",");
						break;
				case 2: setx(xDesc);
						printf("%s", token);
						token = strtok(NULL, ",");
						break;
				case 3: setx(xQty);
						printf("%s", token);
						token = strtok(NULL, ",");
						break;
				case 4: setx(xExp);
						printf("%s", token);
						token = strtok(NULL, ",");
						break;
				case 5: setx(xPri);
						printf("%s", token);
						token = strtok(NULL, ",");
						printf("\n");
						break;
				default:break;
				}
			}
			
		}
		//printf("\n");
	}
	getch();
	
}
