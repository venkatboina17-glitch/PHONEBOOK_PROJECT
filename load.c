#include <stdio.h>
#include <stdlib.h>
#include "contact.h"
#include<string.h>

void load_contacts(Contact **head)
{
    FILE *fp;
    Contact *new;
    Contact *temp;
    int i;

    fp = fopen(FILE_NAME, "r");

    if(fp == NULL)
        return;

    while(1)
    {
        new = malloc(sizeof(Contact));

        if(new == NULL)
        {
            fclose(fp);
            return;
        }

        if(fgets(new->name, MAX_NAME, fp) == NULL)
        {
            free(new);
            break;
        }

        new->name[strcspn(new->name, "\n")] = '\0';

        if(fscanf(fp, "%d\n", &new->phone_count) != 1)
        {
            free(new);
            break;
        }

        for(i = 0; i < new->phone_count; i++)
        {
            fgets(new->phone[i], MAX_PHONE, fp);
            new->phone[i][strcspn(new->phone[i], "\n")] = '\0';
        }

        fgets(new->email, MAX_EMAIL, fp);
        new->email[strcspn(new->email, "\n")] = '\0';

        fgets(new->address, MAX_ADDRESS, fp);
        new->address[strcspn(new->address, "\n")] = '\0';

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
    }

    fclose(fp);
}
