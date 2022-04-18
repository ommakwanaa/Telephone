#include "insertion.c"

void display(struct node *first)
{
    while(first != NULL)
    {
        printf("\n\n%s\t%s\t%s\n\n",first->fname,first->lname,first->phoneNumber);
        first = first -> next;
    }
}
int search(char *x, struct node *first)
{
    bool mybool;
    while (first != NULL)
    {
        // printf("\n\n%s\t%ld\n\n",first->name,first->phoneNumber);
        if (strcmp(first->fname, x) == 0)
        {
            mybool = true;
            // printf("here\n");
            break;
        }
        else
        {
            mybool = false;
            // printf("why here\n");
        }
        first = first->next;
    }

    if (mybool)
        return true;

    else
        return false;
}

// struct node* delete(char *x, struct node *first)
// {
// 	if(first == NULL)
//     {
// 		printf("Underflowed");
// 		return 0;
// 	}
	
//     struct node *save;
// 	save= first;

//     free(x);
// }


int main()
{
    int option;
    char number[15];
    char fname[20];
    char lname[20];
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
            printf("\n\ninsertion\n\n");
            printf("\n\nenter first name:\n\n");
            scanf("%s", fname);
            printf("\n\nenter last  name:\n\n");
            scanf("%s", lname);
            printf("\nenter number:\n\n");
            scanf("%s", number);
                // first = insAtBeg(name, number, first);
            first = insAtEnd(fname, lname, number,first);

            break;
        case 2:
            printf("\n\nsearch\n\n");
            printf("\n\nwhom do you want to search:\n\n");
            scanf("%s", fname);
            printf("%d", search(fname, first));
            break;
        case 3:
            printf("\n\nreading\n\n");
            display(first);
            break;
        case 4:
            printf("\n\nsort\n\n");
            break;
        case 5:
            printf("\n\ndelete\n\n");
            printf("\n\nwhom do you want to delete:\n\n");
            scanf("%s", fname);
            // delete(name,first);
            break;
        default:
            printf("\n\ninvalid option\n\n");
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


// struct node *insAtBeg(char *x, unsigned long int number, struct node *first)
// {
//     struct node *new;
//     new = (struct node *)malloc(sizeof(struct node));
//     if (new == NULL)
//     {
//         printf("Overflowed\n");
//         return first;
//     }
//     else
//     {
//         for (int i = 0; i < 20; i++){
//             new->fname[i] = x[i];}
//         new->phoneNumber = number;
//         new->next = first;
//         return new;
//     }
// }
// struct node* insOrd(char *x, unsigned long int number, struct node *first)
// {    //inserts in ordered linked list in ordered manner
	
//     struct node *new;
// 	new = (struct node*)malloc(sizeof(struct node));
	
//     struct node *save;
// 	save = first;
	
// 	if(save == NULL)
//     {
// 		printf("empty\n");
// 		return new;
// 	}
	
//     for (int i = 0; i < 20; i++){
//         new->name[i] = x[i];}
//     new->phoneNumber = number;
	
// 	if(strcmp(new->name,  first->name) < 0 )
//     {
// 		new->next=first;
// 		return new;
// 	}
	
// 	while(save->next != NULL && strcmp(new->name, save->next->name) > 0)
//     {
// 		save=save->next;
// 	}
	
// 	new->next =save->next;
// 	save->next=new;
// 	return first;
// }
    // third->phoneNumber = 90;