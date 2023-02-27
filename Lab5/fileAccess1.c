#include <stdio.h>

void main() {

	FILE* file1;
	FILE* file2;
	int numbers, numIterations, i;
	float interestRate;
	char letter;

	file1 = fopen("LogFile.txt", "w");
	file2 = fopen("UserReport.txt", "w");

	printf("Please enter the number of iterations\n");
	scanf("%d", &numIterations);

	for (int i = 0; i < numIterations; i++)
	{
		printf("Please enter an integer, float and a character \n");
		scanf("%d %f %c", &numbers, &interestRate, &letter);

		printf("Interest is %d, float is %f, letter is %c\n ", numbers, interestRate, letter);

		if (file1 != NULL)
		{
			fprintf(file1, "%d %f %c\n ", numbers, interestRate, letter);
		}

		if (file2 != NULL)
		{
			fprintf(file2, "Interest is %d, float is %f, letter is %c\n ", numbers, interestRate, letter);
		}
	}

	if (file1 != NULL)
	{
		fclose(file1);
	}
	if (file2 != NULL)
	{
		fclose(file2);
	}




}