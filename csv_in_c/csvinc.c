#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *name_var;
char *num_var;
char commma = ',';

struct node
{
	char phoneNumber[15];
	char fname[20];
	struct node *next;
};

void display(struct node *first)
{
	// FILE *fp1 = fopen("contacts.csv", "w");
	while (first != NULL)
	{
		
		// fprintf(fp1, "%s, %s\n","om", "makwana");
		printf("\n%s\t%s\n", first->fname, first->phoneNumber);
		first = first->next;
	}
	// close(fp1);
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
	char num1[20];
	char num2[20];
	int csv_option;
	struct node *first = (struct node *)malloc(sizeof(struct node));
	FILE *fp = fopen("100-contacts.csv", "a+");
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

			first = insAtEnd(name_var, num_var, first);
		}
	}
	while (1)
	{

		fflush(fp);
		printf(" 1 for display csv 2 for inserting data");
		scanf("%d", &csv_option);
		switch (csv_option)
		{
		case 1:
			display(first);

			break;
		case 2:

			printf("enter the name:=");
			scanf("%s", num1);
			printf("enter the number:=");
			scanf("%s", num2);
			fseek(fp,0,SEEK_END);
			fprintf(fp, "\n%s,%s", num1, num2);
			first = insAtEnd(num1, num2, first);
			// fclose(fp);
			break;

		default:
			break;
		}
		close(fp);
	}

	return 0;
}
			// gets(num1);
			// fprintf(fp, "%s",num1);
			// gets(num2);
			// fprintf(fp,"%s\n",num2);
			// fprintf(fp, "%s,%s\n", "wy this", "choking\n");
			// fputs(num1,fp);
			// fputs(commma,fp);
			// fputs(num2,fp);