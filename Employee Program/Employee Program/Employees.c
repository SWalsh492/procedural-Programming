#include <stdio.h>


void main()
{
	int employeeNum , hoursWorked, extraHours = 0;
	float rateOfPay, weeklyWage, totalWageBill = 0;
	int mostHours = 0, topEmployee = 0;

	printf("Please enter the employee number or -1 to exit: \n");
	scanf("%d", &employeeNum);

	while (employeeNum != -1)
	{
		printf("Please enter total hours worked and hourly rate of pay: \n");
		scanf("%d %f", &hoursWorked, &rateOfPay);

		if (hoursWorked <= 39)
		{
			weeklyWage = rateOfPay * hoursWorked;
		}
		else if (hoursWorked > 39 && hoursWorked <= 50)
		{
			weeklyWage = (hoursWorked - 39) * (10 * 1.5f) + (39.00f * rateOfPay);
			extraHours += hoursWorked;
		}
		else if (hoursWorked > 50)
		{
			weeklyWage = (hoursWorked - 50) * (2 * rateOfPay) + 11 * (10 * 1.5f) + (39.00 * rateOfPay);
			extraHours += hoursWorked;
		}
		totalWageBill += weeklyWage;

		printf("Employee Number %d has a total salary of %.2f\n", employeeNum, weeklyWage);

		if (hoursWorked > mostHours)
		{
			mostHours = hoursWorked;
			topEmployee = employeeNum;
		}


		printf("Please enter the employee number or -1 to exit: \n");
		scanf("%d", &employeeNum);
	}

	printf("Total company wage are %f \nThe total number of hours above the 39 hours per week is %d \nEmployee %d had the most hours worked with %d \n", totalWageBill, extraHours, topEmployee, mostHours);





}