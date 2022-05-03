#include<stdio.h>
#include<string.h>
int main()
{
    char llName[25] = "linkedList_";
    char i;
    int j=0;

    for(i='A';i<='Z';i++){
        strcat(llName,&i);
    }

    for(j=0;j<=25;j++){
        printf("%s\n",llName[j]);
    }
}