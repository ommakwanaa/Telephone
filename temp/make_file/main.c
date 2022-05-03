#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "headerfile.h"

int main()
{
    // char llName[25];
    // for(char i=0;i<25;i++){
    //     strcpy(llName, "Linkedlist_");
    //     strcpy(llName,i(char));
    // }
    // for(char i=0;i<25;i++){
    //     printf("%s\n",llName);
    // }
    
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
