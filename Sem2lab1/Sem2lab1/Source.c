#include<stdio.h>
#include<string.h>

void main()
{
	FILE* fp;
	char dept[20];
	int numInputs;
	int sales;
	int totalSales = 0;
	//hardware
	int totalHardware = 0;
	int averageHardware = 0;
	int hardwareInputs = 0;
	int maxHardware = 0;
	// grocery
	int totalGrocery = 0;
	int averageGrocery = 0;
	int groceryInputs = 0;
	int maxGrocery = 0;
	// Drapery
	int totalDrapery = 0;
	int averageDrapery = 0;
	int draperyInputs = 0;
	int maxDrapery = 0;

	fp = fopen("Dailysales.txt", "r");

	if (fp == NULL)
	{
		printf("Sorry the file could not be opened...");
	}

	else {
		while (!feof(fp))
		{
			numInputs = fscanf(fp, "%s %d", dept, &sales);
			if (numInputs == 2)
			{
				printf("The line of text is: %s %d\n", dept, sales);

				if (strcmp(dept, "Hardware") == 0)
				{
					printf("This is a hardware sale\n");
					totalSales += sales;
					totalHardware += sales;
					hardwareInputs++;
					if (sales > maxHardware)
					{
						maxHardware = sales;
					}
				}
				else if (strcmp(dept, "Grocery") == 0)
				{
					printf("This is a grocery sale\n");
					totalSales += sales;
					totalGrocery += sales;
					groceryInputs++;
					if (sales > maxGrocery)
					{
						maxGrocery = sales;
					}
				}
				else if (strcmp(dept, "Drapery") == 0)
				{
					printf("This is a drapery sale\n");
					totalSales += sales;
					totalDrapery += sales;
					draperyInputs++;
					if (sales > maxDrapery)
					{
						maxDrapery = sales;
					}
				}
			}
		}
		fclose(fp);

		// Math
		printf("Total daily sales: %d\n", totalSales);

		//hardware
		averageHardware = totalHardware / hardwareInputs;
		printf("Average Hardware Sales: %d \nMaximum sales in Hardware: %d\n", averageHardware, maxHardware);

		//grocery
		averageGrocery = totalGrocery / groceryInputs;
		printf("Average Grocery Sales: %d \nMaximum sales in Grocery: %d\n", averageGrocery, maxGrocery);

		//Drapery
		averageDrapery = totalDrapery / draperyInputs;
		printf("Average Drapery Sales: %d \nMaximum sales in Drapery: %d\n", averageDrapery, maxDrapery);
	}
}