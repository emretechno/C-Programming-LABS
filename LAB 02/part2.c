#include <stdio.h>
#include <math.h>
#define pi 3.14



int main(){

    double weigth , height;
    printf("Please enter your weight(unity is kg) .\n");
    scanf("%lf",&weigth);
    printf("Please enter your height(unity is meter)\n");
    scanf("%lf",&height);

    
    double BMI = weigth /(height * height);
       
    printf("Your BMI =%lf\n",BMI);
    if( BMI<=18.5){
        printf("UNDERWEIGHT.");
    }
    else if (BMI >18.5 && BMI <= 24.9){
        printf("AVERAGE WEIGHT.");
    }
    else if(BMI>25 && BMI<=29.9) {
        printf("OVERWEIGHT.");
    }
    else {
        printf("OBESE");
    }
    return 0;
}


