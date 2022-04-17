#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    long unsigned int phoneNumber;
    char name[20];
    struct node *next;
};

struct node *insAtBeg(char *x, long unsigned int number, struct node *first)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
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
        return new;
    }
}
struct node* insOrd(char *x, long unsigned int number, struct node *first){    //inserts in ordered linked list in ordered manner
	
    struct node *new;
	new = (struct node*)malloc(sizeof(struct node));
	
    struct node *save;
	save = first;
	
	if(save == NULL){
		printf("empty\n");
		return new;
	}
	
    for (int i = 0; i < 20; i++)
        new->name[i] = x[i];
    new->phoneNumber = number;
	
	if(new->name[0] <= first->name[0]){
		new->next=first;
		return new;
	}
	
	while(save->next != NULL && new->name[0] >= save->next->name[0]){
		save=save->next;
	}
	
	new->next =save->next;
	save->next=new;
	return first;
}

void display(struct node *first){
    while(first != NULL){
        printf("\n\n%s\t%ld\n\n",first->name,first->phoneNumber);
        first = first -> next;
    }
}
int search(char *x, struct node *first)
{
    bool mybool;
    while (first != NULL)
    {
        printf("\n\n%s\t%ld\n\n",first->name,first->phoneNumber);
        if (strcmp(first->name, x) == 0)
        {
            mybool = true;
            printf("here\n");
            break;
        }
        else
        {
            mybool = false;
            printf("why here\n");
        }
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
                // first = insAtBeg(name, number, first);
            first = insOrd(name,number,first);

            break;
        case 2:
            printf("search");
            printf("\nwhom do you want to search:");
            scanf("%s", name);
            printf("%d", search(name, first));
            break;
        case 3:
            printf("\n\nreading\n\n");
            display(first);
            break;
        case 4:
            printf("sort");
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
    // first=insAtBeg(strcpy(first->name,"nirmal"),9927,first);
    // second=insAtBeg(strcpy(first->name,"axyhzbc"),99127,first);
    // third=insAtBeg(strcpy(first->name,"nirmal"),991127,first);
    // printf("%d",search("nirmal",first));
    // return 0;
    // // first->phoneNumber = 90;
    // strcpy(second->name, "abd");
    // second->phoneNumber = 90;
    // strcpy(third->name, "xyz");
    // third->phoneNumber = 90;