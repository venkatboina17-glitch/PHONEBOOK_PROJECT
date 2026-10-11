#include <stdio.h>
#include <string.h>
#include "contact.h"

void edit_contact(Contact *head)
{
    Contact *temp = head;
    char name[MAX_NAME];
    char new_name[MAX_NAME];
    
    
    int option;
    int i;

    printf("Enter contact name to edit: ");
    read_string(name, MAX_NAME);

    while(temp != NULL)
    {
        if(strcmp(temp->name, name) == 0)
        {
            while(1)
            {
                printf("\n---------- EDIT MENU ----------\n");
                printf("1. Edit name\n");
                printf("2. Edit phone number\n");
                printf("3. Add phone number\n");
                printf("4. Edit email\n");
                printf("5. Edit address\n");
                printf("6. Exit edit\n");

                printf("Enter choice: ");
                scanf("%d", &option);
                getchar();

                switch(option)
                {
                    case 1:
                        printf("Enter new name: ");
                        read_string(new_name, MAX_NAME);

                        if(strcmp(new_name, temp->name) != 0 &&
                           contact_exists(head, new_name))
                        {
                            printf("Another contact with this name already exists\n");
                        }
                        else
                        {
                            strcpy(temp->name, new_name);
                            printf("Name updated\n");
                        }
                        break;

                    case 2:
                        if(temp->phone_count == 0)
                        {
                            printf("No phone numbers available\n");
                            break;
                        }

                        printf("Phone numbers:\n");

                        for(i = 0; i < temp->phone_count; i++)
                            printf("%d. %s\n", i + 1, temp->phone[i]);

                        printf("Select phone number: ");
                        scanf("%d", &i);
                        getchar();

                        if(i < 1 || i > temp->phone_count)
                        {
                            printf("Invalid phone number\n");
                            break;
                        }

                        printf("Enter new phone number: ");
                        read_string(temp->phone[i - 1], MAX_PHONE);

                        printf("Phone number updated\n");
                        break;

                    case 3:
                        if(temp->phone_count == MAX_PHONES)
                        {
                            printf("Maximum phone numbers reached\n");
                            break;
                        }

                        printf("Enter new phone number: ");
                        read_string(temp->phone[temp->phone_count],
                                    MAX_PHONE);

                        temp->phone_count++;

                        printf("Phone number added\n");
                        break;

                    case 4:
                        printf("Enter new email: ");
                        read_string(temp->email, MAX_EMAIL);

                        printf("Email updated\n");
                        break;

                    case 5:
                        printf("Enter new address: ");
                        read_string(temp->address, MAX_ADDRESS);

                        printf("Address updated\n");
                        break;

                    case 6:
                        return;

                    default:
                        printf("Invalid choice\n");
                }
            }
        }

        temp = temp->link;
    }

    printf("Contact not found\n");
}
