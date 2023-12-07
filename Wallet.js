const prompt = require("prompt-sync")();

  let amount = 500;
  let action;

  console.log("1. View balance");
  console.log("2. Deposit money");
  console.log("3. Withdrawal money");
  console.log("4. View balance currencies");
  console.log("5. Savings");

  action = parseInt(prompt("Enter your action: "));

  switch (action) {
    case 1:
      console.log("Your current money is: " + amount + " Ariary");
      break;
    case 2:
      const toAdd = parseFloat(prompt("How much money you want to add: "));

      if (toAdd <= 0 || isNaN(toAdd)) {
        console.log("Enter a correct value, please!");
      } 
      else {
        amount += toAdd;
        console.log("Adding " + toAdd + " Ariary to wallet successful");
        console.log("Your current money is: " + amount);
      }
      break;

    case 3:
      const toTake = parseFloat(prompt("Enter money value you want to take: "));

      if (amount >= toTake) {
        amount -= toTake;
        console.log("Your withdrawal " + toTake + " Ariary has been successfully completed");
        console.log("Your current money is: " + amount);
      }
      else {
        console.log("You don't have enough balance to make this withdrawal");
      }
      break;

    case 4:
      console.log("1. EU");
      console.log("2. USD");
      const choose = parseInt(prompt("Enter your currency choice: "));

      let count;

      switch (choose) {
        case 1:
          count = amount / 4993.0;
          const formattedNumberEU = count.toFixed(1);
          console.log("Your current money in EURO is: " + formattedNumberEU + " EU");
          break;

        case 2:
          count = amount / 4582.0;
          const formattedNumberUSD = count.toFixed(2);
          console.log("Your current money in USD is: " + formattedNumberUSD + " USD");
          break;

        default:
        console.log("Invalid choice");
      }
      break;

    case 5:
      let savings = 100;

      console.log("1. View balance savings");
      console.log("2. Store savings");

      const choice = parseInt(prompt("Welcome to your savings account, what would you like to do? "));

      switch (choice) {
        case 1:
          console.log("Your current balance savings is: " + savings + " Ariary");
          break;
        
        case 2:
          const toStore = parseFloat(prompt("Enter money value to savings: "));

          if (toStore <= 0 || isNaN(toStore)) {
            console.log("Enter a value higher than 0, please");
          } 
          else if (toStore > amount) {
            console.log("You don't have enough money to save, add money to your principal balance for savings.");
          }
          else {
            amount -= toStore;
            savings += toStore;
            console.log("You've saved " + toStore + " Ariary");
            console.log("Your current total savings are: " + savings);
            console.log("Your principal balance is: " + amount);
          }
          break;

        default:
          console.log("Invalid action");
      }
}
