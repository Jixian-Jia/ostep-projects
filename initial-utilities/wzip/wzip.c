#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//return the size of output in bytes.
int compress_line(char *line, int size, char *compressed){
    int size_counter = 0;
    int i;
    int rep_counter = 0;
    for (i = 0; i<size -1 ; i++){
        if (line[i] == line [i+1]){
            rep_counter++;
        }
        else{
            if (rep_counter != 0){
                compressed[size_counter] = rep_counter+1;
                compressed[size_counter+4] = line[i];
                size_counter += 5;
                rep_counter = 0;
            }
        }
    }
    
    return size_counter;
}

int main(int argc, char* argv[]){

    if (argc == 1){
        fprintf(stdout,"wzip: file1 [file2 ...]\n");
        exit(1);
    }
    FILE *fp = NULL;
    char *line_buffer;
    size_t len = 0;  
    //char *next_line = "\n";
    int file_counter = 1;
    while(file_counter < argc){
        if ((fp = fopen(argv[file_counter++],"r")) == NULL){
            exit(1);
        }
        while(getline(&line_buffer,&len,fp) != -1){
            char output_butffer[len];
            int output_size = compress_line(line_buffer,len,output_butffer);
            //strcat(output_butffer+output_size,next_line);
            fwrite(output_butffer,1,output_size,stdout);
            len = 0;
            free(line_buffer);
        }
        fclose(fp);
    }
    return 0;
}