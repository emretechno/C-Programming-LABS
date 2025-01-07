
#include <stdio.h>
#include <string.h>
#include <limits.h>

int part1(char [] );
void part2();
int check(char[],char[],int,int);
int part3();
void get_array(int [], int);
void foo_min_max(int [] , int );
int main(int argc, const char * argv[]) {
     printf("Please enter the string.\n");
    char str[50]; // to read the string with spaces
    scanf("%s",str); // to read the rule
    part1(str);
   part2();
   
  part3();
    return 0;
}


int  part1( char str[]){
    
    
    int i=0;
    int j=0;
    int result = 99999; // to find the min number of operation later initializing it with a big number
    for (int k=0 ; 26>k ; k++) // to check all the 26 letters
    { 
        int temp = 0; // to count the number of operation
        int i=0;
        int j=0; 
        while (str[j] != '\0' && str[i] != '\0') /*Not working */
        {
            while (str[j] == str[i] && str[j] != '\0') 
            {
                j++;
            }
            if (str[i] != k+'a') // if the letter is not the same as the letter we are checking
            {
                temp++; // we need to change it
            }
            i = j;
        }
        
        if (temp+1 < result) // to find the min number of operation
        {
            result = temp+1; // to find the min number of operation
        }
    }
    printf("min number of operation is: %d\n",result); // printing the result
return 0; 
}

void part2(){
    char str[50];
    char rule[20];
    printf("Please enter the string and the rule respectively.\n");

    scanf(" %[^\n]s", str); // to read the string with spaces
    printf("Enter a rule: ");  
    scanf("%s", rule); // to read the rule

    printf("Filtered text:\n");
    int i=0;
    while (str[i] != '\0')
    {
        while (str[i] == ' ') i++;
        char newstr[50];
        
        int j=i;
        int k=0;
        while (str[j] != ' ' && str[j] != '\0')
        {
            newstr[k] = str[j];
            k++;
            j++;
        }
        
        newstr[k] = '\0';
        
        
        i = j;
        
        if (check(newstr,rule,0,0) == 0)
        {
            printf("%s ",newstr);
        }
        
    }
    printf("\n");

}

int check(char arr[],char rule[],int i,int j)
{
    if (rule[j] == '\0') return 1; // if the rule is finished
    if (arr[i] == '\0') return 0; // if the string is finished
    if (arr[i] == rule[j]) // if the letters are the same
    {
        return (check(arr,rule,i+1,j) || check(arr,rule,i+1,j+1));
    }
    else if(rule[j] == '?')
    {
        return check(arr,rule,i+1,j+1); // if the rule is ?
    }
    else if(rule[j] == '*') // if the rule is *
    {
        return (check(arr,rule,i+1,j) || check(arr,rule,i+1,j+1)); // we can skip the letter or we can use it
    } 
    else return check(arr,rule,i+1,j); // if the letters are not the same
}

int part3(){
     int size;   
    printf("Enter size: ");     
    scanf("%d", &size); 

  int ar[100]; 
    get_array(ar, size); 
    foo_min_max(ar, size); 
    return 0;
}

void get_array(int ar[], int size){
    int i =0;
    while(i < size){ /*while loop instead of for.*/
        printf("Enter number: %d\n", i+1);
        scanf("%d", &ar[i]);
        i++;
    }
}
void foo_min_max(int ar [] ,int size ){
    int min = ar[0]; 
    int max = ar[0];
   int i=0;
   while( i < size){ /*while loop instead of for.*/
       if(ar[i] < min){
           min = ar[i];
       }
       if(ar[i] > max){
           max = ar[i];
       }
       i++;
   }
       
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
}