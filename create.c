#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

void create_contact(Contact **head)
{
    Contact *new;
    Contact *temp;
    char choice;

    new = malloc(sizeof(Contact));

    if(new == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter contact name: ");
    read_string(new->name, MAX_NAME);

    if(contact_exists(*head, new->name))
    {
        printf("Contact already exists\n");
        free(new);
        return;
    }

    new->phone_count = 0;
    new->email[0] = '\0';
    new->address[0] = '\0';

    do
    {
        if(new->phone_count == MAX_PHONES)
        {
            printf("Maximum phone numbers reached\n");
            break;
        }

        printf("Enter phone number: ");
        read_string(new->phone[new->phone_count], MAX_PHONE);

        new->phone_count++;

        printf("Do you want to add another number (Y/N): ");
        scanf(" %c", &choice);
        getchar();

    } while(choice == 'Y' || choice == 'y');

    printf("Do you want to add email (Y/N): ");
    scanf(" %c", &choice);
    getchar();

    if(choice == 'Y' || choice == 'y')
    {
        printf("Enter email: ");
        read_string(new->email, MAX_EMAIL);
    }

    printf("Do you want to add address (Y/N): ");
    scanf(" %c", &choice);
    getchar();

    if(choice == 'Y' || choice == 'y')
    {
        printf("Enter address: ");
        read_string(new->address, MAX_ADDRESS);
    }

    new->link = NULL;

    if(*head == NULL)
    {
        *head = new;
    }
    else
    {
        temp = *head;

        while(temp->link != NULL)
            temp = temp->link;

        temp->link = new;
    }

    printf("Contact created successfully\n");
}
