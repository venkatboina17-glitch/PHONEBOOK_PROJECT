#include <stdio.h>
#include "contact.h"

void print_contacts(Contact *head)
{
    Contact *temp = head;
    int i;

    if(temp == NULL)
    {
        printf("Phone book is empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("\n-----------------------------\n");
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

        temp = temp->link;
    }

    printf("-----------------------------\n");
}
