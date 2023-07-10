#include <stdio.h>
#include <stdlib.h>



int main(int argc, char* argv[]){
    
    char *buffer = NULL ;
    size_t len = 0;
    int counter = 1;
    
    if (argc == 1){
        exit(0);
    }
    while(counter < argc){

        FILE *fp = fopen(argv[counter++],"r");
        if (fp == NULL){
            printf("wcat: cannot open file\n");
            exit(1);
        }
        
        while(getline(&buffer,&len,fp) != -1){
            printf("%s", buffer);
        }
        fclose(fp);
        free(buffer);
    }
    ;
    return 0;
    



}