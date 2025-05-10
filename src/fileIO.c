#include <stdio.h>

#include "../headers/account.h"

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