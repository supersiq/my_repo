# include <stdio.h>
# include <stdlib.h>

int main(void){

    printf("test");

    FILE *in_file;
    int number1;

    in_file = fopen("number.txt", "r");
    for(int i=0; i!=3; i++){
        if (in_file == NULL)
        {
            printf("Can't open file for reading.\n");
        }
        else
        {
            fscanf(in_file, "%d", &number1);
            printf("%d \n", number1);
        }
    }
    fclose(in_file);
    return 0;
}