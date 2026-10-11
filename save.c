#include <stdio.h>
#include "contact.h"

void save_contacts(Contact *head)
{
    FILE *fp;
    Contact *temp;
    int i;

    fp = fopen(FILE_NAME, "w");

    if(fp == NULL)
    {
        printf("File opening failed\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        fprintf(fp, "%s\n", temp->name);
        fprintf(fp, "%d\n", temp->phone_count);

        for(i = 0; i < temp->phone_count; i++)
            fprintf(fp, "%s\n", temp->phone[i]);

        fprintf(fp, "%s\n", temp->email);
        fprintf(fp, "%s\n", temp->address);

        temp = temp->link;
    }

    fclose(fp);

    printf("Contacts saved successfully\n");
}
