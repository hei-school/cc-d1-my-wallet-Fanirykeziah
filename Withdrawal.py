def withdrawal(amount):
    print("How much money you want to take :")
    toTake = float(input())

    if amount > toTake:
        amount -= toTake
        print("Adding " + str(toTake) + "Ariary to wallet successful")
        print("Your current money is :" + str(amount))

    elif amount <= 0:
        print("Enter a value higher than 0")    

    else : 
        amount += toTake 
        print("Your withdrawal " + str(toTake) + "Ariary has been successfully completed")
        print("Your current money is :" + str(amount))