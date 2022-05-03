#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
char *name_var;
char *num_var;

struct node
{
    char phoneNumber[15];
    char fname[40];
    struct node *next;
};
//***********************************************************************//
/*
 * Function: insAtEnd           
 * ----------------------------
 *   Inserts the node at end of the linked list 
 *
 *   fn: Full name  
 *   phnum: mobile nmber corresponding to the name
 *   first: Head node of LinkedList
 *
 *   returns: Head Node of Linked list
 */                                                                                             
//************************************************************************//
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

//***********************************************************************//
/*
 * Function: csv_to_ll           
 * ----------------------------
 *   copies data of csv file at end of Linked List 
 *
 *   fptmp: name of the file from where to fetch data 
 *   first: Head node of LinkedList
 *
 *   returns: void 
 */                                                                                             
//************************************************************************//
void csv_to_ll(FILE *fptmp ,struct node *first){

    strcpy(first->fname,"Lisha Centini");
    strcpy(first->phoneNumber,"703-235-39\n");
    if (fptmp < 0)
    {
        printf("Can't open file\n");
    }
    else
    {
        char buffer[1024];
        int row = 0;
        int column = 0;
        while (fgets(buffer, 1024, fptmp))
        {
            column = 0;
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
            // printf("==>>%s   %s",name_var, num_var);
            first = insAtEnd(name_var, num_var, first);
            row++;
            first = first->next;
        }
    }
}
//***********************************************************************//
/*
 * Function: display           
 * ----------------------------
 *   display data of csv by traversing through linkedlist
 *
 *   first: Head node of LinkedList
 *
 *   returns: void 
 */                                                                                             
//************************************************************************//
void display(struct node *first)
{
    while (first != NULL)
    {
        printf("\n%s,%s", first->fname, first->phoneNumber);
        first = first->next;
    }
}
//***********************************************************************//
/*
 * Function: sort           
 * ----------------------------
 *   short data and store in the linkedlist
 *
 *   first: Head node of LinkedList
 *
 *   returns: void 
 */                                                                                             
//************************************************************************//
void sort(struct node *first)
{
    FILE *fp = fopen("100-contacts.csv", "a+");
    // csv_to_ll(fp,first);
    struct node *nextnode;
    struct node *saveFirst;
    char temp_name[20];
    char temp_num[20];
    saveFirst = first;
    FILE *fp1 = fopen("10_sorted.csv", "w");
    if (!fp1)
    {
        printf("Can't open file\n");

    }
    else
    { 
        while (first != NULL)
        {
            nextnode = first->next;
            while (nextnode != NULL)
            {
                if (strcmp(first->fname, nextnode->fname) > 0)
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
            // sorted csv saving code
            // sorted csv saving code
        }
    }
    while(saveFirst != NULL)
    {
        fflush(fp1);
        fseek(fp1, 0, SEEK_END);
        printf("%s,%s", saveFirst->fname, saveFirst->phoneNumber);
        fprintf(fp1, "%s,%s", saveFirst->fname, saveFirst->phoneNumber);
        saveFirst = saveFirst->next;        
    }
    pclose(fp1);
}
//***********************************************************************//
/*
 * Function: search           
 * ----------------------------
 *   search from the linkedlist
 * 
 *   x: full name with/without last name 
 *   first: Head node of LinkedList
 *
 *   returns: void 
 */                                                                                             
//************************************************************************//
int search(char *x, struct node *first)
{
    bool mybool;
    while (first != NULL)
    {
        if (strncmp(first->fname, x, strlen(x)) == 0)
        {
            mybool = true;
            printf("%s:%s\n", first->fname, first->phoneNumber);
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
//***********************************************************************//
/*
 * Function: deleteAtIndex           
 * ----------------------------
 *   deleteAtIndex will delete the value from the perticular index 
 * 
 *   x: full name with last name 
 *   first: Head node of LinkedList
 *
 *   returns: void 
 */                                                                                             
//************************************************************************//
struct Node *deleteAtIndex(char *x, struct node *first)
{
    printf("the char is %s \n", x);

    // temp is used to freeing the memory
    struct node *temp;
    struct node *newnext;

    // name found on the first node.
    // move the first node to the next and free the first.
    if (strcmp(first->fname, x) == 0)
    {
        temp = first; // backup the first to free its memory
        first = first->next;
        free(temp);
    }
    else
    {
        struct node *current = first;
        //   newnext = current->next;
        while (current->next != NULL)
        {
            // if yes, we need to delete the current->next node
            if (strcmp(current->fname, x) == 0)
            {
                temp = current;
                // node will be disconnected from the linked list.
                current->next = current->next->next;
                free(temp);
                break;
            }
            // Otherwise, move the current node and proceed
            else
            {
                current = current->next;
            }
        }
    }
}
//***********************************************************************//
/*
 * Function: exit_code           
 * ----------------------------
 *   exit_code will help in saving the data after performing all the operations  
 * 
 * 
 *   first: Head node of LinkedList
 *
 *   returns: void 
 */                                                                                             
//************************************************************************//
int exit_code(struct node *first){
    // sort(first);
    FILE *exit_file = fopen("exit_file.csv", "w+");
    // fprintf(exit_file, "%s,%s\n", "name", "number");
    while (first != NULL)
    {
        // printf("\n%s\t%s\n", first->fname, first->phoneNumber);
        fprintf(exit_file, "%s,%s", first->fname, first->phoneNumber);
        printf("==>>%s,%s\n", first->fname, first->phoneNumber);
        first = first->next;
    }   
    fclose(exit_file);

}
int main()
{

    FILE *fp = fopen("100-contacts.csv", "a+");
    struct node *first = (struct node *)malloc(sizeof(struct node));
    int option;
    char number[15];
    char fname[40];
    char lname[40];
    char ch;
    csv_to_ll(fp,first);

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
            ch = fname[0];
            ch = toupper(ch);
            fname[0] = ch;
            ch = lname[0];
            ch = toupper(ch);
            lname[0] = ch;
            strcat(fname, lname);
            printf("adding");
            fseek(fp, 0, SEEK_END);
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
            printf("\nwhom do you want to delete:\n");
            printf("\nenter first name:\n");
            scanf("%s", fname);
            printf("\nenter last name:\n");
            scanf("%s", lname);
            strcat(fname, " ");
            ch = fname[0];
            ch = toupper(ch);
            fname[0] = ch;
            ch = lname[0];
            ch = toupper(ch);
            lname[0] = ch;
            strcat(fname, lname);
            printf("=======");
            printf("%s\n", fname);
            printf("=======");
            deleteAtIndex(fname, first);
            break;
        case 6:
            printf("\nExit\n");
            exit_code(first);    
            break;    
        default:
            printf("\ninvalid option\n");
            break;
        }
        // close(fp);
    }
}