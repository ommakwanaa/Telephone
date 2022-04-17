#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int inscheck = 0;
struct node
{
    long phoneNumber;
    char name[20];
    struct node *next;
};

struct node *insAtBeg(char x[20], int number, struct node *first)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    // printf("\n\n%s\t%ld\n\n",x,number);
    if (new == NULL)
    {
        printf("Overflowed\n");
        return first;
    }
    else
    {
        for (int i = 0; i < 20; i++)
            new->name[i] = x[i];
        new->phoneNumber = number;
        new->next = first;
        inscheck++;
        return new;
    }
}

bool search(char x[20], struct node *first)
{
    bool mybool;
    while (first != NULL)
    {
        printf("\n\n%s\t%ld\n\n",first->name,first->phoneNumber);

        // if (first->name == x)
        // {
        //     mybool = true;
        //     printf("here\n");
        //     break;
        // }
        // else
        // {
        //     mybool = false;

        //     printf("why here\n");
        // }
        first = first->next;
    }

    if (mybool)
        return true;

    else
        return false;
}

int main()
{
    int option;
    int number;
    char name[20];
    struct node *first,*second,*third, *check;

    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    strcpy(first->name,"nirmal");
    first->phoneNumber = 90;
    strcpy(second->name, "abd");
    second->phoneNumber = 90;
    strcpy(third->name, "xyz");
    third->phoneNumber = 90;
    while (1)
    {
        printf("\nEnter :\n1 to insert\n2 to search\n3 to read\n4 to sort\n5 to delete\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("insertion\n");
            printf("\nenter name:");
            scanf("%s", name);
            printf("\nenter number:");
            scanf("%d", &number);
            if (inscheck == 0)
                insAtBeg(name, number, first);
            // else

            break;
        case 2:
            printf("search");
            printf("\nwhom do you want to search:");
            scanf("%s", name);
            printf("%d", search(name, first));
            break;
        case 3:
            printf("read");
            break;
        case 4:
            printf("short");
            break;
        case 5:
            printf("delete");
            break;
        default:
            printf("invalid option");
            break;
        }
    }
}