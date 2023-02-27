#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
void main() 
{
	int number, result;
	float rate, result2;

	int list[6];
	int numOfDrawNumbers = 0;
	int duplicate;
	int i;

	srand(time(NULL));

	printf("Please enter an integer and a float\n");
	scanf("%d %f", &number, &rate);

	result2 = sqrt(rate);
	printf("The square root of %f is %f\n", rate, result2);

	result2 = pow(10, 2);
	printf("The power of 10 to the power of 2 is %f\n", result2);

	for (i = 0; i < 6; i++)
	{
		result = rand();
		result = (result % 6) + 1;

		duplicate = 0;
		// check for duplicates

		for (int p = 0; p < numOfDrawNumbers; p++)
		{
			if (list[p] == result)
			{
				duplicate = 1;
			}
		}

		if (duplicate == 0)
		{
			list[i] = result;
			numOfDrawNumbers++;
		}
		else if (duplicate == 1)
		{
			i = i - 1;
		}

		printf("the value of number %d is %d\n", i, list[i]);
	}

}