//
//  PART 3
//  108_3
//
//  Created by Yusuf Emre Kılıçer on 10.03.2023.
//(40pts)Write  a  C  program  that prompts  the  user  to  enter  age  andyears  of  experience  of  an employer to calculateand printher/hissalary by the lookup table in below:

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int age, experience;
    printf("please enter your age\n");
    scanf("%d",&age);
    printf("enter your years of  experience\n");
    scanf("%d",&experience);
    
    
    while(experience<0 || age <=0 || (experience>=age)){ /*I know that age cannot be less than or equal to 0.Also experience cannot be less than 0 . That's why I wanted to check these invalid values.By means of that , there is no need to >0 situations in if else conditions.*/
        if(age ==0){
            printf("you entered an invalid age. Please enter your age again.\n");
            scanf("%d",&age);
        }
        if(experience==0){
            printf("you entered an invalid years of experince. Please enter experience  again.\n");
            scanf("%d",&experience);
        }
        if(experience >=age){ /*Experience cannot be greater than age.It is also invalid input.Thus, I check it again.*/
            printf("experience cannot be greater or equal to age . Please enter them again.!\n");
            scanf("%d",&age);
            scanf("%d",&experience);
        }
    }
    
    if(experience <=10){
        if(age <20){
            printf("Your salary is =%d\n",10000);
        }
        else if (age>=20 && age <=50) {
            printf("Your salary is= %d\n",15000);
            
        }
        else { /*It means if age > 50*/
            printf("Your salary is =%d",20000);
        }
    }
    else if(experience>10) {
        if(age <20){
            printf("ERROR!");
        }
        else if (age>=20 && age <=50) {
            printf("Your salary is= %d\n",20000);
            
        }
        else { /*It means if age > 50*/
            printf("Your salary is =%d",25000);
        }

    }
    return 0;
}
