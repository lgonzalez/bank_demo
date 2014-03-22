#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class UserBank {
private:
    const string menu = "[H]ome [D]eposit [B]alance [W]ithdrawal [E]xit";
    static int const MAX_LIMIT = 10000;
    enum {HOME='H', DEPOSIT='D', BALANCE='B', WITHDRAWAL='W', EXIT='E'};
    char userOption;

protected:
    static const int MAX_TRIES = 3;
    int userBalance = 5000;
    const string triesMsg = "You exceeded the number of tries";

public:
    // Clears screen and prints main menu
    void showMenu () {
        system("clear");
        cout << menu << endl;
    }

    // Reads user input and validates it
    void readSelection () {
        static int count = 1;
        cin >> userOption;
        switch (userOption) {
        case HOME:
            showMenu();
            readSelection();
            break;
        case DEPOSIT:
        case BALANCE:
        case WITHDRAWAL:
            break;
        case EXIT:
            return;
        default:
            if (count >= MAX_TRIES) {
                cout << triesMsg << endl;
                break;
            }
            cout << "Unknown option, please try again" << endl;
            count++;
            readSelection();
        }
    }

    char getSelection() { return userOption; }

};

class UserBalance: public UserBank {
private:
    const string balanceMsg = "Your current account balance is: ";

public:
    int getBalance() { return userBalance; }
    void printBalance() { cout << balanceMsg << userBalance << endl; }
};

class Deposit: public UserBank {
private:
    const string enterMsg = "Enter the amount to deposit";
    const string maxMsg = "You exceeded the allowed limit: ";
    static const int MAX_LIMIT = 10000;
    int amount = 0;

public:
    void addAmount() { userBalance += amount; }
    void readAmount() {
        static int count = 1;
        cout << enterMsg << endl;
        cin >> amount;
        if (amount > MAX_LIMIT) { // Try again if max amount is exceeded
            cout << maxMsg << MAX_LIMIT << endl;
            if (count >= MAX_TRIES) {
                cout << triesMsg << endl;
                return;
            }
            count++;
            readAmount();
        }
    }
};

class Withdrawal: public UserBank {
private:
    int billDenom[4] = {0, 0, 0, 0}; // Bill denominations (500, 200, 100, 50)
    int coinDenom[3] = {0, 0, 0}; // Coin denominations (20, 10, 5)
    int amount; // amount to withdraw
    int aux; //self explanatory variable name ;)
    const string withdrawMsg = "Enter the amount to withdraw: ";
    const int bills[4] = {500, 200, 100, 50};
    const int coins[3] = {20, 10, 5};
    const int bSize = 4;
    const int cSize = 3;
    void compareAndAdd(const int *denom, int *values, int index) {
        while (denom[index] <= aux) {
            values[index]++;
            aux -= denom[index];
        }
    }
    void printMoney(const int *denom, int *values, int size) {
        for (int i = 0; i < size; i++) {
            if (values[i] == 0) continue;
            cout << denom[i] << " - " << values[i] << endl;
        }
    }

public:
    Withdrawal() { // Constructor initialize class attributes
            aux = amount = 0;
    }
    void readAmount() {
        cout << withdrawMsg;
        cin >> amount;
        aux = amount;
    }
    void calculateBills() {
        for (int i = 0; i < bSize; i++) { compareAndAdd(bills, billDenom, i); }
    }
    void calculateCoins() {
        for (int i = 0; i < cSize; i++) { compareAndAdd(coins, coinDenom, i); }
    }
    void calculateAll() {
        calculateBills();
        calculateCoins();
    }
    void printBills() {
        cout << "Bills:" << endl;
        printMoney(bills, billDenom, bSize);
    }
    void printCoins() {
        cout << "Coins:" << endl;
        printMoney(coins, coinDenom, cSize);
    }
    void printAll() {
        printBills();
        printCoins();
    }
};

int main () {
    UserBank menu;
    menu.showMenu();
    menu.readSelection();
    return 0;
}
