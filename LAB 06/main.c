#include <stdio.h>
#define sentinel -100
#define size 20
void part1();
void return_result(int [] , int );
void part2();
/*There was no time to add comment line.I am so sorry !*/
int main(void){

        part1();
        part2();

    
       return 0;
}
void part1(){

    int ar[size];
    int n;
    for(int i = 0 ; i<size ; i++){
        printf("Enter a number (TO EXIT , WRITE -100):");
        scanf("%d",&ar[i]);
        if( ar[i]  == sentinel){
           n =i;
            break; 
        }
    }
   
    return_result(ar,n);
}
void return_result (int ar [] , int n ){

  char odd_even[n];
  for(int i = 0 ; i< n; i++){

    if(ar[i] % 2 == 0){
        odd_even[i] =  'e';
    }

    else {
        odd_even[i] = 'o';
    }
  }

  for(int j = 0 ; j < n ; j++){
    printf("%d ",ar[j]);
    printf("%c\n",odd_even[j]);
  }
}


void part2(){
  
      FILE *fp;
      fp= fopen("table.txt","r");
           int row;
        fscanf(fp,"%d",&row);


  int total_fan =0;
  int f_arr[size];
  char f_occupation[size];
  float f_salary[size];
  char f_team[size];

      char input;
   
      printf("Please enter a team :");
      scanf(" %c",&input);
      float total_salary = 0;
      char c;

      int i = 0;

    while (i < row)
    {
        fscanf(fp, "%d %c %f %c\n", &f_arr[i], &f_occupation[i], &f_salary[i], &f_team[i]);
        i++;
    }

      for(int i = 0 ; i< row; i++){
        if(f_team[i] == input){
            total_salary = total_salary + f_salary[i];
            total_fan++;
        }
      }

    float average_salary;
    
   if( total_fan == 0){
      printf("There are no fans of %c in the database",input);
   }
    
   else {
       average_salary  = total_salary / total_fan;
       printf("Average salaries of fans of %c : %.1f ",input,average_salary);

}
fclose(fp);
}
