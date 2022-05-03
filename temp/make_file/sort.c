#include"headerfile.h"
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
