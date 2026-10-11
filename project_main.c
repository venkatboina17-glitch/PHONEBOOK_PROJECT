#include <stdio.h>
#include "contact.h"

int main()
{
    Contact *head = NULL;
    char choice;

    load_contacts(&head);

    while(1)
    {
        printf("\n");
        printf("------------------MENU------------------\n");
        printf("c/C: Create a new contact\n");
        printf("p/P: Print all contacts\n");
        printf("d/D: Delete contact\n");
        printf("f/F: Find contact\n");
        printf("e/E: Edit a contact\n");
        printf("s/S: Save the contacts in the file\n");
        printf("q/Q: Quit from app\n");
        printf("-----------------------------------------\n");

        printf("Enter choice: ");
        scanf(" %c", &choice);
        getchar();

        switch(choice)
        {
            case 'c':
            case 'C':
                create_contact(&head);
                break;

            case 'p':
            case 'P':
                print_contacts(head);
                break;

            case 'd':
            case 'D':
                delete_contact(&head);
                break;

            case 'f':
            case 'F':
                find_contact(head);
                break;

            case 'e':
            case 'E':
                edit_contact(head);
                break;

            case 's':
            case 'S':
                save_contacts(head);
                break;

            case 'q':
            case 'Q':
                free_contacts(&head);
                printf("Exiting phone book...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
