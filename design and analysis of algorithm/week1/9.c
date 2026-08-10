#include <stdio.h>

struct Book
{
    int id;
    char title[50];
    char author[50];
    int totalCopies;
    int availableCopies;
};

int main()
{
    struct Book b[100];

    int count = 0;
    int choice;
    int id;
    int i;
    int found;

    do
    {
        printf("\n\n===== LIBRARY MENU =====\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Display Unavailable Books\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            if(count >= 100)
            {
                printf("Library is full!\n");
            }
            else
            {
                printf("\nEnter Book ID: ");
                scanf("%d", &b[count].id);

                printf("Enter Book Title: ");
                scanf(" %[^\n]", b[count].title);

                printf("Enter Author Name: ");
                scanf(" %[^\n]", b[count].author);

                printf("Enter Total Copies: ");
                scanf("%d", &b[count].totalCopies);

                b[count].availableCopies = b[count].totalCopies;

                count++;

                printf("Book added successfully!\n");
            }
        }

        else if(choice == 2)
        {
            printf("\nEnter Book ID to search: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < count; i++)
            {
                if(b[i].id == id)
                {
                    printf("\nBook Found!\n");
                    printf("Book ID: %d\n", b[i].id);
                    printf("Title: %s\n", b[i].title);
                    printf("Author: %s\n", b[i].author);
                    printf("Total Copies: %d\n", b[i].totalCopies);
                    printf("Available Copies: %d\n", b[i].availableCopies);

                    found = 1;
                    break;
                }
            }

            if(found == 0)
            {
                printf("Book not found!\n");
            }
        }

        else if(choice == 3)
        {
            printf("\nEnter Book ID to issue: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < count; i++)
            {
                if(b[i].id == id)
                {
                    found = 1;

                    if(b[i].availableCopies > 0)
                    {
                        b[i].availableCopies--;

                        printf("Book issued successfully!\n");
                        printf("Available copies: %d\n",
                               b[i].availableCopies);
                    }
                    else
                    {
                        printf("Book is not available!\n");
                    }

                    break;
                }
            }

            if(found == 0)
            {
                printf("Book not found!\n");
            }
        }

        else if(choice == 4)
        {
            printf("\nEnter Book ID to return: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < count; i++)
            {
                if(b[i].id == id)
                {
                    found = 1;

                    if(b[i].availableCopies < b[i].totalCopies)
                    {
                        b[i].availableCopies++;

                        printf("Book returned successfully!\n");
                        printf("Available copies: %d\n",
                               b[i].availableCopies);
                    }
                    else
                    {
                        printf("All copies are already in the library!\n");
                    }

                    break;
                }
            }

            if(found == 0)
            {
                printf("Book not found!\n");
            }
        }

        else if(choice == 5)
        {
            found = 0;

            printf("\n===== UNAVAILABLE BOOKS =====\n");

            for(i = 0; i < count; i++)
            {
                if(b[i].availableCopies == 0)
                {
                    printf("\nBook ID: %d\n", b[i].id);
                    printf("Title: %s\n", b[i].title);
                    printf("Author: %s\n", b[i].author);

                    found = 1;
                }
            }

            if(found == 0)
            {
                printf("No books are currently unavailable.\n");
            }
        }

        else if(choice == 6)
        {
            printf("\nThank you for using the library system!\n");
        }

        else
        {
            printf("\nInvalid choice!\n");
        }

    } while(choice != 6);

    return 0;
}