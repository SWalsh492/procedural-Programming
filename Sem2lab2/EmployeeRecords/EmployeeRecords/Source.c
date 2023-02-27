#include<stdio.h>
#include<string.h>

typedef struct {
	char name[30];
	int number;
	int weeklyHours;
	float hourlyRate;
}employeeT;

void main()
{
	FILE* fp;
	int numInputs;
	employeeT check;
	employeeT practice[50];
	int addAmount = 0;

	// Display existing Employees
	fp = fopen("employee.txt", "r");

	if (fp == NULL)
	{
		printf("\nSorry the file could not be opened...");
	}
	else {
		while (!feof(fp))
		{
			numInputs = fscanf(fp, "%s %d %d %f", check.name, &check.number, &check.weeklyHours, &check.hourlyRate);
			if (numInputs == 4)
			{
				printf("The line of text is: %s %d %ds %.2f\n", check.name, check.number, check.weeklyHours, check.hourlyRate);
			}
		}
		fclose(fp);
	}

	// Ask user
	printf("How many employees do you wish to add?\n");
	scanf("%d", &addAmount);

	for (int i = 0; i < addAmount; i++)
	{
		printf("Please enter employee name\n");
		scanf("%s", practice[i].name);

		printf("Please enter employee number, weekly hours, hourly rate\n");
		scanf("%d %d %f", &practice[i].number, &practice[i].weeklyHours, &practice[i].hourlyRate);
	}

	// append info

	fp = fopen("employee.txt", "a");
	for (int i = 0; i < addAmount; i++)
	{
		fprintf(fp, "\n%s %d %d %.2f", practice[i].name, practice[i].number, practice[i].weeklyHours, practice[i].hourlyRate);
	}
	fclose(fp);
}
/*
void display(employeeT emp, int i)
{

}
*/