#include <stdio.h>
#include <string.h>
#include "main.h"


/** * welcome_msg - greets the user
*/

void welcome_msg(void)
{
	int i;

	printf("\n\n\n");
	for (i = 0; i < 36; i++)
		printf("-");
	printf("\n\n\n");
	printf(" WELCOME TO MY LIBRARY\n");
	printf("\n\nHere you will find available books\n");
	printf("to take home with a permit.\n\n");
}

/** * loop_options- prints all options for user
*/

void print_options(void)
{
	printf("\n\nChoose an option:\n\n");
	printf("[1]: Rent a Book\n");
	printf("[2]: List All Books\n");
	printf("[3]: Administrator Settings\n");
	printf("[4]: Exit\n\n");
}

int main (void)
{

	int on = 1, i;
	char *str_option = NULL;
	size_t len = 0;
	ssize_t read;

	books *head = NULL;
	load_books(&head);
	welcome_msg();

	print_options();/* prints options to choose */


	while (on == 1)
	{
		printf(">");
		read = getline(&str_option, &len, stdin);
		if (read == -1)
		{
			on = 0;
		}
		else
		{
			str_option[read - 1] = '\0'; /* remove \n from get line at end */

			if ((strcmp(str_option, "1")) == 0)
			{
				printf("\n\n[RENT A BOOK]\n\n");
				print_options();
			}
			else if ((strcmp(str_option, "2")) == 0)
			{
				printf("\n\n\n");
				printf("-----BOOK LIST-----\n\n");
				print_list(head);
				for (i = 0; i < 40; i++)
					printf("-");
				printf("\n\n\n");
				print_options();
			}
			else if ((strcmp(str_option, "3")) == 0)
			{
				admin_settings(&head);
				print_options();
			}
			else if ((strcmp(str_option, "4")) == 0)
			{
				on = 0;
			}
			else
			{
				printf("\nERROR: CHOOSE A VALID OPTION 1, 2 OR 3\n");
				print_options();
			}
		}
	}
	printf("\n\nThankyou for visiting we hope to see you soon\n");
	printf("-----------------------------------\n\n\n");
	free_list(head);
	free(str_option);
}
