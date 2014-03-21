#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class MainMenu {
private:
    const string menu = "[H]ome [D]eposit [B]alance [W]ithdrawal [E]xit";
    static int const MAX_LIMIT = 10000;
    enum {HOME='H', DEPOSIT='D', BALANCE='B', WITHDRAWAL='W', EXIT='E'};
    char userOption;

protected:
    static const int MAX_TRIES = 3;
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
};

int main () {
    MainMenu menu;
    menu.showMenu();
    menu.readSelection();
    return 0;
}
