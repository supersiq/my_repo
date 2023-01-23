# include <stdio.h>
# include <stdlib.h>

int main(void){
    FILE *in_file;
    int number1;

    in_file = fopen("number.txt", "r");
    if (in_file == NULL)
    {
        printf("Can't open file for reading.\n");
        return 0;
    }

    fscanf(in_file, "%d", &number1);
    if (in_file == '%\n'){
        printf("bonjour");
        return 0;
    }
    printf("i made it here  hello   ");
    fclose(in_file);
    return 0;
}