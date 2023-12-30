#include <stdio.h>
#include <string.h>
#include "main.h"


/**
 * list_books - prints the list of all books and the total
 */

void list_books(void)
{

	int letter;

	FILE *file = fopen("books.txt", "r");

	if (file == NULL)
	{
		perror("Error opening file");
		return;
	}

	while ((letter = fgetc(file)) != EOF) /* this gets each line until file ends */
		putchar(letter);
	fclose(file);
}



/**
 * welcome_msg - greets the user
 */

void welcome_msg(void)
{
	printf("\n\n\n-----------------------------------\n\n\n");
	printf(" WELCOME TO MY LIBRARY\n");
	printf("\n\nHere you will find available books\n");
	printf("to take home with a permit.\n\n");
}

/**
 * loop_options- prints all options for user
 */

void loop_options(void)
{
	printf("\n\nChoose an option:\n\n");
	printf("[1]: Rent a Book\n");
	printf("[2]: List All Books\n");
	printf("[3]: Exit\n\n:");
}

int main (void)
{

	int on = 1;
	char *str_option;

	books *head = NULL;
	load_books(&head);
	welcome_msg();

	while (on == 1)
	{
		loop_options();/* prints options to choose */
		scanf("%s:",str_option);
		if ((strcmp(str_option, "1")) == 0)
			printf("\n\n[RENT A BOOK]\n\n");
		else if ((strcmp(str_option, "2")) == 0)
		{
			printf("\n\n\n");
			print_list(head);
			printf("\n\n\n");
		}
		else if ((strcmp(str_option, "3")) == 0)
			on = 0;
		else
			printf("\nERROR: CHOOSE A VALID OPTION 1, 2 OR 3\n");
	}
	printf("\n\n\n-----------------------------------\n\n\n");
}
