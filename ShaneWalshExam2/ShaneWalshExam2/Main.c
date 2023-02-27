#include <stdio.h>

void main()
{
	// Variables
	float lastYear[12], thisYear[12];
	float compareHighest = 0, compareLowest = 1000;
	int highestThis = 0, lowestThis = 0;
	int highestLast= 0, lowestLast = 0;

	// Inflation file declared
	FILE* inflationFile;

	inflationFile = fopen("inflation.txt", "w"); // Open inflationFile

	// Take in LAST years inflation from user
	for (int i = 0; i < 12; i++)
	{
		printf("please enter the inflation for month %d of last year\n", i+1);
		scanf("%f", &lastYear[i]);
		if (lastYear[i] >= compareHighest) // Calc highest last year
		{
			compareHighest = lastYear[i];
			highestLast = i+1;
		}
		if (lastYear[i] <= compareLowest) // Calc lowest last year
		{
			compareLowest = lastYear[i];
			lowestLast = i+1;
		}
	}

	// Take in THIS years inflation from user
	compareHighest = 0; // Resets highest and lowest for following year
	compareLowest = 1000;
	for (int i = 0; i < 12; i++)
	{
		printf("please enter the inflation for month %d of this year\n", i + 1);
		scanf("%f", &thisYear[i]);
		if (thisYear[i] >= compareHighest) // Calc highest this year
		{
			compareHighest = thisYear[i];
			highestThis = i+1;
		}
		if (thisYear[i] <= compareLowest) // Calc lowest this year
		{
			compareLowest = thisYear[i];
			lowestThis = i+1;
		}
	}

	// Display table of data
	printf("Month\tThis Year\tLast Year\n");
	fprintf(inflationFile, "Month\tThis Year\tLast Year\n");

	for (int i = 0; i < 12; i++)
	{
		printf("%d	  %.2f	  %.2f\n", i+1, thisYear[i], lastYear[i]);

		if (inflationFile != NULL)
		{
			fprintf(inflationFile, "%d	  %.2f	  %.2f\n", i + 1, thisYear[i], lastYear[i]); // Write data to file
		}
	}
	if (inflationFile != NULL)
	{
		fclose(inflationFile); // Close inflationFile
	}

	// Check for negative inflation within LAST years
	for (int i = 0; i < 12; i++)
	{
		if (lastYear[i] < 0)
		{
			printf("Month %d is negative inflation last year\n", i+1);
		}
	}

	// Check for negative inflation within THIS year
	for (int i = 0; i < 12; i++)
	{
		if (thisYear[i] < 0)
		{
			printf("Month %d is negative inflation this year\n", i+1);
		}
	}

	// Calculate highest and lowest of LAST year
	printf("Highest inflation last year is in month %d\n", highestLast);
	printf("Lowest inflation last year is in month %d\n\n", lowestLast);

	// Calculate highest and lowest of THIS year
	printf("Highest inflation this year is in month %d\n", highestThis);
	printf("Lowest inflation this year is in month %d\n\n", lowestThis);
}