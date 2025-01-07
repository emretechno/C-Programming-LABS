//
//  PART 1
//  CSE108 LAB
//
//  Created by Yusuf Emre Kılıçer on 10.03.2023.
//(30 pts) Write a C program that prompts theuser to enter an integer value between 1 and 100. The program prints an output by the following operations:•If the entered value is divisible by 3, output "Fizz",•If the entered value is between 5and 50, output "Buzz",•If the entered value is divisible by 3 and between5and 50, output "FizzBuzz".Note that, you are allowed to use at most two if –else statements.
void fizz_buzz(int);
#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n1;
    printf("enter an integer between 1 and 100\n");
    scanf("%d",&n1);
    fizz_buzz(n1);
    return 0;
}
void fizz_buzz(int n){
    
    
    
    while(n<1 || n >100){ /*The rule is integer must be between 1 and 100.That is why I control the user's input by this while loop.*/
        printf("Your number should be between 1 and 100\n");
        printf("enter and another ingeter.\n");
        scanf("%d",&n);
    }
    if(n%3 ==0){ /*My first if .*/
        printf("Fizz");
    }
    if(n>=5 && n<=50){ /*My second if.*/
        printf("Buzz");
    }

    
}

