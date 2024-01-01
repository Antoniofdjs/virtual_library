#include <stdio.h>
#include "main.h"
#include <stdlib.h>

void *delete_book(books **head, const int book_id)
{
	int match = 0;

	books *temp = *head;
	books *prev_book = NULL;

	while (temp != NULL)
	{
		if (temp->id == book_id)
		{
			match = 1; /* found id of book */

			if (prev_book != NULL) /* check if we are not at first node(book) */
			{
				prev_book->next = temp->next;
				free(temp->name);
				free(temp->author);
				free(temp);
			}
			else
			{
				/* Book to delete is the first */
				*head = temp->next;
				free(temp->name);
				free(temp->author);
				free(temp);
				match = 2; /* match 2 indicates its the first node */
			}

			break; /* Book node is deleted */
		}
		prev_book = temp;
		temp = temp->next;
	}

	if (match == 2)
		prev_book = *head;
	else
		prev_book = prev_book->next;

	/* Update the ids of remaining books */
	while (prev_book != NULL)
	{
		prev_book->id = (prev_book->id - 1);
		prev_book = prev_book->next;
	}
}

/**
 *add_node_end- Add a new node to th6e end of the link list

 *@head: head pointer of nodes
 *@str: string6
 *Return: new_node adress
 */

void *add_book_end(books **head, const char *book_name, const char *book_author)
{
	int book_id = 2;
	books *new_book, *temp;

	temp = NULL;

	new_book = malloc(sizeof(books)); /* create node */
	if (new_book == NULL)
		return (NULL);

	new_book->name = strdup(book_name);
	if (new_book->name == NULL)
	{
		free(new_book);
		return (NULL);
	}

	new_book->author = strdup(book_author);
	if (new_book->author == NULL)
	{
		free(new_book->name);
		free(new_book);
		return (NULL);
	}
	if (*head == NULL)
	{
		*head = new_book;
		new_book->id = 1;
	}
	else
	{
		temp = *head; /* temporary *ptr for nodes */
		while (temp->next != NULL)/* finding last node */
		{
			temp = temp->next;
			book_id++;
		}

		temp->next = new_book; /* found last node, point to new_book */
		new_book->id = book_id;
	}
	new_book->next = NULL; /* Finally new_node points to null */
}

/**
 * load_books - loads all books into list every time app opens
 * @head: pointer to adress of head for nodes(linked list books)
 */

void load_books(books **head)
{

	char line[250];
	char *name = NULL;
	char *author = NULL;
	int len = 0;
	FILE *file = fopen("books.txt", "r");

	if (file == NULL)
	{
		perror("Error opening file\n");
		return;
	}

	/*
	 * The next block goes line by line in the .txt file
	 * We make a tokenize to split it into 2 parts
	 * "name--author", devided by the "--" characters
	 * we use strtok to cut via "-"
	 * this allows us seperate name and author of the book
	 * after that we send it to the add_book to make a node for the book
	 */


	while(fgets(line, sizeof(line), file) != NULL) /* create nodes with the .txt file */
	{
		name = strtok(line, "-");
		if (name == NULL)
		{
			printf("ERROR NULL NAME\n");
			return;
		}
		author = strtok(NULL, "-");
		if (author == NULL)
		{
			printf("ERROR NULL AUTHOR\n");
			return;
		}

		len = strlen(author);
		author[len - 1] = '\0';/* remove '\n' at the end of author string */
		add_book_end(head, name, author); /* make a node */
	}
	fclose(file); /*  close file when done */
}

/**
 *print_list- Print list of single linked list for books
 *
 *@h: head pointer of list
 *Return: number of total nodes
 */

void print_list(const books *head)
{
	int total_books = 0;

	while (head != NULL)
	{
		printf("#%d: \"%s\" by %s\n\n", head->id, head->name, head->author);
		total_books++;
		head = head->next;
	}
	printf("Total Books %d\n", total_books);
}

/**
 * free_list- free linked list passing the head to it
 */

void free_list( books *head)
{
	books *temp;
	temp = NULL;

	while (head != NULL)
	{
		temp = head->next;
		free(head->name);
		free(head->author);
		free(head);
		head = temp;
	}
}

