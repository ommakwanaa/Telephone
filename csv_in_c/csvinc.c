#include <stdio.h>
#include <string.h>
char *name_var;
char *num_var;
struct node
{
	char phoneNumber[15];
	char fname[20];
	struct node *next;
};

void display(struct node *first)
{
    while(first != NULL)
    {
        printf("\n\n%s\t%s\n\n",first->fname,first->phoneNumber);
        first = first -> next;
    }
}
// insertion code end_of_ll
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

// insertion code end_of_ll

int main()
{
	FILE *fp = fopen("100-contacts.csv", "a+");
	struct node *first = (struct node*)malloc(sizeof(struct node));
	if (!fp)
		printf("Can't open file\n");
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
			
			insAtEnd(name_var,num_var,first);
			// printf("name = %s",name_var);
			// printf("\n");
			// printf("number = %s",num_var);
			// printf("\n");
		}
	}
	// char *num1 = "nirmal";
	// char *num2 = "89988775625";
	// fprintf(fp, "%s,%s", num1, num2);
	display(first);
	close(fp);
	return 0;
}
