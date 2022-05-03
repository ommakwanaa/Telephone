#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


struct node *insAtEnd(char *, char *, struct node *);
void csv_to_ll(FILE * ,struct node *);
void display(struct node *);
void sort(struct node *first);
int search(char *, struct node *);
struct Node *deleteAtIndex(char *, struct node *);
int exit_code(struct node *);