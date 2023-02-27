#include<stdio.h>

void main() {
	//Decalre variables
	float written, lab, assignment, overall;
	float average = 0;
	char grade= ' ';

	//User input
	printf("Please input each of your results in the order: Written, Lab, Assignment.\n");
	scanf("%f %f %f", &written, &lab, &assignment);
	printf("Written: %.1f, lab: %.1f, assignment: %.1f\n", written, lab, assignment);

	//Calculate average
	average = (written / 100 * 60) + (lab / 100 * 10) + (assignment / 100 * 30);
	printf("Average: %.1f\n", average);

	//Determine Grade
	if (average >= 70 && average <= 100) {
		grade = 'A';
	}
	else if (average >= 60 && average < 70) {
		grade = 'B';
	}
	else if (average >= 50 && average < 60) {
		grade = 'C';
	}
	else if (average >= 40 && average < 50) {
		grade = 'D';
	}
	else  if (average < 40 && average > 0) {
		grade = 'E';
	}
	else if (average > 100 || average < 0)
	{
		printf("Invalid result, grade must fit typical result spectrum, please try again\n");
		grade = 'F';
	}
	else
	{
		printf("Non applicable result, you broke the system. Please try again\n");
		grade = 'F';
	}

	//Output Result and grade
	if (grade != 'F')
	{
		printf("Your grade is: %c and the percentage is %.1f", grade, average);
	}




	/*
	switch (average)
	{
		case average >  90:
			grade = 'A';
			break;



		default:
			break;
	}

	*/


}