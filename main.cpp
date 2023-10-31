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

int main() {
    int water = 300;  // initial water amount in milliliters
    int milk = 200;   // initial milk amount in milliliters
    int coffee = 100; // initial coffee amount in grams
    double money = 0; // initial money in dollars

    const double ESPRESSO_COST = 1.50;
    const double LATTE_COST = 2.50;
    const double CAPPUCCINO_COST = 3.00;

    bool paymentSuccess = false;
    string drinkName;

    while (true) {
        cout << "===========================================================================================" << endl;
        cout << "                                   WELCOME TO BIGOO COFFE STATION                           " << endl;
        cout << "===========================================================================================\n  " << endl;
        cout << "                                   WHAT DO YOU WANT TO DO?:                           " << endl;
        cout << "                                   1. Buy a drink                                   \n  " << endl;
        cout << "                                   2. Check report                                   \n  " << endl;
        cout << "                                   3. Turn off the machine                                   \n  " << endl;
        cout <<"                                   Enter your choice:                                   \n   ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "                                   Available :                                   \n  " << endl;
            cout << "                                   1. Espresso ($1.50)                                   \n  " << endl;
            cout << "                                      ( ( )\n                                      ) )\n                                   ( ( )\n                                   (`-' )                                   \n                                     " << endl;
            cout << "                                   2. Latte ($2.50)                                   \n  " << endl;
            cout << "                                      ( ( ( )\n                                      ) ) )\n                                   ( ( ( )\n                                     `-' ) ) )                                   \n  " << endl;
            cout << "                                   3. Cappuccino ($3.00)                                   \n  " << endl;
            cout << "                                      ( ( ( )\n                                      ) ) )\n                                   ( ( ( )\n                                     `-' ) ) )                                   " << endl;
            cout << "                                   Which Coffe Favor Can We Offer You?:                                   \n   ";

            int drinkChoice;
            cin >> drinkChoice;

            double drinkCost;

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
                cout << "                                   Invalid drink choice.                                   \n  " << endl;
                continue;
            }

            cout << "                                   Select payment mode (1. Cash / 2. Credit Card / 3. Mobile Money):                                    \n  ";
            int paymentChoice;
            cin >> paymentChoice;

            paymentSuccess = false;

            if (paymentChoice == 1) {
                cout << "                                   Please insert coins ($" << fixed << setprecision(2) << drinkCost << "):                                    \n  ";
                double coinsInserted;
                cin >> coinsInserted;
                if (coinsInserted >= drinkCost) {
                    paymentSuccess = true;
                }
            }
            else if (paymentChoice == 2) {
                cout << "                                   Insert credit card and press Enter to process payment...                                   \n  " << endl;
               
                cin.ignore(); 
                cin.get();    
                paymentSuccess = true;
            }
            else if (paymentChoice == 3) {
                cout << "Enter mobile money number to process payment: " << endl;
                string number;
                cin >> number;

                cout << "                                   Confirm payment by inputing your pin as confirmation on the pop-up message on your phone                                    \n  " << endl;
                displayLoadingBar(20000);
                
                paymentSuccess = true;
                cout << "                                   Payment Successfully made...................                                   \n  " << endl;
            }
            else {
                cout << "                                   Invalid payment choice.                                   \n  " << endl;
                continue;
            }

            if (paymentSuccess) {
                cout << "                                   Preparing your " << drinkName << ". Enjoy!                                   \n  " << endl;
                displayLoadingBar(10000); 
                cout << "                                   Your Coffe is Ready Enjoy\n                                      " << endl;
                cout << "                                   Nice Seeing You at our Coffe Station\n                                     " << endl;
                cout << "\n \n   " << endl;
                money += drinkCost;
                water -= (drinkName == "Espresso" ? 50 : (drinkName == "Latte" ? 200 : 250));
                milk -= (drinkName == "Latte" ? 150 : 0);
                coffee -= (drinkName == "Espresso" ? 18 : 24);
            }
            else {
                cout << "                                   Payment failed. Please try again                                   \n  ." << endl;
            }
            break;
        }
        case 2:
            cout << "                                   Water: " << water << "ml\n" << endl;
            cout << "                                   Milk: " << milk << "ml\n" << endl;
            cout << "                                   Coffee: " << coffee << "g\n" << endl;
            cout << "\n" << endl;
            cout << "                                   Money: $" << fixed << setprecision(2) << money << endl;
            break;
        case 3:
            cout << "Turning off the Coffee Machine. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
