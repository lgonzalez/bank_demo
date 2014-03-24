#include <iostream>
#include "userbalance.h"

int UserBalance::getBalance() {
    return userBalance;
}

void UserBalance::printBalance() {
    std::cout << balanceMsg << userBalance << std::endl;
}
