#include <stdio.h>

#define ROWS 3
#define COLS 3

void main()
{
	int i, j;

	int array1[3][3];
	int array2[3][3];
	int array3[3][3];

	// Matrice 1
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			printf("For first matrice, please enter number %d, %d: ", i, j);
			scanf("%d", &array1[i][j]);
		}
	}

	// Matrice 2
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			printf("for second matrice, please enter number %d, %d: ", i, j);
			scanf("%d", &array2[i][j]);
		}
	}

	// Add the two
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			array3[i][j] = array2[i][j] + array1[i][j];
			printf("%d\n", array3[i][j]);
		}
	}



}