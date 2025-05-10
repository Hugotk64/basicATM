#include <stdio.h>

#include "../headers/account.h"

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