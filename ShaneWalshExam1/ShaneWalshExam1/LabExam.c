#include <stdio.h>

void main()
{
	// Variable declarations
	int departmentID, planID;
	int summerDayUnits, summerNightUnits, winterUnits, numOfLowNightDept = 0;
	float summerDayRate = 0, summerNightRate = 0, winterRate = 0;
	float compAnnual = 0, deptAnnual, summerNightBill, maxSummerNightBill = 0;

	// Reads in department ID or -1 to skip do while
	printf("Please enter the department ID or -1 to exit the loop: \n");
	scanf("%d", &departmentID);
	
	while (departmentID < -1) // Handling incorrect input
	{
		printf("Incorrect input, please input an appropriate department ID: ");
		scanf("%d", &departmentID);
	}

	while (departmentID != -1) // Keeps us in loop while necessary
	{
		// Reads in unit amounts and planID
		printf("Please enter the summer day time units, summer night time units, winter units and the electricity plan ID: \n");
		scanf("%d %d %d %d", &summerDayUnits, &summerNightUnits, &winterUnits, &planID);

		// Assigns electricity rates approriately based on planID
		switch (planID)
		{
		case 1:
			summerDayRate = 0.5;
			summerNightRate = 0.1;
			winterRate = 0.6;
			break;

		case 2:
			summerDayRate = 0.75;
			summerNightRate = 0.2;
			winterRate = 0.85;
			break;

		case 3:
			summerDayRate = 1.1;
			summerNightRate = 0.3;
			winterRate = 1.3;
			break;
		}

		// Calculates annual electricity in current department, adds to company annual and sets summer night bill
		deptAnnual = (summerDayUnits * summerDayRate) + (summerNightUnits * summerNightRate) + (winterUnits * winterRate);
		compAnnual += deptAnnual;
		summerNightBill = summerNightUnits * summerNightRate;

		// Counts up number of night units below 1000
		if (summerNightUnits < 1000)
		{
			numOfLowNightDept++;
		}
		// Sets new maximum summer night bill if approriate
		if (maxSummerNightBill < summerNightBill)
		{
			maxSummerNightBill = summerNightBill;
		}

		// Outputs total electricity bill and summer night time bill for current department
		printf("\nThe total bill of dept %d is %.2f and the night time summer cost is %.2f\n", departmentID, deptAnnual, summerNightBill);

		// Reads user input for another department ID or loop exit
		printf("\nPlease enter the department ID or -1 to exit the loop: \n");
		scanf("%d", &departmentID);
		
		while (departmentID < -1) // Handling incorrect input
		{
			printf("Incorrect input, please input an appropriate department ID: ");
			scanf("%d", &departmentID);
		}

	}

	// Outputs company annual bill, max summer night time bill and number of departments with low night-time units
	printf("\nThe total company bill is %.2f \nTHe max summer night time bill by any department was %.2f \nThe number of department with less than 1000 summertime night units is %d \n", compAnnual, maxSummerNightBill, numOfLowNightDept);

}