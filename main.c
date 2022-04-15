#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int insert(){
    int

}
int main(){
    int option;
    printf("Enter :\n1 to insert\n2 to search\n3 to read\n4 to sort\n5 to delete\n");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        printf("insertion");
        break;
    case 2:
        printf("search");
        break;
    case 3:
        printf("read");
        break;
    case 4:
        printf("short");
        break;
    case 5:
        printf("delete");
        break;
    default:
    printf("invalid option");
        break;
    }
    
}
