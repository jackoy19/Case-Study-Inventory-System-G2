#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fptr = fopen("TESTinventory.csv", "r");
    int size;
    fseek (fptr, 0, SEEK_END);
    size = ftell(fptr);
    if (size == 0) {
        printf("file is empty\n");
    }

    fclose(fptr);

    return 0;
}