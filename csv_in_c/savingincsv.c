#include <stdio.h>
#include <string.h>
int main(){
   FILE *fp1 = fopen("contacts.csv", "a+"); 
   fprintf(fp1, "%s, %s\n","om", "makwana");
}