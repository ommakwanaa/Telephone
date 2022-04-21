#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *name_var;
char *num_var;
char commma = ',';

int main(){
    char name[20] = "nirmal";
    char num[20] = "883283321";
	FILE *fp = fopen("100-contacts.csv", "a+");char buffer[1024];
		// int row = 0;
		// int column = 0;
		// while (fgets(buffer, 1024, fp))
		// {
		// 	column = 0;
		// 	row++;
		// 	if (row == 1)
		// 		continue;
		// 	char *value = strtok(buffer, ",");
		// 	while (value)
		// 	{
		// 		if (column == 0)
		// 		{
		// 			name_var = value;
		// 		}
		// 		if (column == 1)
		// 		{
		// 			num_var = value;
		// 		}
		// 		value = strtok(NULL, ",");
		// 		column++;
		// 	}

		// }
    fprintf(fp, "%s,%s\n", name, num);
    close(fp);
}