#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void displayLoadingBar(int duration) {
    int progress = 0;
    int totalBars = 50;
    for (int i = 0; i < totalBars; ++i) {
        progress = (i * 100) / totalBars;
        cout << "[";
        for (int j = 0; j < i; ++j) {
            cout << "=";
        }
        for (int j = i; j < totalBars - 1; ++j) {
            cout << " ";
        }
        cout << "] " << progress << "%" << "\r";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(duration / totalBars));
    }
    cout << endl;
}

void printReceipt(string drinkName, double drinkCost, double change, double tipAmount) {
    cout << "==================================== RECEIPT ====================================" << endl;
    cout << "ITEM PURCHASED: " << drinkName << endl;
    cout << "PRICE: $" << fixed << setprecision(2) << drinkCost << endl;
    cout << "TIP: $" << fixed << setprecision(2) << tipAmount << endl;
    cout << "TOTAL PAID: $" << fixed << setprecision(2) << (drinkCost + tipAmount) << endl;
    cout << "CHANGE: $" << fixed << setprecision(2) << change << endl;
    cout << "=================================================================================" << endl;
}

int main() {
    int water = 300;  // initial water amount in milliliters
    int milk = 200;   // initial milk amount in milliliters
    int coffee = 100; // initial coffee amount in grams
    double money = 0; // initial money in dollars

    const double ESPRESSO_COST = 1.50;
    const double LATTE_COST = 2.50;
    const double CAPPUCCINO_COST = 3.00;

    while (true) {
        cout << "===========================================================================================" << endl;
        cout << "                                   WELCOME TO BIGOO COFFEE STATION                           " << endl;
        cout << "===========================================================================================" << endl;
        cout << "                                   WHAT DO YOU WANT TO DO?:                                " << endl;
        cout << "                                   1. Buy a drink                                        " << endl;
        cout << "                                   2. Check report                                       " << endl;
        cout << "                                   3. Turn off the machine                                " << endl;
        cout << "                                   Enter your choice:                                     ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "                                   Available Drinks:                                   " << endl;
            cout << "                                   1. Espresso ($1.50)                                   " << endl;
            cout << "                                      ( ( )\n                                      ) )\n                                   ( ( )\n                                   (`-' )                                   " << endl;
            cout << "                                   2. Latte ($2.50)                                   " << endl;
            cout << "                                      ( ( ( )\n                                      ) ) )\n                                   ( ( ( )\n                                     `-' ) ) )                                   " << endl;
            cout << "                                   3. Cappuccino ($3.00)                                   " << endl;
            cout << "                                      ( ( ( )\n                                      ) ) )\n                                   ( ( ( )\n                                     `-' ) ) )                                   " << endl;
            cout << "                                   Which Coffee Flavor Can We Offer You?:               ";

            int drinkChoice;
            cin >> drinkChoice;

            double drinkCost;
            string drinkName;

            switch (drinkChoice) {
            case 1:
                drinkName = "Espresso";
                drinkCost = ESPRESSO_COST;
                break;
            case 2:
                drinkName = "Latte";
                drinkCost = LATTE_COST;
                break;
            case 3:
                drinkName = "Cappuccino";
                drinkCost = CAPPUCCINO_COST;
                break;
            default:
                cout << "                                   Invalid drink choice.                                " << endl;
                continue;
            }

            cout << "                                   Please insert coins ($" << fixed << setprecision(2) << drinkCost << "): ";
            double coinsInserted;
            cin >> coinsInserted;

            // Handle overpaid cash and tipping
            double change = coinsInserted - drinkCost;
            double tipAmount = 0;

            if (change >= 0) {
                cout << "                                   Would you like to leave a tip? (1. Yes / 2. No): ";
                int tipChoice;
                cin >> tipChoice;
                if (tipChoice == 1) {
                    cout << "                                   Enter tip amount: $";
                    cin >> tipAmount;
                    if (tipAmount > change) {
                        cout << "                                   Invalid tip amount. Tip cannot exceed the change.                     " << endl;
                        continue;
                    }
                    change -= tipAmount;
                }

                // Prepare the receipt
                printReceipt(drinkName, drinkCost, change, tipAmount);
            }
            else {
                cout << "                                   Insufficient payment. Please try again.                       " << endl;
                break;
            }

            // Check if there are sufficient resources to make the drink
            if ((drinkName == "Espresso" && water < 50) ||
                (drinkName == "Latte" && (water < 200 || milk < 150)) ||
                (drinkName == "Cappuccino" && (water < 250 || milk < 150 || coffee < 24))) {
                cout << "                                   Insufficient resources to make " << drinkName << ". Please choose another drink.                                   " << endl;
                break;
            }

            // Prepare the drink
            cout << "                                   Preparing your " << drinkName << ". Enjoy!                " << endl;
            displayLoadingBar(10000);
            cout << "                                   Your Coffee is Ready! Enjoy your " << drinkName << ".            " << endl;
            cout << "                                   Nice Seeing You at our Coffee Station.                   " << endl;
            money += (drinkCost + tipAmount);
            water -= (drinkName == "Espresso" ? 50 : (drinkName == "Latte" ? 200 : 250));
            milk -= (drinkName == "Latte" ? 150 : 0);
            coffee -= (drinkName == "Espresso" ? 18 : 24);

            break;
        }
        case 2:
            cout << "                                   Water: " << water << "ml\n" << endl;
            cout << "                                   Milk: " << milk << "ml\n" << endl;
            cout << "                                   Coffee: " << coffee << "g\n" << endl;
            cout << "                                   Money: $" << fixed << setprecision(2) << money << endl;
            break;
        case 3:
            cout << "                                   Turning off the Coffee Machine. Goodbye!               " << endl;
            return 0;
        default:
            cout << "                                   Invalid choice. Please try again.                        " << endl;
        }
    }

    return 0;
}
