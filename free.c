#include <stdlib.h>
#include "contact.h"

void free_contacts(Contact **head)
{
    Contact *temp;

    while(*head != NULL)
    {
        temp = *head;
        *head = (*head)->link;
        free(temp);
    }
}
