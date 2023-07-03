#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Takes base and height and returns the hypothenuse.
double hypo(double base, double height){
    double squared = (pow(base, 2) + pow(height, 2));
    double hypothenuse = sqrt(squared);
    return hypothenuse;
}

// Prints plane data
int print_plane_data(double plane_height, 
                     double plane_hypo, 
                     double plane_base){
        printf("Plane Height: %.2f\n", plane_height);
        printf("Plane Hypothenuse: %.2f\n", plane_hypo);
        printf("Plane Base: %.2f", plane_base);
    return 0;
}

//Prints profile data
int print_profile_data(double profile_height, 
                       double profile_hypo, 
                       double profile_base){
    printf("Profile Height: %.2f\n", profile_height);
    printf("Profile Hypothenuse: %.2f\n", profile_hypo);
    printf("Profile Base: %.2f\n", profile_base);
    return 0;
}


int main (void){            
    // Initial base length minus the quarter circle cut away part.
    double initial_base = 120 - ((27.5*2)/3.14159265358979323846);
    double profile_base = initial_base;
    double profile_height = 180;
    double profile_hypo;
    double plane_base = initial_base;
    double plane_height = 20;
    double plane_hypo;
    // The construction's lowest post.
    int lowest_post = 80;
    int i = 0;
    while(profile_height >= lowest_post){
        i = i + 1;
        printf("\n\n\nTriangle: %d \n", i);
        //Call function to calculate the hypo of profile
        profile_hypo = hypo(profile_base, profile_height);
        print_profile_data(profile_height, profile_hypo, profile_base);
        //Call function to calculate the hypo of plane.
        plane_hypo = hypo(plane_base, plane_height);        
        print_plane_data(plane_height, plane_hypo, plane_base);
        //Move profile base to new plane hypo and adjust heights.
        profile_base = plane_hypo;
        profile_height -= 20;
        plane_height += 20;
    }
    return 0;
}