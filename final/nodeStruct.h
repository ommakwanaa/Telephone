
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char phoneNumber[15];
    char fname[20];
    char lname[20];
    struct node *next;
};