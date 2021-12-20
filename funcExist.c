int funcExist(int *itemId) {
    int foundInLine = 1;
    char item[6];
    sprintf(item,"%d",*itemId); // converts int to char
    FILE *fptr = fopen(fileName, "r"); 
    char line[120];
    while (!feof(fptr))  // loop until end of the file
    {
        fgets(line, 120, fptr);  //store the whole line in variable line
        //below if compare if the Item_ID is matched on inventory
        if(strcmp(item,strtok(line,",")) == 0) {
            fclose(fptr);
            // printf("Found\n");
            return foundInLine;
        }
        foundInLine++;
    }
    fclose(fptr);
    // printf("Item ID does not exist!");
    return 0;
}