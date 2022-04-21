#include "insertion.c"

void display(struct node *first)
{
    while(first != NULL)
    {
        printf("\n%s\t%s\t%s\n",first->fname,first->lname,first->phoneNumber);
        first = first -> next;
    }
}
//under development
void sort(struct node* first)
{
    struct node *nextnode;
	char temp_name[20];
    char temp_num[20];

	while(first != NULL)
    {
	    nextnode = first->next;
        while(nextnode != NULL)
        {
            if(strcmp(first->fname,nextnode->fname) > 0)
            {
                strcpy(temp_name, first->fname);
                strcpy(temp_num, first->phoneNumber);

                strcpy(first->fname, nextnode->fname);
                strcpy(first->phoneNumber, nextnode->phoneNumber);

                strcpy(nextnode->fname, temp_name);
                strcpy(nextnode->phoneNumber, temp_num);

            }
            nextnode = nextnode->next;
        }
        first = first->next;
    }
}

int search(char *x, struct node *first)
{
    bool mybool;
    while (first != NULL)
    {
        // printf("\n%s\t%ld\n",first->name,first->phoneNumber);
        if (strncmp(first->fname, x,strlen(x)) == 0)
        {
            mybool = true;
            printf("%s:%s\n",first->fname,first->phoneNumber);
            // printf("here");
            // break;
        }
        else
        {
            mybool = false;
            // printf("why here");
        }
        first = first->next;
    }
    if (mybool)
        return true;
    else
        return false;
}
//under development
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
            printf("\ninsertion\n");
            printf("\nenter first name:\n");
            scanf("%s", fname);
            printf("\nenter number:\n");
            scanf("%s", number);
            first = insAtEnd(fname, number,first);
            break;
        case 2:
            printf("\nsearch\n");
            printf("\nwhom do you want to search:\n");
            scanf("%s", fname);
            printf("%d", search(fname, first));
            break;
        case 3:
            printf("\nreading\n");
            display(first);
            break;
        case 4:
            printf("\nsort\n");
            printf("\n---------------------working on it------------------------\n");
            sort(first);
            break;
        case 5:
            printf("\ndelete\n");
            printf("\n---------------------working on it------------------------\n");
            printf("\nwhom do you want to delete:\n");
            scanf("%s", fname);
            // delete(name,first);
            break;
        default:
            printf("\ninvalid option\n");
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
//         printf("Overflowed");
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
// 		printf("empty");
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