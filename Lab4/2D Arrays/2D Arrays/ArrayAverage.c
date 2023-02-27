#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void main()
{
	// declare array and variables
	int numList[20];
	int total = 0;
	float average;

	// loop through array num assignment
	for (int i = 0; i <= 19; i++)
	{
		printf("Please enter array element %d: ", i);
		scanf("%d", &numList[i]);
		// numList[i] = rand();
		total += numList[i];
	}

	// Calculate and present average
	average = total / 20;
	printf("The average of this array is %.2f\n", average);

	// Loop through and display the nums < average
	printf("The numbers below are lower than the average: \n");
	for (int c = 0; c <= 19; c++)
	{
		if (numList[c] < average)
		{
			printf("%d\n", numList[c]);
		}
	}


}
