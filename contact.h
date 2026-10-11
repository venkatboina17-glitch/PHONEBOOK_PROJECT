#ifndef CONTACT_H
#define CONTACT_H

#define MAX_NAME 50
#define MAX_PHONE 15
#define MAX_EMAIL 50
#define MAX_ADDRESS 100
#define MAX_PHONES 5
#define FILE_NAME "phonebook.dat"

typedef enum
{
    NO = 0,
    YES = 1
} Choice;

typedef struct Contact
{
    char name[MAX_NAME];
    char phone[MAX_PHONES][MAX_PHONE];
    int phone_count;
    char email[MAX_EMAIL];
    char address[MAX_ADDRESS];

    struct Contact *link;
} Contact;

void read_string(char *str, int size);
int contact_exists(Contact *head, char *name);

void create_contact(Contact **head);
void print_contacts(Contact *head);
void find_contact(Contact *head);
void delete_contact(Contact **head);
void edit_contact(Contact *head);

void save_contacts(Contact *head);
void load_contacts(Contact **head);

void free_contacts(Contact **head);

#endif
