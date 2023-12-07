from Deposit import deposit;
from Withdrawal import withdrawal;
from Convertion import convert_currency;
from Savings import savings;

def display_balance(amount):
    print("Your current money is :" + str(amount) + "Ariary")

def main(action):
    amount = 500.0

    if action == 1: 
        display_balance(amount)

    elif action == 2: 
        deposit(amount)

    elif action == 3:
        withdrawal(amount)

    elif action == 4:
        print('1. EU')
        print('2. USD')
        print('Enter your choice:')
        choose = int(input())
        convert_currency(choose,amount)

    elif action == 5:
        print("1. View balance savings")
        print("2. Store savings")
        print('Enter your choice:')

        choose = int(input())
        savings(choose,amount)

    else :
        print("Invalid choice.")        


print('1. View balance')
print('2. Deposit money')
print('3. Withdrawal money')
print('4. View balance currencies')
print('5. Savings')
print('Enter your choice:')
action = input()
main(int(action))