//
//  main.c
//  lab_5
//
//  Created by Yusuf Emre Kılıçer on 7.04.2023.
//

#include <stdio.h>
#include <math.h>
/*Part 1 functions*/
void menu_part1();
double celc_to_fahr(double);
double fahr_to_celc(double);
/*Part 2 functions*/
int make_reverse(int);
int find_digit(int);
/*Part 3 functions*/
void menu_part3();
int to_octal(int);
int to_binary(int);
int to_hexadecimal(int);


int main() {
    /*------------------------PART 1----------------------*/
   printf("------------------------PART 1----------------------\n\n");
   menu_part1(); /*My part 1 menu.*/
   


    /*------------------------PART 2----------------------*/
    printf("------------------------PART 2----------------------\n\n");
    int nbr;
    int digit;
    printf("Enter a number (3,4,5 digits)\n");
    scanf("%d",&nbr);
    digit = find_digit(nbr); /*I check the digit to check the digit of number.*/

    while(digit <3 || digit >5){  /*Checking the digit numbers.*/
        printf("Plese enter only 3 ,4 ,5 digit numbers!\n");
        scanf("%d",&nbr);
        digit = find_digit(nbr); /*If still user enters to invalid digit , I check.*/
    }
   int reverse = make_reverse(nbr);
   printf("Reversed number is %d:\n\n",reverse);





    printf("------------------------PART 3----------------------\n\n");

       menu_part3();
  
    return 0;

}


void menu_part1(){
     int op;
    int flag =1;
    double entered;
    double calculate;
    do { /*Do while is essential in infinite loop until user exits.*/
        printf("\nTemperature Conversion Menu\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Quit\n");
        scanf("%d",&op);
        switch (op)
        {
       case 1:
   printf("Enter the temperature value to convert:");
   scanf("%lf",&entered);
   calculate = celc_to_fahr(entered); /*My function convert celcius to fahr.*/
   printf("%.2lf Celcius = %.2lf Fahrenheit\n",entered,calculate);
   
       break;
       case 2:

     printf("Enter the temperature value to convert:");
       scanf("%lf",&entered);
      calculate = fahr_to_celc(entered);  /*My function convert fahr to celcius.*/
     printf("%.2lf Fahrenheit = %.2lf Celcicus\n",entered,calculate);

       break;
       case 3:
    flag =0;
       break;
        
        default:
        printf("INVALID CHOICE!ENTER MAKE A VALID CHOICE\n\n");
            break;
        }
    } while (flag); /*My menu is gonna run until user exits.*/
    
}

double celc_to_fahr(double entered){
    double calculated =  (9 * entered) /5  +32;
    return calculated;

}
double fahr_to_celc(double entered){
    double calculated =   ( (entered - 32) *5)/9;
    return calculated;

}
int find_digit(int nbr){
    int count_digit=0;
    while (nbr !=0)
    {
        nbr = nbr /10;
        count_digit++;
    }
   return count_digit;
    
}
int make_reverse(int nbr){
  
    int remainder;
    int reverse =0; /*This is gonna be my result.*/
    while(nbr !=0){
        remainder = nbr %10; /*Firslt find the remainder.*/
        reverse = (reverse *10) + remainder; /*After multipyl reverse by  10 , then add the remainder.*/
        nbr = nbr/10;

    }
    return reverse; /*returning the reverse*/
}
void menu_part3(){ /*My menu works constantly until user quits.I used do while and flag.*/
       int result_octal,result_binary,result_hexadecimal;
       int op;
       int nbr;
    int flag =1;
    
    do {
        printf("\n\nMake a choice !\n\n");
        printf("1. Convert a number to decimal, binary, octal, and hexadecimal\n");
        printf("2. Quit\n");
        scanf("%d",&op);
        switch (op)
        {
            case 1:
                printf("Enter a number:");
                scanf("%d",&nbr);
                printf("Decimal equivalent: %d\n",nbr);
                result_binary = to_binary(nbr); /*converting to binary.*/
                printf("Binary equivalent: %d\n",result_binary);
                result_octal = to_octal(nbr);
                printf("Octal equivalent is :%d\n",result_octal);
                result_hexadecimal = to_hexadecimal(nbr);
                printf("Hexadecimal equivalent is :%d\n",result_hexadecimal);
                
                
                
                
                
                break;
                
                
            case 2:
                printf("You quit!\n");
                flag =0;
                break;
                
                break;
                
            default:
                
                printf("INVALID CHOICE!\n\n");
                break;
        }

    }while(flag);



}
/*My all converting  functions have same logic.I think there is no need to explain the other same logic.*/
int to_binary(int nbr){
int remainder;
int result =0;
int i =0;


    while (nbr !=0)
    {
        remainder = nbr % 10; /*Finding remainder.*/
        result = result + remainder * pow(2,i); /*binary is the 2 based number.Every time I find the remainder , I multiply it by base of two and sum them constantly to find the result.*/
        i++; /*Tabanin ussunu bir arttiririz her islemde.*/
        nbr = nbr /10;
    }
    return result;
}

int to_octal(int nbr){
int remainder;
int result =0;
int i =0;


    while (nbr !=0)
    {
        remainder = nbr % 10;
        result = result + remainder * pow(8,i); /*8 based displaying.*/
        i++;
        nbr = nbr /10;
    }
    return result;
}
int to_hexadecimal(int nbr){
int remainder;
int result =0;
int i =0;


    while (nbr !=0)
    {
        remainder = nbr % 10;
        result = result + remainder * pow(16,i);
        i++;
        nbr = nbr /10;
    }
    return result;
}
