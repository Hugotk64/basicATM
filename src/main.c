#include <stdio.h>
#include <stdlib.h>

#include "../headers/account.h"
#include "../headers/fileIO.h"
#include "../headers/menu.h"

int main() {
    Account *accounts = NULL;
    int accountCount = 0;
    accounts = loadAccounts(&accountCount);

    // Declare variables and menu options
    int choice;
    do
    {
        printf("==== HNB ATM ====\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear the input buffer

        switch (choice)
        {
        case 1:
            createAccount(&accounts, &accountCount);
            break;
        
        case 2:
            int accNumber;
            int pin;

            printf("Enter account number: ");
            scanf("%d", &accNumber);

            printf("Enter PIN: ");
            scanf("%d", &pin);

            while (getchar() != '\n'); // Clear the input buffer

            Account *user = login(accounts, accountCount, accNumber, pin);

            if (user)
            {
                printf("welcome %s %s\n", user->name);
                accountMenu(user, accounts, accountCount);
            } else {
                printf("Invalid account number or PIN.\n");
            }

            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
        
    } while (choice != 3);

    // Free allocated memory
    free(accounts);
    return 0;
}

