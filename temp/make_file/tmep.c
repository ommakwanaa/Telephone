#include<stdio.h>
#include<string.h>
int main()
{
    char llName[25] = "linkedList_";
    for(char i='A';i<='Z';i++){
        strcat(llName,i);
    }
    // for(char i='A';i<='Z';i++){
    //     printf("%s\n",llName);
    // }
}