
#include <stdio.h>

double roll_exam(double );
void get_letter(int);
int calculate(char , int ,int);
int main(int argc, const char * argv[]) {
    
    
    printf("----------PART1-------------\n");
    
    int n1,n2,n3; /*number 1 ,number 2 , number 3.*/
    printf("Please enter three integers.\n");
    scanf("%d %d %d",&n1,&n2,&n3);
    int median =n1; /*Firstly I assign median n1.If following if conditions are not true , I understand that our median is n1.*/
    
    if(n2>=n1){ /*If n1<=n2<=n3 , median is n2*/
        if(n2<=n3){
            median = n2;
        }
    }
    
    if(n2<=n1){ /*If n3<=n2<=n1 , median is n2*/
        if(n2>=n3){
            median=n2;
        }
    }
    
    if(n3>=n1){ /*If n1<=n3<=n2 , median is n3*/
        if(n3<=n2){
            median = n3;
        }
    }
    
    if(n3<=n1){ /*If n2<=n3<=n1 , median is n3*/
        if(n3>=n2){
            median=n3;
        }
    }
    
    printf("The median is :%d\n",median);
    
    
    
    
    printf("----------PART2-------------=\n");
    double exam_1 , exam_2 , exam_3;
    printf("Enter your scores:\n");
    
    scanf("%lf %lf %lf",&exam_1,&exam_2,&exam_3);

    
    double average =( exam_3+exam_2+exam_1)/3; /*Firstly I calculate the average before I send them to roll function.*/

   
    exam_1 = roll_exam(exam_1); /*In this function , I roll the exam grades to integer of multiplies of 10.*/
    exam_2 = roll_exam(exam_2);
    exam_3 = roll_exam(exam_3);/*same process.*/
    
    /*NOTE:I DO NOT KNOW IF TYPE CASTING IS ALLOWED SO I CHOSE THAT WAY TO ROLL THE GRADES.IT MAY BE KIND OF LONG BUT IT IS THE SAFEST WAY.*/
    
    printf("Your letter grades are ");
    get_letter(exam_1); /*Then I print the letters by using swtich statement in get_letter function.*/
    printf(", ");
    get_letter(exam_2); /*Same*/
    printf("and ");
    get_letter(exam_3);/*Same*/
    /*I know that my grades were double ,but I sent them as an integer because switch case works with integers, not with doubles.*/
    if((exam_1>=0 && exam_1<=100 ) &&  (exam_2>=0 && exam_2<=100 ) && (exam_3>=0 && exam_3<=100 )){
        
        
        
        printf("with an %.2lf average\n",average);     /*I print the average.My average is still double btw, I just sent the copies of grades to the functions.*/

    }
    else {
        printf("With an not calculated average..."); /*If users invalid grades , the average will not be calculated.*/
    }
    
    
    
    
    printf("----------PART3-------------=\n");
    char operand;
    printf("Please enter the operand (+,-,*./)");
        scanf(" %c",&operand);
    
    int num1,num2,answer;
    printf("Please enter two integers\n");
    scanf("%d %d",&num1,&num2);
    printf("Result:\n");
    scanf("%d",&answer);
    int result = calculate(operand,num1,num2); /*In this part , I used switch again and find the result of operation.*/
    
    if(result==answer){ /*If user's answer is same is result , It it correct.*/
        printf("Bravo, correct answer!\n");
    }
    if(result !=answer){
        printf("Wrong answer, try again...\n"); /*Else , it i s not correct.*/
    }
    
    
    return 0;
}

double roll_exam(double exam){ /*In this function , I jusr calculate the rolled version of my exams.So that I will be able to use switch case.*/
    
    if(exam >=90 && exam <=100){
        exam =90; /*In this interval I said it is 90 but I could have told another number .It does not matter at all.*/
    }
    
    if(exam>=80 && exam <90){ /*Same process are also valid for these situations.*/
        exam=80;
    }

    if(exam>=70 && exam <80){
        exam=70;
    }
    if(exam>=60 && exam<70){
        exam=60;
    }
    if(exam>=50 && exam <60)
        exam = 50;
    

    if( exam>=40 && exam <50){
        exam = 40;
    }
    if(exam >=0 && exam <40){
        exam = 35;
    }

    return  exam;

}
void get_letter(int exam){ /*And then I printed the letters as I arranged before.I said 90 and one my case is 90 , I said 60 and one of my case is 60.*/
    
    switch(exam){
        case 90:
            printf("A+ "); /*There are given in pdf.*/
            break;
            
        case 80:
            printf("A ");
            break;
            
        case 70:
            printf("B+ ");
            break;
            
        case 60:
            printf("B ");
            break;
            
        case 50:
            printf("C ");
            break;
            
        case 40:
            printf("D ");
            break;
            
        case 35 :
            printf("F ");
            break;
            
        default:
            printf("Invalid grade! ");
            break;
            
    }
}

int calculate(char operand , int num1 , int num2){
    int result=0; /*I must initialize my number.*/
    switch(operand){ /*In this switch case , I just calculated ther results of every operand.*/
        case '+':
            result = num1+num2;
            break;
            
        case '-':
            result = num1-num2;
            break;
            
        case '*':
            result = num1 * num2;
            break;
            
        case '/':
            result = num1/num2;
            break;
            
        default:
            printf("\nError! operator is not correct\n");
    }
    
    return result; /*I return the result of my process.*/
}
