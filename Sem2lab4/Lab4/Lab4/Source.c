#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	int number;
	char title[30];
	char author[25];
	float price;
}bookT;

//void read_Book(bookT* library, int size);
void set_Book(bookT* library, int size);
void add_book(bookT* library, int size);
void display_book(bookT* library, int size);
void edit_book(bookT* library, int size);

void main() {
	int numberOfBooks;
	int choice = 0;
	bookT* library;

	printf("Please enter the number of books in the library\n");
	scanf("%d", &numberOfBooks);

	library = (bookT*)malloc(numberOfBooks * sizeof(bookT));
	set_Book(library, numberOfBooks);


	do
	{
		printf("\nWhich function would you like to perform?\nSearch book: 1\nAdd book: 2\nEdit book: 3\nTo Exit: -1\n");
		scanf("%d", &choice);

		if (choice == 1)
			display_book(library, numberOfBooks);
		else if (choice == 2)
		{
			add_book(library, numberOfBooks);
		}
		else if (choice == 3)
			edit_book(library, numberOfBooks);

	}while(choice != -1);
	
}

void set_Book(bookT* library, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		(library + i)->number = 0;
	}
}

void add_book(bookT* library, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (library->number == 0)
		{
			printf("Enter book ISBN \n");
			scanf("%d", &(library+i)->number);

			printf("Enter book title \n");
			scanf("%s", (library + i)->title);

			printf("Enter author name\n");
			scanf("%s", (library+i)->author);

			printf("Enter Price\n");
			scanf("%f", &(library+i)->price);
		}
	}
}

void display_book(bookT* library, int size)
{
	int i;
	int searchNum;
	printf("Please enter ISBN \n");
	scanf("%d", &searchNum);

	for (i = 0; i < size; i++)
	{
		if (searchNum == (library + i)->number)
		{
			printf("Num: %d \nTitle: %s \nAuthor: %s \nPrice: %.2f", (library+ i)->number, (library + i)->title, (library + i)->author, (library + i)->price);
		}
	}
}

void edit_book(bookT* library, int size)
{
	int editChoice;
	printf("Which book would you like to edit price of?");
	scanf("%d", &editChoice);

	printf("Enter New Price\n");
	scanf("%f", &(library + editChoice)->price);
}

/*void read_Book(bookT* library, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("Book: %d \nTitle: %s \nAuthor: %s \nPrice: %f", i+1, (library + i)->title, (library + i)->author, (library + i)->price);
	}
}*/