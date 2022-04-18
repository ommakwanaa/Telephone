// C program for the above approach
// #include <conio.h>
#include <stdio.h>
#include <string.h>
char *hijk;
char *lmnop;
int printing(char *valueee)
{
	hijk = valueee;
}
int printingnumber(char *valueee)
{
	lmnop = valueee;
}
// Driver Code
int main()
{
	// Substitute the full file path
	// for the string file_path
	FILE *fp = fopen("100-contacts.csv", "a+");

	if (!fp)
		printf("Can't open file\n");

	else
	{
		// Here we have taken size of
		// character array 1024 you can modify it
		char buffer[1024];

		int row = 0;
		int column = 0;
		int i = 0;

		while (fgets(buffer, 1024, fp))
		{
			column = 0;
			// printf("\nrow = %d\n",row);
			row++;
			// ignoring the first column as it data has no point

			if (row == 1)
				continue;
			// ignoring the first column

			// Splitting the data
			char *value = strtok(buffer, ",");
			// printf("\nvalue = %s");

			while (value)
			{

				// Column 1
				if (column == 0)
				{
					// printf("%d Name. :",i);
					// printf("%s", value);
					printing(value);
					printf("\nname:= %s", hijk);

					// printf("\n1\n");
				}

				// Column 2
				if (column == 1)
				{
					// printf("\tcontact_1. :");
					// printf("%s", value);
					// printf("\n2\n");
					printingnumber(value);
					printf("\nnumber:= %ls", lmnop);
				}

				// printf("%s", value);

				value = strtok(NULL, ",");
				column++;
			}
			i++;

			printf("\n");
		}
		char *nam = "nirmal makwana";
		char *num = "7990051361";
		// fputs(nam+num,fp);
		fprintf(fp, "\n%s,%s", nam, num);
		fclose(fp);
	}
	return 0;
}