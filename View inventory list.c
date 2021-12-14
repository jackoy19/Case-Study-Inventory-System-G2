#include <stdio.h>

int main() {
	FILE *the_file = fopen("Case Study CSV.csv", "r");
	if (the_file == NULL){
		perror("unable to open the file.");
		exit(1);
	}
	char line[80];
	
	while(fgets(line, sizeof(line), the_file))
	{
		char *token;
		
		token = strtok(line, ",");
		
		while(token!= NULL) {
			printf("%s", token);
			token = strtok(NULL, ",");
		}
		printf("\n");
	}
}
