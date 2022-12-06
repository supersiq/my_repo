# include <stdio.h>
# include <stdlib.h>

int main(void){

    printf("test\n");

    FILE *in_file;
    int number1;

    in_file = fopen("input_a_o_c_1.txt", "r");
    for(int i=0; i!=14; i++){
        if (in_file == NULL)
        {
            printf("Can't open file for reading.\n");
            return 0;
        }
        else
        {
            fscanf(in_file, "%d", &number1);
            if (in_file == '\n'){
                i = i - 1;
                printf("bonjour");
            }
            printf("Iteration: %d, %d \n",i , number1);
            
        }
    }
    fclose(in_file);
    return 0;
}