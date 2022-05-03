#include"headerfile.h"
/*
* Function: deleteAtIndex           
* ------------------------------------------------------------------------//
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
