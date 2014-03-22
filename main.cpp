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
        cout<<menu<<endl;
    }

    // Reads user input and validates it
    void readSelection () {
        static int count = 1;
        cin>>userOption;
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
                cout<<triesMsg<<endl;
                break;
            }
            cout<<"Unknown option, please try again"<<endl;
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
    void printBalance() { cout<<balanceMsg<<userBalance<<endl; }
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

int main () {
    UserBank menu;
    menu.showMenu();
    menu.readSelection();
    return 0;
}
