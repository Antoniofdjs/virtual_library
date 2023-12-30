#include <stdio.h>
#include "main.h"

/**
 *add_node- Add a new node to the start of the link list
 *
 *@head: head pointer of nodes
 *@book_name: name of book
 *@book_author: name of author of book
 */

void *add_book(books **head, const char *book_name, const char *book_author)
{
	books *new_book; /* make a node */

	new_book = malloc(sizeof(books));
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
	}
	new_book->next = *head;
	*head = new_book;
}

/**
 * load_books - loads all books into list every time app opens
 * @head: pointer to adress of head for nodes(linked list books)
 */

void load_books(books **head)
{

	char line[200];
	char *name;
	char *author;
	int len;
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
		author = strtok(NULL, "-");
		len = strlen(author);
		author[len - 1] = '\0';/* remove '\n' at the end of author string */
		add_book(head, name, author); /* make a node */
	}
	fclose(file); /*  close file when done */
}

/**
 *print_list- Print list of single linked list for books
 *
 *@h: head pointer of nodes
 *Return: number of total nodes
 */

void print_list(const books *head)
{
	int total_books = 0;
	int id = 1; /* id number for book, //should make this in the node?// */

	while (head != NULL)
	{
		printf("#%d: \"%s\" by %s\n", id, head->name, head->author);
		id++;
		total_books++;
		head = head->next;
	}
	printf("Total Books %d\n", total_books);
}
