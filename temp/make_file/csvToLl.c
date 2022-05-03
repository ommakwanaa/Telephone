#include"headerfile.h"

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
