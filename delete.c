#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contact.h"

void delete_contact(Contact **head)
{
    Contact *temp;
    Contact *prev;
    char name[MAX_NAME];

    if(*head == NULL)
    {
        printf("Phone book is empty\n");
        return;
    }

    printf("Enter contact name to delete: ");
    read_string(name, MAX_NAME);

    temp = *head;
    prev = NULL;

    while(temp != NULL)
    {
        if(strcmp(temp->name, name) == 0)
        {
            if(prev == NULL)
                *head = temp->link;
            else
                prev->link = temp->link;

            free(temp);

            printf("Contact deleted successfully\n");
            return;
        }

        prev = temp;
        temp = temp->link;
    }

    printf("Contact not found\n");
}
