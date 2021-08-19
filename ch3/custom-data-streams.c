#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char line[80]; // To hold current line of text.

	if (argc != 6)
	{
		fprintf(stderr, "You need to give 5 arguments\n");
		return 1;
	}

	/* Create/open custom data streams */
	FILE *in = fopen("spooky.csv", "r");
	FILE *file1 = fopen(argv[2], "w");
	FILE *file2 = fopen(argv[4], "w");
	FILE *file3 = fopen(argv[5], "w");
	
	// There is another line with characters.
	while (fscanf(in, "%79[^\n]\n", line) == 1) 
	{
		/* Write to respective data streams */
		if (strstr(line, argv[1]))
			fprintf(file1, "%s\n", line);
		else if (strstr(line, argv[3]))
			fprintf(file2, "%s\n", line);
		else
			fprintf(file3, "%s\n", line);
	}

	/* Close custom data streams */
	fclose(file1);
	fclose(file2);
	fclose(file3);
	fclose(in);

	return 0;
}
			
