#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct {
    int accountNumber;
    int pin;
    char name[50];
    float balance;
} Account;

#endif