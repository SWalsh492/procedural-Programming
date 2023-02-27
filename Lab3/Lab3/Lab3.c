#include <stdio.h>

void main()
{
	float input = 0;
	float totalSum = 0;
	float average = 0, noOfEntries = 0;

	while (input != -1)
	{
		totalSum = totalSum + input;

		printf("Debug %.2f\n", totalSum);

		printf("Enter any number to enter integer or -1 to calculate your average\n");
		scanf("%f", &input);
		noOfEntries = noOfEntries + 1;
	}

	// calc average
	average = totalSum / noOfEntries;
	printf("Average is %.2f", average);





















}