#include <iostream>
#include <stdio.h>
#include <string>
#include "userinterface.h"

void UserInterface::showMenu() {
    system("clear");
    std::cout << menu << std::endl;
}
void UserInterface::readSelection() {
    static int count = 1;
    std::cin >> userOption;
    switch (userOption) {
    case HOME:
        showMenu();
        readSelection();
        break;
    case DEPOSIT:
        readDepositAmount();
        addAmount(amount);
        showMenu();
        readSelection();
        break;
    case BALANCE:
        printBalance();
        readSelection();
        break;
    case WITHDRAWAL:
        readWithdrawalAmount();
        calculateAll();
        printAll();
        updateBalance();
        readSelection();
        break;
    case EXIT:
        return;
    default:
        if (count >= MAX_TRIES) {
            std::cout << triesMsg << std::endl;
            break;
        }
        std::cout << "Unknown option, please try again" << std::endl;
        count++;
        readSelection();
    }
}
void UserInterface::readDepositAmount() {
    static int count = 1;
    std::cout << enterMsg << std::endl;
    std::cin >> amount;
    if (amount > MAX_LIMIT) { // Try again if max amount is exceeded
        std::cout << maxMsg << MAX_LIMIT << std::endl;
        if (count >= MAX_TRIES) {
            std::cout << triesMsg << std::endl;
            return;
        }
        count++;
        readDepositAmount();
    }
}
void UserInterface::readWithdrawalAmount() {
    std::cout << withdrawMsg;
    std::cin >> amount;
    setAmount(amount);
}
