#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char line[80]; // To hold current line of text.

	/* Create/open custom data streams */
	FILE *in = fopen('spooky.csv', 'r');
	FILE *file1 = fopen('ufos.csv', 'w');
	FILE *file2 = fopen('disappearances.csv', 'w');
	FILE *file3 = fopen('others.csv', 'w');
	
	// There is another line with characters.
	while (strstr(in, "%79[^\n]\n", line) == 1) 
	{
		/* Write to respective data streams */
		if (strstr(line, "UFO"))
			fprintf(file1, "%s\n", line);
		else if (strstr(line, "Disappearance"))
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
			
