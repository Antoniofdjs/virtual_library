#include <stdio.h>
#include "main.h"

void print_admin_options(void)
{
	printf("[1]: Add New Book to list\n");
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
	int on = 1;

	(void)head;
	printf("PASSWORD: ");
	read = getline(&str_option, &len, stdin);
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
			read = getline(&str_option, &len, stdin);
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
							printf("Added Book\n");
							break;
						}
					case '2':
						{
							printf("Deleted Book\n");
							break;
						}
					case '3':
						{
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

