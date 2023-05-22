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
    // double initial_profile_height = 20;

    double profile_base = initial_base;
    double profile_height = 180;
    double profile_hypo;
    // = hypo(initial_base, profile_height);


    double plane_base = initial_base;
    double plane_height = 20;
    double plane_hypo;
    // = hypo(initial_base, plane_height);


        int i = 0;
    while(profile_height >= 80){
         i = i + 1;
//        printf("Iteration: %d \n\n", i);


        //call function to calculate the hypo of profile
        profile_hypo = hypo(profile_base, profile_height);
        //print profile data
        printf("\nTriangle #%d \n\nProfile: \n", i);
        printf("Hypothenuse: %.1f\n", profile_hypo);
        printf("Base: %.1f\n", profile_base);
        printf("Height: %.1f\n\n", profile_height);

        //call function to calculate the hypo of plane
        plane_hypo = hypo(plane_base, plane_height);        
        //print plane data
        printf("Plane: \n");
        printf("Height: %.1f\n", plane_height);
        printf("Hypothenuse: %.1f\n", plane_hypo);
        printf("Base: %.1f\n\n______________", plane_base);

        //move profile base to new plane hypo
        profile_base = plane_hypo;



        profile_height -= 20;
//        printf("pr_he: %.f \n", profile_height);

        plane_height += 20;
//        printf("pl_he: %.f \n\n\n", plane_height);
    }


    return 0;
}