def convert_currency(choose,amount):
    count = 0
    if choose == 1: 
        count = amount / 4993.0
        print("Your current money in EURO is :" + str(round(count,1)) + "EU")
    elif choose == 2: 
        count = amount / 4582.0
        print("Your current money in EURO is :" + str(round(count,2)) + "EU")
    else :
        print("Invalid choice")        

