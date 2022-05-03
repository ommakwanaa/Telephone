#include"headerfile.h"
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
