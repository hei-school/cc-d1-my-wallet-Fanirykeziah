def savings(choose,amount):
    savings = 100
    if choose == 1 : 
        print("Your current balance savings is :" + str(savings) + "Ariary")
    elif choose == 2 : 
        print("Enter money value to savings :")
        toSave = float(input())

        if toSave <= 0 : 
           print("Enter a value higher than 0,please")
        elif toSave > amount : 
           print("You don't have enough money to save, add money to your principal balance for savings.")
        else : 
            amount -= toSave 
            toSave += amount 
            print("You've saved" + str(toSave) + "Ariary")
            print("Your current total savings are :" + str(savings))
            print("Your principal balance is :" + str(amount))
