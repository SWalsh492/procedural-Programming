#include<stdio.h>
#include<string.h>


void main() {
	int table[5][4];
	int mayorLoc = 0;
	FILE* fp;
	enterVotes(table);
	displayVotes(table);
	mayorLoc = stateWinners(table, mayorLoc);
	displayMayor(mayorLoc);

	fp = fopen("votes.txt", "w");
	if (fp == NULL)
	{
		printf("\nSorry the file could not be opened...");
	}
	else {
			for (int i = 0; i < 5; i++)
			{
				fprintf(fp, "State %d: ", i + 1);
				for (int j = 0; j < 4; j++)
				{
					fprintf(fp, "%d", table[i][j]);
				}
				fprintf(fp,"\n");
			}
		fclose(fp);
	}
}

int enterVotes(int table[5][4]) {

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("Please enter votes for state %d, candidate %d\n", i + 1, j + 1);
			scanf("%d", &table[i][j]);
		}
		printf("\n");
	}
}

int displayVotes(int table[5][4]) {
	printf("State		A	B	C	D\n");
	for (int i = 0; i < 5; i++)
	{
		printf("State %d:	", i+1);
		for (int j = 0; j < 4; j++)
		{
			printf("%d	", table[i][j]);
		}
		printf("\n");
	}
}
int stateWinners(int table[5][4], int mayorLoc) {
	int winnerLoc = 0;
	int highest = 0;
	char candidates[4] = {'A','B','C','D'};
	int mostWins[4] = {0, 0, 0, 0};

	for (int i = 0; i < 5; i++)
	{
		highest = 0;
		for (int j = 0; j < 4; j++)
		{
			if (table[i][j] > highest)
			{
				highest = table[i][j];
				winnerLoc = j;
			}
		}
		printf("The winner of state %d is %c\n", i+1, candidates[winnerLoc]);
		if (candidates[winnerLoc] == 'A')
			mostWins[0]++;
		else if (candidates[winnerLoc] == 'B')
			mostWins[1]++;
		else if (candidates[winnerLoc] == 'C')
			mostWins[2]++;
		else if (candidates[winnerLoc] == 'D')
			mostWins[3]++;

		for (int f = 0; f < 4; f++)
		{
			if (mostWins[f] > mostWins[winnerLoc])
				mayorLoc = f;
		}
	}
	return mayorLoc;
}
int displayMayor(int mayorLoc) {
	char mayor;
	
	switch (mayorLoc)
	{
	case 0:
		mayor = 'A';
		break;
	case 1:
		mayor = 'B';
		break;
	case 2:
		mayor = 'C';
		break;
	case 3:
		mayor = 'D';
		break;
	default:
		mayor = 'X';
		break;
	}
	printf("The new Mayor of the City is Candidate %c\n", mayor);
}