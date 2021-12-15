#include <windows.h>
#include<stdio.h>
#include<conio.h>
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

int main()
{
    setx(0);
    printf("Item ID");

    setx(10);
    printf("|Description");

    setx(60);
    printf("|Quantity");

    setx(70);
    printf("|Expiry Date");

    setx(90);
    printf("|Price\n");

    for(int i = 0; i<10; i++){
        setxy(10, i);
        printf("|");

        setxy(60, i);
        printf("|");

        setxy(70, i);
        printf("|");

        setxy(90, i);
        printf("|");
    }
 return 0;
}
