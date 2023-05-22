#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double hypo(double base, double height){

    double squared = (pow(base, 2) + pow(height, 2));
    double hypothenuse = sqrt(squared);

    return hypothenuse;
}


int main (void){

    double profile_base = 1;
    double profile_height = 1;

    double profile_hypo = hypo(profile_base, profile_height);
    printf("this should be sqrt2 %.1f \n", profile_hypo);



    double plane_hypo;
    double plane_base;
    double plane_height;


    return 0;
}