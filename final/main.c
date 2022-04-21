#include "insertion.c"

void display(struct node *first)
{
    while(first != NULL)
    {
        printf("\n%s\t%s\n", first->fname, first->phoneNumber);
        first = first -> next;
    }
}
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
        if (strncmp(first->fname, x,strlen(x)) == 0)
        {
            mybool = true;
            printf("%s:%s\n",first->fname,first->phoneNumber);
        }
        else
        {
            mybool = false;
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
    char number[15];
    char fname[40];
    char lname[20];
    struct node *first;

    first = (struct node *)malloc(sizeof(struct node));
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
            printf("\nenter last name:\n");
            scanf("%s", lname);
            printf("\nenter number:\n");
            scanf("%s", number);
            strcat(fname, " ");
            strcat(fname,lname);
            first = insAtEnd(fname, number, first);
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
            break;
        default:
            printf("\ninvalid option\n");
            break;
        }
    }
}