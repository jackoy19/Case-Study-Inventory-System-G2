#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lineShow(int itemId) {
  //printf("ITEM ID: %d\n", itemId); 
	FILE *fp = fopen("inventory.csv", "r");
	
	char line[100][120];
	
    int i = 0;
    int tot = 0;
   
    while(fgets(line[i], 120, fp)){
        line[i][strlen(line[i]) - 1] = '\0';
        //printf("VALUES: %c\n", line[i][strlen(line[i]) - 1]); 
        i++;
    }
    tot = i;
		printf("%s\n", line[itemId-1]);
    printf("\n");
    fclose(fp);
    return 0;
}
