#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int romanToInt(char * s){
    int len = strlen(s);
    printf("length of input roman number is %d\n", len);
    int arabic_number = 0;

    
    
    for (int i = 0; i <= len; i ++){
        arabic_number = (int)s[i];
        printf("%d", arabic_number);
        // - '0';
        //arabic_number = (int)s[i];
        //printf("%d", arabic_number);
        
        printf("iteration %d: %c\n", i, s[i]);
    }
    return arabic_number;
}

int main(){

 //   char str[10] = "hell";
 //   int len = strlen(str);
 //   printf("%s is a %d letter word\n", str, len);
//
 //   for (int i = 0; i < len; i ++){
 //       printf("%s\n", str[i]);
 //   }

    char s[3] = "IVX";
    int n = romanToInt(s);
    printf("the roman number %s in arabic is = %d",s ,  n);

    return 0;
}