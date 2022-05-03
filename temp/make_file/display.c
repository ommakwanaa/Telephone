#include<headerfile.h>
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
