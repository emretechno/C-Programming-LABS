#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcpy was obligation for this lab

typedef struct node {
    int data;
    struct node *next;
} node;
typedef struct order {
    char customer_name[50];
    int order_number;
    char items[50];
    char order_time[50];
    struct order *next;

} order;

typedef struct exampaper{
    char student_name[50];
    int student_number;
    int score;
    struct exampaper *next;
}exampaper;

exampaper *push (exampaper * stack , char *student_name , int student_number, int score){
    exampaper *new_node = (exampaper *)malloc(sizeof(exampaper));
    strcpy(new_node->student_name, student_name);
    new_node->student_number = student_number;
   new_node->score = score;
    new_node->next = stack;
    stack = new_node;
    printf("Pushed\n");
    return stack;
}
exampaper *pop(exampaper *stack){
    exampaper *temp = stack;
    if(temp == NULL){
        printf("Stack is empty.Nothing can be deleted!\n");
        return stack;
    }
    stack = temp->next;
    free(temp);
    printf("Popped\n");
    return stack;
}
int is_Empty(exampaper *head){
    if(head == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void display(exampaper *head){
    exampaper *temp = head;
    while(temp != NULL){
        printf("Student Name : %s  \nStudent Number : %d    \nScore : %d \n", temp->student_name, temp->student_number, temp->score);
        printf("\n\n");
        temp = temp->next;
    }
}

order *enqueue(order  *  queue,  char  *  customerName,  int  orderID, char  *  items,  char  * orderTime){
order *new_node  = queue;
if(new_node == NULL){
    order *temp = (order *)malloc(sizeof(order));
    strcpy(temp->customer_name, customerName);
    temp->order_number = orderID;
    strcpy(temp->items, items);
    strcpy(temp->order_time, orderTime);
    temp->next = queue;
    queue = temp;
    printf("Enqueued \n");
    return queue;
   
}
while(new_node->next != NULL){
    new_node = new_node->next;
}
order *temp = (order *)malloc(sizeof(order));
strcpy(temp->customer_name, customerName);
temp->order_number = orderID;
strcpy(temp->items, items);
strcpy(temp->order_time, orderTime);
new_node->next = temp;
temp->next = NULL;

return queue;
}
order *deque(order *queue){
    order *temp = queue;
    if(temp == NULL){
        printf("Queue is empty.Nothing can be deleted!\n");
        return queue;
    }
   if(temp->next == NULL){
    printf("Dequed");
       queue = NULL;
       free(temp);
       return queue;
   }
   else{
    printf("Dequed");
       queue = temp->next;
       free(temp);
       return queue;
   }
}
order *update(order *queue , int orderid , char *newitems){
    order *temp = queue;
    if(temp == NULL){
        printf("Queue is empty.Nothing can be updated!\n");
        return queue;
    }
    while(temp != NULL && temp->order_number != orderid){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("The order id(%d)  was not found in linked list!!\n",orderid);
        return queue;
    }
    else{
        printf("Updated");
        strcpy(temp->items, newitems);
        return queue;
    }
}
void display_order(order *head){
    order *temp = head;
    if(temp == NULL){
        printf("Queue is empty.Nothing can be displayed!\n");
        return;
    }
    printf("The display by OrderID the queue is as follows:\n\n");
    while(temp != NULL){
        printf("Customer Name : %s  \nOrder Number : %d    \nItems : %s \nOrder Time : %s \n", temp->customer_name, temp->order_number, temp->items, temp->order_time);
        temp = temp->next;
       printf("\n");

    }
    printf("\n");
   
}

int main(){


printf("-------------------------------------------------------PART1 ! -------------------------------------------------------\n");
    order *list = NULL;
    printf("The menu is enqueued !\n");
   list = enqueue(list, "Ali Ahmet ", 1, "Burger Kola ", "12:00");
   list = enqueue(list, "Veli Mehmet ", 2, "Pizza Patates", "12:30");
    list = enqueue(list, "Ayse Hatun", 3, "Kebap Ayran", "13:00");
    list = enqueue(list, "Fatma Fatos", 4, "Lahmacun", "13:30");
     display_order(list);
    list = deque(list);
    list = deque(list);
     printf("Dequed the  last order!\n");
    display_order(list);
        list = update(list,4, "Hamburger Kola");
        display_order(list);

    printf("-------------------------------------------------------PART2 ! -------------------------------------------------------\n");
   exampaper *stack = NULL;
  
    stack = push(stack, "Ali Ahmet", 1, 100);
    stack = push(stack, "Veli Mehmet", 2, 90);
    stack = push(stack, "Ayse Hatun", 3, 80);
    stack = push(stack, "Fatma Fatos", 4, 70);
    printf("The pushed stack : ");
    display(stack);
    stack = pop(stack);
    stack = pop(stack);
   printf("The popped stack : \n");
    display(stack);


    return 0;
}
