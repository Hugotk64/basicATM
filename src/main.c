#include <stdio.h>

int main() {
    
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
    } while (choice != 3);
    
}

