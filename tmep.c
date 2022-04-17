#include<stdio.h>
#include<string.h>

void foo(char *f){
    printf("%s",f);
}

int main(){
    char nirmal[20];
    scanf("%s",nirmal);
    foo(nirmal);
}