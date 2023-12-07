def deposit(amount):
    print("How much money you want to add :")
    toAdd = float(input())

    if toAdd <= 0:
        print("Enter a correct value,please!")
    else : 
        amount += toAdd 
        print("Adding " + str(toAdd) + "Ariary to wallet successful")
        print("Your current money is :" + str(amount))