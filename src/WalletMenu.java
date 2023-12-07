import java.util.Scanner;

public class WalletMenu {
    double amount = 500;

    public void displayMenu(){
        Scanner scanner = new Scanner(System.in);
        int action;

        System.out.println("1. View balance");
        System.out.println("2. Deposit money");
        System.out.println("3. Withdrawal money");
        System.out.println("4. View balance currencies");
        System.out.println("5. Savings");

        System.out.println("Enter your action : ");
        action = scanner.nextInt();

        switch (action) {
            case 1 -> displayBalance();
            case 2 -> deposit();
            case 3 -> withdrawal();
            case 4 -> convertCurrency();
            case 5 -> savings();
        }
    }

    private void displayBalance(){
        System.out.println("Your current money is :" + amount + "Ariary");
    }

    private void deposit(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("How much money you want to add :");
        double toAdd = scanner.nextDouble();

        if( toAdd <= 0 ) {
            System.out.println("Enter a correct value,please!");
        }
        else {
            amount += toAdd;
            System.out.println("Adding " + toAdd + "Ariary to wallet successful");
            System.out.println( "Your current money is :" + amount );
        }
    }

    private void withdrawal(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter money value you want taking : ");
        double toTake = scanner.nextDouble();

        if( amount > toTake){
            amount -= toTake;
            System.out.println("Your withdrawal " + toTake + "Ariary has been successfully completed");
            System.out.println("Your current money is : " + amount);
        }

        else {
            System.out.println("You don't have enough balance to make this withdrawal");
        }
    }

    private void convertCurrency(){
        System.out.println("1. EU");
        System.out.println("2. USD");
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter your currency choice");
        double count;

        switch (scanner.nextInt()) {
            case 1 -> {
                count = amount / 4993.0;
                double formattedNumberEU = Math.round(count * 100.0) / 100.0;
                System.out.println("Your current money in EURO is :" + formattedNumberEU + "EU");
            }
            case 2 -> {
                count = amount / 4582.0;
                double formattedNumberUSD = Math.round(count * 100.0) / 100.0;
                System.out.println("Your current money in EURO is :" + formattedNumberUSD + "USD");
            }
        }
    }

    private void savings(){
        double savings = 100;
        System.out.println("1. View balance savings");
        System.out.println("2. Store savings");
        Scanner scanner = new Scanner(System.in);
        System.out.println("Welcome to your savings account, what would you like to do?");

        switch (scanner.nextInt()) {
            case 1 -> System.out.println("Your current balance savings is :" + savings + "Ariary");
            case 2 -> {
                Scanner scannerToStore = new Scanner(System.in);
                System.out.println("Enter money value to savings :");
                double toStore = scannerToStore.nextDouble();
                if (toStore <= 0) {
                    System.out.println("Enter a value higher than 0,please");
                } else if (toStore > amount) {
                    System.out.println("You don't have enough money to save, add money to your principal balance for savings.");
                } else {
                    amount -= toStore;
                    savings += toStore;
                    System.out.println("You've saved" + toStore + "Ariary");
                    System.out.println("Your current total savings are :" + savings);
                    System.out.println("Your principal balance is :" + amount);
                }
            }
        }
    }
}
