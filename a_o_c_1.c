# include <stdio.h>
# include <stdlib.h>

int main(void){
    FILE *in_file;
    //Array for storing the numbers.
    int numbers[1024];

    in_file = fopen("number.txt", "r");
    if (in_file == NULL)
    {
        printf("Can't open file for reading.\n");
        return 0;
    }


    int i = 0;
    fscanf(in_file, "%d", &numbers[i]);
    printf("%d \n", numbers[i]);
    // Want to iterate in between the lines in numbers.txt
    while(fscanf(in_file, "%d", &numbers[i]) != NULL){
    printf("%d \n", numbers[i]);
        i = i +1;
            if(i==4){
                //Exit
                fclose(in_file);
                printf("damn");
                return 0;
            }

        
    }       
    printf("i made it here  hello");
    fclose(in_file);
    return 0;
}