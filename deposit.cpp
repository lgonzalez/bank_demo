#include "deposit.h"

void Deposit::addAmount(int amount) {
    userBalance += amount;
    std::cout << userBalance << std::endl;
}
