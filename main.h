#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdlib.h>
#include <signal.h>


typedef struct Books{
char *name;
char *author;
struct Books *next;
}books;

void admin_settings(books **head);
void *add_book_end(books **head, const char *book_name, const char *book_author);
void load_books(books **head);
void print_list(const books *head);
void free_list( books *head);

#endif
