#include <stdio.h>

#include "../headers/account.h"
#include "../headers/fileIO.h"

void accountMenu(Account *account, Account *accounts, int size) {
    int choice; 
    do {
        printf("==== HNB ATM ====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Logout\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear the input buffer
        switch (choice) {
            case 1:
                printf("Your balance is: %.2f\n", account->balance);
                break;
            case 2:
                float amount;
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                while (getchar() != '\n'); // Clear the input buffer

                if (amount > 0) {
                    account->balance += amount;
                    saveAccounts(accounts, size);
                    printf("New balance: %.2f\n", account->balance);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;
            case 3:
                float amount;
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                while (getchar() != '\n'); // Clear the input buffer

                if (amount > 0 && amount <= account->balance) {
                    account->balance -= amount;
                    saveAccounts(accounts, size);
                    printf("New balance: %.2f\n", account->balance);
                } else {
                    printf("Invalid withdrawal amount.\n");
                }

                break;
            case 4:
                printf("Logging out...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}