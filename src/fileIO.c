#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/account.h"

Account* loadAccounts(int *size) {
    FILE *file = fopen("../data/accounts.txt", "r");
    if (!file) {
        *size = 0;
        return NULL;
    }

    Account *accounts = NULL;
    int count = 0;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        Account acc;
        
        if (sscanf(line, "%d %d %49[^,] %f", 
            &acc.accountNumber, 
            &acc.pin, 
            acc.name, 
            &acc.balance) == 4) {
            
            accounts = realloc(accounts, (count + 1) * sizeof(Account));
            accounts[count] = acc;
            count++;
        }
    } 

    // Close the file
    fclose(file);
    *size = count;
    return accounts;
}

void saveAccounts(Account *account, int size) {
    
    FILE *file = fopen("../data/accounts.txt", "w");
    
    if (!file) {
        printf("Error saving data.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d %d %s %2f\n", 
            account[i].accountNumber, 
            account[i].pin, 
            account[i].name,
            account[i].balance
        );
    }

    fclose(file);
    printf("Data saved successfully.\n");
}