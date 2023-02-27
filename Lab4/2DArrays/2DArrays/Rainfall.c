#include<stdio.h>

#define ROWS 2
#define COLS 6

void main()
{
	float weeklyRainfall[ROWS][COLS];
	int i, j;
	float total = 0, average = 0, maxRainfall = 0;
	int dayMost = 0, hrMost = 0;

	//read in weekly rainfall
	for (i = 0; i < ROWS; i++)
	{
		printf("day %d: \n", i+1);
		for (j = 0; j < COLS; j++)
		{
			printf("Please enter the input for day %d, hour %d:\n", i+1, j+1);
			scanf("%f", &weeklyRainfall[i][j]);
			total += weeklyRainfall[i][j];
			if (weeklyRainfall[i][j] > maxRainfall)
			{
				maxRainfall = total;
				hrMost = j+1;
				dayMost = i+1;
			}
		}
		//end of a day, calculate average
		average = total / COLS;
		printf("\nAverage rainfall for day %d is: %f\n", i+1, average);
		total = 0;
	}

	// Display rainfall
	printf("Weekly Rainfall\n\n");
	for (i = 0; i < ROWS; i++)
	{
		printf("\nDay %d: \n", i+1);
		for (j = 0; j < COLS; j++)
		{
			printf("Hour %d = %.2f\t", j+1, weeklyRainfall[i][j]);
		}
		printf("\n\n");
	}	

	// Display day and hour with most
	printf("The max rainfall was %f on day %d hour %d\n", maxRainfall, dayMost, hrMost);




}