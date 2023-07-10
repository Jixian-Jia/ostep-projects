#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(char *line, size_t line_size, char *word, size_t word_size){
    int i,j;
    for (i = 0; i<= line_size - word_size; i++){
        for (j = 0; j< word_size; j++){
            if (line[i+j] != word[j]){
                break;
            }
            
        }
        if (j == word_size)
                return 1; //found the word
        
    }
    return 0; //not found
}

int main(int argc, char *argv[]){

    char *buffer;
    size_t len = 0;

    FILE *fp;
    if (argc == 1){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    if (argc == 2){

        while(getline(&buffer,&len,stdin) != -1){
            if(search(buffer,len,argv[1],strlen(argv[1])) == 1)
                printf("%s", buffer);
            len = 0;
        }
        free(buffer);
    }
       
    else{
        fp = fopen(argv[2],"r");
        if (fp == NULL){
            printf("wgrep: cannot open file\n");
            exit(1);
        }
    

        while(getline(&buffer,&len,fp) != -1){
            if(search(buffer,len,argv[1],strlen(argv[1])) == 1)
                printf("%s", buffer);
            len = 0;
        }
        fclose(fp);
        free(buffer);
    }
    return 0;
    



}