#include "userbank.h"

// Set initial balance
int UserBank::userBalance = 5000;

void UserBank::setBalance(int i) {
    userBalance = i;
}

