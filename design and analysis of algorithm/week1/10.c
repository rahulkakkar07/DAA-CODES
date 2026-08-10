#include <stdio.h>

int main()
{
    float balance = 1000.0;
    float amount;

    int choice;
    int transaction[5];
    int count = 0;
    int i;

    do
    {
        printf("\n===== ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Last 5 Transactions\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("\nCurrent Balance = %.2f\n", balance);
        }

        else if(choice == 2)
        {
            printf("\nEnter amount to deposit: ");
            scanf("%f", &amount);

            if(amount > 0)
            {
                balance = balance + amount;

                printf("Money deposited successfully!\n");
                printf("New Balance = %.2f\n", balance);

                /* Store deposit */
                if(count < 5)
                {
                    transaction[count] = amount;
                    count++;
                }
                else
                {
                    for(i = 0; i < 4; i++)
                    {
                        transaction[i] = transaction[i + 1];
                    }

                    transaction[4] = amount;
                }
            }
            else
            {
                printf("Invalid amount!\n");
            }
        }

        else if(choice == 3)
        {
            printf("\nEnter amount to withdraw: ");
            scanf("%f", &amount);

            if(amount <= 0)
            {
                printf("Invalid amount!\n");
            }
            else if(amount > balance)
            {
                printf("Insufficient balance!\n");
            }
            else
            {
                balance = balance - amount;

                printf("Please collect your money.\n");
                printf("Remaining Balance = %.2f\n", balance);

                /* Store withdrawal as negative */
                if(count < 5)
                {
                    transaction[count] = -amount;
                    count++;
                }
                else
                {
                    for(i = 0; i < 4; i++)
                    {
                        transaction[i] = transaction[i + 1];
                    }

                    transaction[4] = -amount;
                }
            }
        }

        else if(choice == 4)
        {
            if(count == 0)
            {
                printf("\nNo transactions yet.\n");
            }
            else
            {
                printf("\n===== LAST 5 TRANSACTIONS =====\n");

                for(i = 0; i < count; i++)
                {
                    if(transaction[i] > 0)
                    {
                        printf("Deposited: +%d\n", transaction[i]);
                    }
                    else
                    {
                        printf("Withdrawn: %d\n", transaction[i]);
                    }
                }
            }
        }

        else if(choice == 5)
        {
            printf("\nThank you for using the ATM!\n");
        }

        else
        {
            printf("\nInvalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}