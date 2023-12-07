#include <stdio.h>


struct WalletMenu {
    double amount;
};

void displayMenu(struct WalletMenu *wallet);
void displayBalance(const struct WalletMenu *wallet);
void deposit(struct WalletMenu *wallet);
void withdrawal(struct WalletMenu *wallet);
void convertCurrency(const struct WalletMenu *wallet);
void savings(struct WalletMenu *wallet);

int main() {
    
    struct WalletMenu wallet = {500};
    
    displayMenu(&wallet);

    return 0;
}

void displayMenu(struct WalletMenu *wallet) {
    int action;

    printf("1. View balance\n");
    printf("2. Deposit money\n");
    printf("3. Withdrawal money\n");
    printf("4. View balance currencies\n");
    printf("5. Savings\n");

    printf("Enter your action: ");
    scanf("%d", &action);

    switch (action) {
        case 1:
            displayBalance(wallet);
            break;
        case 2:
            deposit(wallet);
            break;
        case 3:
            withdrawal(wallet);
            break;
        case 4:
            convertCurrency(wallet);
            break;
        case 5:
            savings(wallet);
            break;
        default:
            printf("Invalid choice\n");
    }
}

void displayBalance(const struct WalletMenu *wallet) {
    printf("Your current money is: %.2f Ariary\n", wallet->amount);
}

void deposit(struct WalletMenu *wallet) {
    double toAdd;

    printf("How much money you want to add: ");
    scanf("%lf", &toAdd);

    if (toAdd <= 0) {
        printf("Enter a correct value, please!\n");
    } else {
        wallet->amount += toAdd;
        printf("Adding %.2f Ariary to wallet successful\n", toAdd);
        printf("Your current money is: %.2f Ariary\n", wallet->amount);
    }
}

void withdrawal(struct WalletMenu *wallet) {
    double toTake;

    printf("Enter money value you want to take: ");
    scanf("%lf", &toTake);

    if (wallet->amount >= toTake && toTake > 0) {
        wallet->amount -= toTake;
        printf("Your withdrawal %.2f Ariary has been successfully completed\n", toTake);
        printf("Your current money is: %.2f Ariary\n", wallet->amount);
    } else if(toTake < 0){
        printf("You can't take a negative money");
    }
    else {
        printf("Invalid withdrawal amount or insufficient balance\n");
    }
}

void convertCurrency(const struct WalletMenu *wallet) {
    int choice;
    double count;

    printf("1. EU\n");
    printf("2. USD\n");

    printf("Enter your currency choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            count = wallet->amount / 4993.0;
            printf("Your current money in EURO is: %.2f EU\n", count);
            break;
        case 2:
            count = wallet->amount / 4582.0;
            printf("Your current money in USD is: %.2f USD\n", count);
            break;
        default:
            printf("Invalid currency choice\n");
    }
}

void savings(struct WalletMenu *wallet) {
    double savings = 100;
    int savingsChoice;

    printf("1. View balance savings\n");
    printf("2. Store savings\n");

    printf("Welcome to your savings account, what would you like to do? ");
    scanf("%d", &savingsChoice);

    switch (savingsChoice) {
        case 1:
            printf("Your current balance savings is: %.2f Ariary\n", savings);
            break;
        case 2: {
            double toStore;

            printf("Enter money value to savings: ");
            scanf("%lf", &toStore);

            if (toStore > 0 && toStore <= wallet->amount) {
                wallet->amount -= toStore;
                savings += toStore;
                printf("You've saved %.2f Ariary\n", toStore);
                printf("Your current total savings are: %.2f Ariary\n", savings);
                printf("Your principal balance is: %.2f Ariary\n", wallet->amount);
            } else {
                printf("Invalid savings amount or insufficient balance\n");
            }
            break;
        }
        default:
            printf("Invalid choice\n");
    }
}
