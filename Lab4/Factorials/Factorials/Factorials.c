#include <stdio.h>

void main()
{
	int input = 0, totalSum = 0, currentSum = 0;
	int counter = 0;

	printf("Please enter a number to factorise: ");
	scanf("%d", &input);
	counter = input;
	totalSum = counter;

	while (counter >= 2)
	{
		currentSum = totalSum;
		counter--;
		totalSum = totalSum * counter;
		printf("%d X %d = %d\n", currentSum, counter, totalSum);
		printf("Debug: %d\n", totalSum);
	}










}