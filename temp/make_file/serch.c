#include<headerfile.h>
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
