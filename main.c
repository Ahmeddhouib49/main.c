#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} BankAccount;
void createNewAccount(BankAccount *accounts, int *numAccounts);
void updateAccount(BankAccount *accounts, int numAccounts);
void deleteAccount(BankAccount *accounts, int *numAccounts);
void displayAccountDetails(BankAccount *accounts, int numAccounts);
void displayClientList(BankAccount *accounts, int numAccounts);
void transferMoney(BankAccount *accounts, int numAccounts);

int main() {
    BankAccount accounts[100];
    int numAccounts = 0;
    accounts[numAccounts].accountNumber = 1001;
    strcpy(accounts[numAccounts].name, "John Doe");
    accounts[numAccounts].balance = 5000.0;
    numAccounts++;

    int choice;
    do {
        printf("\nMain Menu:\n");
        printf("1. Create a new account\n");
        printf("2. Update account information\n");
        printf("3. Display and manage bank transactions\n");
        printf("4. Delete an account\n");
        printf("5. Display account details\n");
        printf("6. Display client list\n");
        printf("7. Transfer money between accounts\n");
        printf("0. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createNewAccount(accounts, &numAccounts);
                break;
            case 2:
                updateAccount(accounts, numAccounts);
                break;
            case 3:
                break;
            case 4:
                deleteAccount(accounts, &numAccounts);
                break;
            case 5:
                displayAccountDetails(accounts, numAccounts);
                break;
            case 6:
                displayClientList(accounts, numAccounts);
                break;
            case 7:
                transferMoney(accounts, numAccounts);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void createNewAccount(BankAccount *accounts, int *numAccounts) {
    if (*numAccounts >= 100) {
        printf("Maximum number of accounts reached. Cannot create a new account.\n");
        return;
    }

    printf("Account number: ");
    scanf("%d", &accounts[*numAccounts].accountNumber);

    for (int i = 0; i < *numAccounts; i++) {
        if (accounts[i].accountNumber == accounts[*numAccounts].accountNumber) {
            printf("This account number is already in use. Please choose another number.\n");
            return;
        }
    }

    printf("Account holder's name: ");
    scanf("%s", accounts[*numAccounts].name);

    printf("Initial balance: ");
    scanf("%f", &accounts[*numAccounts].balance);

    (*numAccounts)++;
    printf("New account created successfully!\n");
}

void updateAccount(BankAccount *accounts, int numAccounts) {
    int accountNum;
    printf("Enter account number to update: ");
    scanf("%d", &accountNum);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNum) {
            printf("New balance: ");
            scanf("%f", &accounts[i].balance);
            printf("Account information updated successfully!\n");
            return;
        }
    }

    printf("Account not found.\n");
}

void deleteAccount(BankAccount *accounts, int *numAccounts) {
    int accountNum;
    printf("Enter account number to delete: ");
    scanf("%d", &accountNum);

    for (int i = 0; i < *numAccounts; i++) {
        if (accounts[i].accountNumber == accountNum) {
            for (int j = i; j < *numAccounts - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            (*numAccounts)--;
            printf("Account deleted successfully!\n");
            return;
        }
    }

    printf("Account not found.\n");
}

void displayAccountDetails(BankAccount *accounts, int numAccounts) {
    int accountNum;
    printf("Enter account number: ");
    scanf("%d", &accountNum);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNum) {
            printf("Account Details:\n");
            printf("Account number: %d\n", accounts[i].accountNumber);
            printf("Account holder: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void displayClientList(BankAccount *accounts, int numAccounts) {
    printf("Client List:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("%d. %s\n", accounts[i].accountNumber, accounts[i].name);
    }
}

void transferMoney(BankAccount *accounts, int numAccounts) {
    int source, destination;
    float amount;

    printf("Source account number: ");
    scanf("%d", &source);

    printf("Destination account number: ");
    scanf("%d", &destination);

    printf("Amount to transfer: ");
    scanf("%f", &amount);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == source) {
            for (int j = 0; j < numAccounts; j++) {
                if (accounts[j].accountNumber == destination) {
                    if (accounts[i].balance >= amount) {
                        accounts[i].balance -= amount;
                        accounts[j].balance += amount;
                        printf("Transfer successful!\n");
                        return;
                    } else {
                        printf("Insufficient balance for transfer.\n");
                        return;
                    }
                }
            }
        }
    }

    printf("Source or destination account not found.\n");
}
