#include <stdio.h>
#include <string.h>
#include "contact.h"

void read_string(char *str, int size)
{
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int contact_exists(Contact *head, char *name)
{
    Contact *temp = head;

    while(temp != NULL)
    {
        if(strcmp(temp->name, name) == 0)
            return 1;

        temp = temp->link;
    }

    return 0;
}
