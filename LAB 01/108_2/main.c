//
//  PART 2.
//  108_2
//
//  Created by Yusuf Emre Kılıçer on 10.03.2023.
 //Write a C program that takes Xand Ydecimal numbers from the user and calculates the Zvalue by the following formula:𝑍=𝑋𝑌+max(𝑋,𝑌)𝑋+𝑌Please note that you can’tuse any type of function to determine which of X and Y is the maximum value.

#include <stdio.h>

int main(int argc, const char * argv[]) {
    float x,y;
    printf("Enter the x value\n");
    scanf("%f",&x);
    printf("Enter the y value\n");
    scanf("%f",&y);
    int max = x; /* I assigned max to x .*/
    if (y >x) {  /* But if y > x , i can say that max is y.*/
        max =y;
    }
    float z= (x/y) + (max/(x+y));
    printf("the value of z is %.3f:\n",z);
    return 0;
}
