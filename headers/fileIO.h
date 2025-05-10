#ifndef FILEIO_H
#define FILEIO_H

#include "../headers/account.h"

Account* loadAccounts(int *size);
void saveAccounts(Account *account, int size);

#endif