#include <iostream>
#include "withdrawal.h"

void Withdrawal::compareAndAdd(const int *denom, int *values, int index) {
    while (denom[index] <= aux) {
        values[index]++;
        aux -= denom[index];
    }
}
void Withdrawal::printMoney(const int *denom, int *values, int size) {
    for (int i = 0; i < size; i++) {
        if (values[i] == 0) continue;
        std::cout << denom[i] << " -> " << values[i] << std::endl;
    }
}
Withdrawal::Withdrawal() { aux = amount = 0; }
void Withdrawal::setAmount(int a) { aux = amount = a; }
void Withdrawal::updateBalance() { userBalance -= amount; }
void Withdrawal::calculateBills() {
    for (int i = 0; i < bSize; i++) { compareAndAdd(bills, billDenom, i); }
}
void Withdrawal::calculateCoins() {
    for (int i = 0; i < cSize; i++) { compareAndAdd(coins, coinDenom, i); }
}
void Withdrawal::calculateAll() {
    calculateBills();
    calculateCoins();
}
void Withdrawal::printBills() {
    std::cout << "Bills:" << std::endl;
    printMoney(bills, billDenom, bSize);
}
void Withdrawal::printCoins() {
    std::cout << "Coins:" << std::endl;
    printMoney(coins, coinDenom, cSize);
}
void Withdrawal::printAll() {
    printBills();
    printCoins();
}
