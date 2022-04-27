#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>
char*name_var;
char *num_var;
struct node
{
    char phoneNumber[15];
    char fname[40];
    struct node *next;
};

void display(struct node *first)
{
    while(first != NULL)
    {
        printf("\n%s\t%s\n", first->fname, first->phoneNumber);
        first = first -> next;
    }
}

struct node *insAtEnd(char *fn, char *phnum, struct node *first)
{ // insert at ending of linked list
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));

	// storing data in new node
	strcpy(new->fname, fn);
	strcpy(new->phoneNumber, phnum);
	new->next = NULL;

	// copy of first pointer
	struct node *save;
	save = first;

	// if not empty traverse to end
	while (save->next != NULL)
	{
		save = save->next;
	}

	// save new node at end of save.
	save->next = new;
	return first;
}
void sort(struct node* first)
{
    struct node *nextnode;
	char temp_name[20];
    char temp_num[20];
	FILE *fp1 = fopen("shorted.csv", "a+");
	if (!fp1){
		printf("Can't open file\n");}
	else{

	while(first != NULL)
    {
	    nextnode = first->next;
        while(nextnode != NULL)
        {
            fflush(fp1);
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
        // shorted csv saving code 
        fseek(fp1,0,SEEK_END);
        fprintf(fp1, "%s,%s", temp_name, temp_num);
        // shorted csv saving code 
    }
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
struct Node * deleteAtIndex(char *x, struct node *first){
    printf("the char is %s \n",x);
    
    while (first != NULL)
    {
        if (strncmp(first->fname, x,strlen(x)) == 0)
        {

            printf("this should be deleted: %s:%s\n",first->fname,first->phoneNumber);
        }
        else
        {
            // printf("\nnothing to delete");
        }
        
        first = first->next;
    }

    // return first;
}
int main()
{
    int option;
    char number[15];
    char fname[40];
    char lname[40];
	struct node *first = (struct node *)malloc(sizeof(struct node));
	FILE *fp = fopen("10k.csv", "a+");
	if (!fp){
		printf("Can't open file\n");}
	else
	{
		char buffer[1024];
		int row = 0;
		int column = 0;
		while (fgets(buffer, 1024, fp))
		{
			column = 0;
			row++;
			if (row == 1)
				continue;
			char *value = strtok(buffer, ",");
			while (value)
			{
				if (column == 0)
				{
					name_var = value;
				}
				if (column == 1)
				{
					num_var = value;
				}
				value = strtok(NULL, ",");
				column++;
			}

			first = insAtEnd(name_var, num_var, first);
    		}
	}
    // first = (struct node *)malloc(sizeof(struct node));
    while (1)
    {
        fflush(fp);
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
            printf("adding");
			fseek(fp,0,SEEK_END);
			fprintf(fp, "\n%s,%s", fname, number);
            printf("added");
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
            printf("\nenter first name:\n");
            scanf("%s", fname);
            // printf("\nenter last name:\n");
            scanf("%s", lname);
            strcat(fname, " ");
            strcat(fname,lname);
            deleteAtIndex(fname,first);
            break;
        default:
            printf("\ninvalid option\n");
            break;
        }
        close(fp);
    }
}