// C program for the above approach
// #include <conio.h>
#include <stdio.h>
#include <string.h>

// Driver Code
int main()
{
	// Substitute the full file path
	// for the string file_path
	FILE* fp = fopen("100-contacts.csv", "r");

	if (!fp)
		printf("Can't open file\n");

	else {
		// Here we have taken size of
		// array 1024 you can modify it
		char buffer[1024];
	

		int row = 0;
		int column = 0;
		int i=0;

		while (fgets(buffer,1024, fp)) {
			column = 0;
			// printf("\nrow = %d\n",row);
			row++;
			//ignoring the first column

			if (row == 1)
				continue;
			//ignoring the first column

			// Splitting the data
			char* value = strtok(buffer, ",");

			while (value) {
				
				// Column 1
				if (column == 0) {
					printf("%d Name. :",i);
				}

				// Column 2
				if (column == 1) {
					printf("\t\t\t\tcontact_1. :");
				}

				printf("%s", value);
				value = strtok(NULL, ",");
				column++;
				
			}
			i++;

			printf("\n");
		}

		// Close the file
		fclose(fp);
	}
	return 0;
}


