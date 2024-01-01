#include <stdio.h>
#include "main.h"



void print_add_instructions(void)
{
	printf("Type the title of the book and the author like the following example, ignore the ' ':\n");
	printf("'Book title goes here--Author goes here'\n");
	printf("'Title--Author'(the '--' will split the title from the author\n");
	printf(">");
}

void admin_add(books **head)
{
	char *str_input = NULL;
	size_t len = 0;
	ssize_t read;
	char *name = NULL, *author = NULL;
	char *line = NULL;

	print_add_instructions();
	read = getline(&str_input, &len, stdin);
	if (read == -1)
	{
		printf("ERROR INPUT");
		free(str_input);
		return;
	}
	str_input[read - 1] = '\0'; /* remove \n at end */
	if(str_input != NULL && head != NULL)
	{
		line = strdup(str_input);
		name = strtok(line, "-");
		author = strtok(NULL, "-");
		add_book_end(head, name, author);
		free(str_input);
		free(line);
		printf("\nBook was added\n\n");
	}
}
void print_admin_options(void)
{
	printf("\n[1]: Add New Book to list\n");
	printf("[2]: Delete Book from list\n");
	printf("[3]: Edit Book from list\n");
	printf("[4]: Exit\n>>");

}
void admin_settings(books **head)
{
	char *str_option = NULL;
	size_t len = 0;
	ssize_t read;
	char *password = "1234";
	int on = 1, input;

	printf("\nPASSWORD: ");
	read = getline(&str_option, &len, stdin); /* gets the password */
	if (read == -1)
	{
		printf("ERROR INPUT");
		free(str_option);
		return;
	}
	str_option[read - 1] = '\0';

	if (strcmp(str_option, password) == 0)
	{
		while (on == 1)
		{
			print_admin_options();
			read = getline(&str_option, &len, stdin); /* gets the option from admin */
			if (read == -1)
			{
				printf("ERROR INPUT");
				free(str_option);
				return;
			}
			else
			{
				switch (str_option[0])
				{
					case '1':
						{
							admin_add(head);
							break;
						}
					case '2':
						{
							printf("Enter book id to delete (#number);>>#");
							read = getline(&str_option, &len, stdin); /* gets the password */
							if (read == -1)
							{
								printf("ERROR INPUT");
								free(str_option);
								return;
							}
							str_option[read - 1] = '\0';
							input = atoi(str_option);
							delete_book(head, input);
							break;
						}
					case '3':{
								 printf("Edit Book\n");
								 break;
							 }
					case '4':
							 {
								 on = 0;
								 break;
							 }
					default:
							 printf("Choose a valid option 1 2 3 or 4\n");
				}
			}
		}
	}
	else
		printf("\nWrong password\n");

	printf("\nExited admin options\n\n\n");
	free(str_option);
}

