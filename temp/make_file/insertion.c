#include"headerfile.h"
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
