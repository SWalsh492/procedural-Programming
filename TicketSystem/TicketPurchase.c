#include<stdio.h>

void main()
{
	// declare variables
	int age, noOfTicket, timeOfTravel;
	char occupation;
	float ticketPrice;
	float discount, newPrice, ticketDiscount = 0;
	float overallCost;

	// read inputs
	printf("Please enter your age\n");
	scanf("%d", &age);

	printf("Welcome to the ticket service! Please enter the number of ticket's and the price\n");
	scanf("%d %f", &noOfTicket, &ticketPrice);

	printf("Please enter the hour of travel\n");
	scanf("%d", &timeOfTravel);

	printf("Please enter S for student and E for employee\n");
	scanf("%c", &occupation);
	scanf("%c", &occupation);


	printf("Debug %d %d %f %d %c\n", age, noOfTicket, ticketPrice, timeOfTravel, occupation); 

	// I am dead - determine % discount

	if (timeOfTravel >= 0 && timeOfTravel <= 6)
		discount = 20;
	else if (timeOfTravel > 6 && timeOfTravel <= 10)
		discount = 0;
	else if (timeOfTravel > 10 && timeOfTravel <= 15)
		discount = 30;
	else if (timeOfTravel > 15 && timeOfTravel <= 19)
		discount = 0;
	else if (timeOfTravel > 19 && timeOfTravel <= 24)
		discount = 40;

	// check if student discount should be added
	if (occupation == 'S' || occupation == 's')
		ticketDiscount += 10;


	// Currently more dead - Calculate ticket price
	ticketDiscount = ticketPrice * ticketDiscount / 100;
	newPrice = ticketPrice - ticketDiscount;

	// calculate overall cost
	overallCost = noOfTicket * newPrice;

	// Display the result
	printf("The overall cost of your tickets is %.2f\n", overallCost);










}