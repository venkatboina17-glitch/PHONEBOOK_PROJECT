#include <stdio.h>
#include <string.h>
#include "contact.h"

void find_contact(Contact *head)
{
    Contact *temp = head;
    char name[MAX_NAME];
    int i;

    printf("Enter contact name to find: ");
    read_string(name, MAX_NAME);

    while(temp != NULL)
    {
        if(strcmp(temp->name, name) == 0)
        {
            printf("\nContact found\n");
            printf("-----------------------------\n");
            printf("Name    : %s\n", temp->name);

            for(i = 0; i < temp->phone_count; i++)
                printf("Phone %d : %s\n", i + 1, temp->phone[i]);

            if(temp->email[0] != '\0')
                printf("Email   : %s\n", temp->email);
            else
                printf("Email   : Not available\n");

            if(temp->address[0] != '\0')
                printf("Address : %s\n", temp->address);
            else
                printf("Address : Not available\n");

            return;
        }

        temp = temp->link;
    }

    printf("Contact not found\n");
}
