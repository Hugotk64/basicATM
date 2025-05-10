#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct {
    int accountNumber;
    int pin;
    char name[50];
    float balance;
} Account;

int generateAccountNumber(Account *account, int size);
void createAccount(Account **accounts, int *size);
Account* login(Account *accounts, int size, int accNumber, int pin);

#endif