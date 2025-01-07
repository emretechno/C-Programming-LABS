#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEVEL 4

typedef struct Customer{
    char name[20];
    int age;
    char priority_group[20];
    int priority_level;
     struct Customer *next;
    struct Customer *prev;
}customer;

customer *insert_customer_sorted(customer *head , char name[20] , int age , char priority_group[20] , int priority_level){
    customer *new_customer = (customer *)malloc(sizeof(customer));
    strcpy(new_customer->name , name);
    new_customer->age = age;
    strcpy(new_customer->priority_group , priority_group);
    new_customer->priority_level = priority_level;
    new_customer->next = NULL;
    new_customer->prev = NULL;
    if(head == NULL){
        head = new_customer;
        return head;
    }
    customer *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_customer;
    new_customer->prev = temp;
    return head;
}
customer *remove_customer(customer *head, char name[20]){
if(head == NULL ){
    printf("No customers to remove");
    return head;
}
customer *temp = head;
printf("\n");
while(temp != NULL){
    if(strcmp(temp->name , name) == 0){
        if(temp->prev == NULL){
            head = temp->next;
            head->prev = NULL;
            free(temp);
            return head;
        }
        else if(temp->next == NULL){
            temp->prev->next = NULL;
            free(temp);
            return head;
        }
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            return head;
        }
    }
    temp = temp->next;

}
if(temp == NULL) printf("Customer not found") ;
return head;

}

void display_customers_inpriority_order(customer *head){
    if(head == NULL )printf("No customers to display");
    for(int j = MAX_LEVEL ; j>=1 ; j--){
    customer *temp = head;
    while(temp != NULL){
        if(temp->priority_level == j){
            printf("Name : %s\n" , temp->name);
            printf("Age : %d\n" , temp->age);
            printf("Priority Group : %s\n" , temp->priority_group);
            printf("Priority Level : %d\n" , temp->priority_level);
            printf("\n");
        }
        temp = temp->next;

    }
    }



}
customer *change_priority(customer *head , char name[20] ,int priority_level){
 if(head == NULL ) printf("No customers to change priority");
    customer *temp = head;
    while(temp != NULL){
        if(strcmp(temp->name , name) == 0){
            temp->priority_level = priority_level;
            return head;
        }
        temp = temp->next;
    }
    if(temp == NULL) printf("Customer not found");
    return head;
}


customer *search_customers_recursively(customer *head , char name[20]){
    if(head == NULL ){
        printf("Customer was not found :( !");
        return NULL;
    }
    if(strcmp(head->name , name) == 0) {
        printf("Customer found !!");
        printf("Name : %s\n" , head->name);
        printf("Age : %d\n" , head->age);
        printf("Priority Group : %s\n" , head->priority_group);
        printf("Priority Level : %d\n" , head->priority_level);
        printf("\n");

        return head;
    }
    return search_customers_recursively(head->next , name);
}

int main(){
    customer *head = NULL;
    FILE *fp= fopen("customers.txt" , "r+");
    if(fp == NULL){
        printf("File not found");
        return 0;
    }
    char name[20];
    int age;
    char priority_group[20];
    int priority_level;
    while(!feof(fp)){
        fscanf(fp , "%s %d %s %d\n" , name , &age , priority_group , &priority_level);
        head = insert_customer_sorted(head,name , age , priority_group , priority_level);
    }
    fclose(fp);
    int option;
    printf("Welcome to ABC BANK\n");
    int flag = 1;
    do{
           

    printf("Please enter an option: \n");
     printf("1- > Insert a customer\n");
     printf("2- > Remove a customer\n");
     printf("3- > Display all customers in order\n");
     printf("4- > Search a customer\n");
     printf("5- > Change priority settings\n");
     printf("6- > Exit\n");
     scanf("%d" , &option);
     switch(option){
        case 1 : printf("\nPlease enter the name of the customer : ");
                 char name[20];
                 scanf("%s" , name);
                 printf("Please enter the age of the customer : ");
                 int age;
                 scanf("%d" , &age);
                 printf("Please enter the priority group of the customer : ");
                 char priority_group[20];
                 scanf("%s" , priority_group);
                 printf("Please enter the priority level of the customer : ");
                 int priority_level;
                 scanf("%d" , &priority_level);
                 fp = fopen("customers.txt" , "w");
                 head = insert_customer_sorted(head , name , age , priority_group , priority_level);
                 FILE *fp4 = fopen("customers2.txt", "w");
                    for(int j = MAX_LEVEL ; j>=1 ; j--){
    customer *temp = head;
    while(temp != NULL){
        if(temp->priority_level == j){
            fprintf(fp4 , "%s %d %s %d\n" , temp->name , temp->age , temp->priority_group , temp->priority_level);
        }
        temp = temp->next;

    }
    }
                  fclose(fp4);
                    remove("customers.txt");
            rename("customers2.txt" , "customers.txt");
                 fclose(fp);
                 break;
    case 2 : printf("Please enter the name you want to remove  : ");
             char name2[20];
                scanf("%s" , name2);
                head = remove_customer(head , name2);
                  customer *temp3 = head;
                    FILE *fp2 = fopen("customers2.txt", "a");
      for(int j = MAX_LEVEL ; j>=1 ; j--){
    customer *temp = head;
    while(temp != NULL){
        if(temp->priority_level == j){
          
         fprintf(fp2 , "%s %d %s %d\n" , temp->name , temp->age , temp->priority_group , temp->priority_level);
        }
        temp = temp->next;

    }
    }
        fclose(fp2);

    remove("customers.txt");
            rename("customers2.txt" , "customers.txt");
                break;

    case 3: display_customers_inpriority_order(head); break;
     case 4: printf("Please enter the name you want to search : ");
                  char name3[20];
                  scanf("%s" , name3);
                 customer * temp = search_customers_recursively(head , name3);
                 
                  break;
  
    case 5 : printf("Please enter the name you want to change the priority : ");
       char name4[20];
       scanf("%s" , name4);
       printf("Please enter the new priority level : ");
         int priority_level2;
            scanf("%d" , &priority_level2);
            head  = change_priority(head , name4 , priority_level2);
            customer *temp2 = head;
            FILE *fp3 = fopen("customers2.txt", "w");
    while(temp2 != NULL){
          fprintf(fp3 , "%s %d %s %d\n" , temp2->name , temp2->age , temp2->priority_group , temp2->priority_level);
        temp2 = temp2->next;
    }
        fclose(fp3);
        remove("customers.txt");
            rename("customers2.txt" , "customers.txt");
        break;
     case 6 : flag = 0;
     break;


     }
    } while(flag);
    return 0;
}