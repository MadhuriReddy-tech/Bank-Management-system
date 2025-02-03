#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold account details
struct Account {
    int accountNumber;
    char name[100];
    float balance;
};

// Global array of accounts
struct Account accounts[100];
int accountCount = 0;

// Function to create a new account
void createAccount() {
    printf("Enter account number: ");
    scanf("%d", &accounts[accountCount].accountNumber);
    printf("Enter account holder's name: ");
    scanf(" %[^\n]", accounts[accountCount].name);
    accounts[accountCount].balance = 0.0;  // Initial balance set to zero
    printf("Account created successfully!\n");
    accountCount++;
}

// Function to deposit money
void depositMoney() {
    int accNum, i;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    for (i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount > 0) {
                accounts[i].balance += amount;
                printf("Amount deposited successfully! New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Invalid amount!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to withdraw money
void withdrawMoney() {
    int accNum, i;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    for (i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > 0 && amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("Amount withdrawn successfully! New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance or invalid amount!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to check balance
void checkBalance() {
    int accNum, i;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    for (i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Account Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to display account details
void displayAccounts() {
    if (accountCount == 0) {
        printf("No accounts available!\n");
        return;
    }
    printf("\n--- Account Details ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Account Holder: %s\n", accounts[i].name);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("----------------------\n");
    }
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\n--- Bank Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: checkBalance(); break;
            case 5: displayAccounts(); break;
            case 6: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
