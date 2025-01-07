

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE_ARRAY 10000
typedef struct student{
    int ID;
    int age;
    float gpa;
        }student;

int *generate_array(int size){ 
    int *array = (int *)malloc(sizeof(int)*size); /*malloc is used to allocate memory.*/
              printf("Enter the elements of the array : "); 

    for(int i = 0 ; i< size ; i++){ 
        scanf("%d",&array[i]); 
    }
    return array; /*Returning array as you want.*/
} 
int find_min(int *array,int size){ 
    int min = array[0]; 
    for(int i = 1; i< size ; i++){ 
        if(array[i] < min){ 
            min = array[i];  
        }
    }
    return min;
}
float part3(student * std){

    float average = 0;
    if(std == NULL ) std = (student *)malloc(sizeof(student)*SIZE_ARRAY); /*malloc is used to allocate memory.*/
    for(int i = 0 ; i< SIZE_ARRAY ; i++){ 
       std[i].age = rand()%20 + 18;
       std[i].ID = rand()%1000000;
       std[i].gpa = (float)(rand()%401) /100.0;
         average += std[i].gpa;
    }
    free(std); /*Don't forget to deallocate the dynamically allocated memory at the end of the function to avoid memory leaks.*/
    return average/SIZE_ARRAY; /*I divide 10000 to find the avg*/
}
float calculate_average(float avg){
   return avg = avg/SIZE_ARRAY;
}
void prin_the_average(float avg){
    printf("Average GPA OF %d X %d students  : %.5lf\n",SIZE_ARRAY,SIZE_ARRAY,avg);
}
int main(int argc, const char * argv[]) {
 srand(time(NULL)); 
    printf("----------------- WELCOME TO PART 1 ------------------\n");
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int *array = generate_array(size);
 int min = find_min(array,size);
    printf("The minimum element of the array is -> %d\n\n",min);
    int size2;
  printf("\n----------------- WELCOME TO PART 2 ------------------\n");

    printf("Enter the size of array : ");
    scanf("%d",&size2);
     int *array2 = generate_array(size2);

     int *cumulative_arr  = calloc(size2,sizeof(int)); /*calloc is used to allocate memory and initialize it to 0.*/
    cumulative_arr[0] = array2[0];

    for(int i = 1 ; i< size2 ; i++){
        cumulative_arr[i] = cumulative_arr[i-1] + array2[i];
    }
    printf("The cumulative array is : ");
    for(int i = 0 ; i< size2 ; i++){ /*Printing the cumulative array.*/
        printf("%d ",cumulative_arr[i]);
    }
    printf("\n----------------- WELCOME TO PART 3 ------------------\n\n");
  student *std = NULL;
  float avrg=0;
  for(int i = 0 ; i<SIZE_ARRAY ; i++){ /*I call the function 10000 times as you want*/
     avrg = avrg  + part3(std);
  }
  avrg = calculate_average(avrg);
  prin_the_average(avrg);
    free(array2); /*Don't forget to deallocate the dynamically allocated memory at the end of the function to avoid memory leaks.*/
    free(cumulative_arr); /*Don't forget to deallocate the dynamically allocated memory at the end of the function to avoid memory leaks.*/
    free(array); /*Don't forget to deallocate the dynamically allocated memory at the end of the function to avoid memory leaks.*/
    free(std); /*Don't forget to deallocate the dynamically allocated memory at the end of the function to avoid memory leaks.*/
    return 0;
}
