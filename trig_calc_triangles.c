#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double hypo(double base, double height){

    double squared = (pow(base, 2) + pow(height, 2));
    double hypothenuse = sqrt(squared);

    return hypothenuse;
}


int main (void){


    double initial_base = 120 - ((27.5*2)/3.14159265358979323846);
    printf("%.1f", initial_base);
    double profile_base;
    double profile_height = 180;

    double profile_hypo = hypo(profile_base, profile_height);
//    printf("this should be sqrt2 %.2f \n", profile_hypo);



    double plane_base;
    double plane_height;
    double plane_hypo = hypo(plane_base, plane_height);


    int i = 0;
    while(profile_height != 80){
        i = i + 1;
        printf("iteration: %d \n", i);
        profile_height -= 20;    
    }


    return 0;
}