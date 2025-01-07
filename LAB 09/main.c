#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define MAX_WORD_SIZE 15

typedef struct s_furniture{
    char f_name[MAX_WORD_SIZE+1];
    char f_color[MAX_WORD_SIZE+1];
    int f_price;
    char f_serial[7];
    int f_quant;
} t_furniture;

int count_lines()
{
    FILE * furn = fopen("furniture_database.txt", "r+");
    char my_char;
    int line_c = 0;

    my_char = fgetc(furn);
    while (my_char != EOF)
    {
        if (my_char == '\n')
            line_c++;
        my_char = fgetc(furn);
    }
    fclose(furn);
    return line_c;
}

void    print_database(t_furniture my_furniture[100], int line_c)
{
    printf("\nCurrent Database Information: \n");
    for (int i = 0; i < line_c; i++)
    {
        printf("%s, %s, %d, %s, %d\n", my_furniture[i].f_name,
                                                my_furniture[i].f_color,
                                                my_furniture[i].f_price,
                                                my_furniture[i].f_serial,
                                                my_furniture[i].f_quant);
    }
}

void    add_new_furniture(t_furniture my_furniture[100])
{
    FILE *furnit;

    char temp_f_name[MAX_WORD_SIZE+1];
    char temp_f_color[MAX_WORD_SIZE+1];
    int temp_f_price;
    char temp_f_serial[7];
    int temp_f_quant;

    printf("Please input a new furniture space seperated(name, color, price, serial, quantity\n--> )");
    scanf("%s %s %d %s %d", temp_f_name, temp_f_color, &temp_f_price, temp_f_serial, &temp_f_quant);

    furnit = fopen("furniture_database.txt", "a");
    
    fprintf(furnit,"%s, %s, %d, %s, %d\n", temp_f_name,
                                                temp_f_color,
                                                temp_f_price,
                                                temp_f_serial,
                                                temp_f_quant);

    fclose(furnit);
}

void    remove_furniture(t_furniture my_furniture[100], int line_c)
{
    FILE *furn;
    int idx;

    printf("Please enter the index of the furniture you want to delete: ");
    scanf("%d", &idx);

    furn = fopen("furniture_database.txt", "w");
    for (int i = 0; i < line_c; i++)
    {
        if (i != idx)
        {
            fprintf(furn,"%s, %s, %d, %s, %d\n", my_furniture[i].f_name,
                                                my_furniture[i].f_color,
                                                my_furniture[i].f_price,
                                                my_furniture[i].f_serial,
                                                my_furniture[i].f_quant);
        }
    }
    fclose(furn);
}

void update_database(t_furniture my_furniture[100])
{
    FILE *furnit;
    
    int line_c = count_lines();
    furnit = fopen("furniture_database.txt", "r+");

    for (int i = 0; i < line_c; i++)
    {
        fscanf(furnit, "%[^,], %[^,], %d, %[^,], %d\n", my_furniture[i].f_name,
                                                my_furniture[i].f_color,
                                                &my_furniture[i].f_price,
                                                my_furniture[i].f_serial,
                                                &my_furniture[i].f_quant);
    }
    fclose(furnit);
}

void    search_recursion_name(t_furniture my_furniture[100], char search_name[15],int line_c, int idx){
    if (idx == line_c)
    {
        return ;
    }
    if (strcmp(my_furniture[idx].f_name, search_name) == 0)
    {
        printf("%s, %s, %d, %s, %d\n", my_furniture[idx].f_name,
                                                my_furniture[idx].f_color,
                                                my_furniture[idx].f_price,
                                                my_furniture[idx].f_serial,
                                                my_furniture[idx].f_quant);
    }
    search_recursion_name(my_furniture, search_name, line_c, idx+1);
}

void    search_recursion_color(t_furniture my_furniture[100], char search_name[15],int line_c, int idx){
    if (idx == line_c)
    {
        return ;
    }
    if (strcmp(my_furniture[idx].f_color, search_name) == 0)
    {
        printf("%s, %s, %d, %s, %d\n", my_furniture[idx].f_name,
                                                my_furniture[idx].f_color,
                                                my_furniture[idx].f_price,
                                                my_furniture[idx].f_serial,
                                                my_furniture[idx].f_quant);
    }
    search_recursion_name(my_furniture, search_name, line_c, idx+1);
}

int main(void)
{   char str[15];
    int n = 0;
    int chc =0;
    t_furniture my_furniture[100];

    update_database(my_furniture);

    while (n < 5)
    {
        printf("\n1) See all furnitures\n");
        printf("2) Add a new furniture\n");
        printf("3) Remove furniture\n");
        printf("4) Search furniture\n");
        printf("5) Exit\n");
        printf("Choose an operation: ");
        scanf("%d", &n);
        
        int line_c = count_lines();
        switch(n)// i used switch case to make a menu
        {
            case 1:
                print_database(my_furniture, line_c);
                break;
            case 2:
                add_new_furniture(my_furniture);
                update_database(my_furniture);
                break;
            case 3:
                remove_furniture(my_furniture, line_c);
                update_database(my_furniture);
                break;
            case 4:
            
           
                printf("1-) Search by Name\n");
                printf("2-) Search by Color\n");
                scanf("%d", &chc);
                if (chc == 1)
                {
                    printf("Please enter the name you want to search\n");
                    scanf("%s", str);
                    search_recursion_name(my_furniture, str, line_c, 0);
                }
                else if (chc == 2)
                {
                    printf("Please enter the color you want to search\n");
                    scanf("%s", str);
                    search_recursion_color(my_furniture, str, line_c, 0);
                }
                break;
        }
    }

}
