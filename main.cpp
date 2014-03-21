#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class MainMenu {
private:
    string menu = "[H]ome [D]eposit [B]alance [W]ithdrawal [E]xit";
    static int const MAX_LIMIT = 10000;

public:
    void showMenu () { cout<<menu<<endl; }
};

int main () {
    MainMenu menu;
    menu.showMenu();
    return 0;
}
