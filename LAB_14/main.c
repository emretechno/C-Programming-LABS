#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcpy was obligation for this lab
#include <time.h> 

typedef struct node {
    int data;
    struct node *next;
} node;
typedef struct order {
    char customer_name[50];
    int order_number;
    char items[50];
    time_t time[50];
    struct order *next;

} order;

void find_last_Id(order *head, int *orderID){
    order *temp = head;
    if(temp == NULL){
        printf("Queue is empty.Nothing can be displayed!\n");
        return;
    }
    while(temp != NULL){
        if(temp->order_number > *orderID){
            *orderID = temp->order_number + 1;
        }
        temp = temp->next;
    }
    return;
}

order *enqueue(order  *  queue,  char  *  customerName,  int  orderID, char  *  items,  char  * orderTime){ //FIFO
order *new_node  = queue;
if(new_node == NULL){
    order *temp = (order *)malloc(sizeof(order));
    strcpy(temp->customer_name, customerName);
    temp->order_number = orderID;
    strcpy(temp->items, items);
    temp->next = queue;
    queue = temp;
    printf("Name %s Order ID : %d Items : %s Time : %s \n", temp->customer_name, temp->order_number, temp->items, ctime(&temp->time));
    return queue;
   
}

while(new_node->next != NULL){
    new_node = new_node->next;
}
order *temp = (order *)malloc(sizeof(order));
strcpy(temp->customer_name, customerName);
temp->order_number = orderID;
strcpy(temp->items, items);
new_node->next = temp;
temp->next = NULL;
printf("Name %s Order ID : %d Items : %s Time : %s \n", temp->customer_name, temp->order_number, temp->items, ctime(&temp->time));
return queue;
}

order *LIFO(order *queue, char *customerName, int orderID, char *items, char *orderTime){
    order *temp = (order *)malloc(sizeof(order));
    strcpy(temp->customer_name, customerName);
    temp->order_number = orderID;
    strcpy(temp->items, items);
    temp->next = queue;
    queue = temp;
    printf("Name %s Order ID : %d Items : %s Time : %s \n", temp->customer_name, temp->order_number, temp->items, ctime(&temp->time));
    return queue;
}

    
order *deque(order *queue){
    order *temp = queue;
    if(temp == NULL){
        printf("Queue is empty.Nothing can be deleted!\n");
        return queue;
    }
   if(temp->next == NULL){ 
   
       queue = NULL;
       free(temp);
       return queue;
   }
   else{

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
  
    while(temp != NULL){
        printf("Order Number : %d     \nCustomer Name : %s  \nItems : %s \nOrder Time : %s \n", temp->order_number,temp->customer_name, temp->items, ctime(&temp->time));
        temp = temp->next;
       printf("\n");

    }
    printf("\n");
}
order *binary_serialize(order *head){
    order *temp = head;
    if(temp == NULL){
        printf("Queue is empty.Nothing can be serialized!\n");
        return head;
    }
    FILE *fp;
    fp = fopen("fifo.bin", "wb");
    if(fp == NULL){
        printf("File could not be opened!\n");
        return head;
    }
    printf("The menu is serialized by binary !\n");
    while(temp != NULL){
        fwrite(temp, sizeof(order), 1, fp);
        temp = temp->next;
    }
    fclose(fp);
    return head;
}

order *de_serialize_binary(order *head,const char *filename){
    FILE *fp;
    fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("File could not be opened!\n");
        return head;
    }
    if(head == NULL ){
        printf("The linked list is empty!\n");
        return head;
    }
    order *temp = head;
    while(temp != NULL){
        fread(temp, sizeof(order), 1, fp);
        temp = temp->next;
    }
    fclose(fp);
    return head;
}
order *deserializeLIFO(order *head, const char *filename){
    FILE *fp;
    fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("File could not be opened!\n");
        return head;
    }
  
    order *read_queue = NULL;
    order *temp = head;
    while(temp != NULL){
        fread(temp, sizeof(order), 1, fp);
        read_queue = LIFO(read_queue, temp->customer_name, temp->order_number, temp->items,time(NULL));
        temp = temp->next;
    }
    fclose(fp);
    return read_queue;
}
order* deserialized_FIFO(order *head, const char *filename){
    FILE *fp;
    fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("File could not be opened!\n");
        return head;
    }
    if(head != NULL){
        printf("The linked list is not empty!\n");
        return head;
    }
    order *read_queue = NULL;
    order *temp = head;
    while(temp != NULL){
        fread(temp, sizeof(order), 1, fp);
        read_queue = enqueue(read_queue, temp->customer_name, temp->order_number, temp->items,time(NULL));
        temp = temp->next;
    }
    fclose(fp);
    return read_queue;
}

int main(){


printf("-------------------------------------------------------PART1 ! -------------------------------------------------------\n");
order *list = NULL;
printf("The menu is enqueued !\n");
int orderID = 1;
list = enqueue(list, "Ali Ahmet ",orderID, "Burger Kola ",time(NULL));
find_last_Id(list, &orderID);
list = enqueue(list, "Veli Mehmet ",++orderID, "Pizza Patates",time(NULL));
find_last_Id(list, &orderID);
list = enqueue(list, "Ayse Hatun",++orderID, "Kebap Ayran",time(NULL));
find_last_Id(list, &orderID);
list = enqueue(list, "Fatma Fatos",++orderID, "Lahmacun",time(NULL));
find_last_Id(list, &orderID);
printf("------------------------- ! SERIALIAZATION PART !-------------------------\n");
list  = binary_serialize(list);
printf("The menu is de-serialized FIFO !\n");
display_order(list);
printf("The menu is de-serializedby FIFO !\n");
list = deserialized_FIFO(list,"fifo.bin");
display_order(list);
printf("The menu is de-serialized by LIFO !\n");
list = deserializeLIFO(list,"fifo.bin");
display_order(list);
printf("AFTER DEQUEUED : \n");
list = deque(list);
list = deque(list);
display_order(list);


    return 0;
}
