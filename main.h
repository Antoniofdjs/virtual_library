#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdlib.h>


typedef struct Books{
char *name;
char *author;
struct Books *next;
}books;

void *add_book(books **head, const char *book_name, const char *book_author);
void load_books(books **head);
void print_list(const books *head);

#endif
