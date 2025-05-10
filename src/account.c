#include <stdio.h>
#include <stdlib.h>

#include "../headers/account.h"
#include "../headers/fileIO.h"

int generateAccountNumber(Account *account, int size) {
    int accountNumber;
    
    do
    {
        // Generate a random account number between 100000 and 999999
        accountNumber = 100000 + rand() % 900000;

        // Check if the account number already exists
        for (int i = 0; i < size; i++) {
            if (account[i].accountNumber == accountNumber) {
                accountNumber = 0;
                break;
            }
        }

    } while (accountNumber == 0);
    return accountNumber;
}

void createAccount(Account **accounts, int *size) {
    Account newAccount;
    newAccount.accountNumber = generateAccountNumber(accounts, size);

    printf("Enter your name: ");
    fgets(newAccount.name, sizeof(newAccount.name), stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0; // Remove newline character

    printf("Enter your PIN: ");
    scanf("%d", &newAccount.pin);
    while (getchar() != '\n'); // Clear the input buffer

    newAccount.balance = 0.0;

    *accounts = realloc(*accounts, (*size + 1) * sizeof(Account));
    (*accounts)[*size] = newAccount;
    (*size)++;

    saveAccounts(*accounts, *size);
    printf("Account created successfully!\n");
    printf("Your account number is: %d\n", newAccount.accountNumber);
}

Account* login(Account *accounts, int size, int accNumber, int pin) {
    // Check if the account number and PIN match any existing account
    for (int i = 0; i < size; i++) {
        if (accounts[i].accountNumber == accNumber && accounts[i].pin == pin) {
            return &accounts[i];
        }
    }
    return NULL;
}