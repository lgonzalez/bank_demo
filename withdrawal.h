#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H
#include "userbank.h"

class Withdrawal: public UserBank {
 private:
    int billDenom[4] = {0, 0, 0, 0}; // Bill denominations (500, 200, 100, 50)
    int coinDenom[3] = {0, 0, 0}; // Coin denominations (20, 10, 5)
    int amount; // amount to withdraw
    int aux; //self explanatory variable name ;)
    const int bills[4] = {500, 200, 100, 50};
    const int coins[3] = {20, 10, 5};
    const int bSize = 4;
    const int cSize = 3;
    void compareAndAdd(const int *denom, int *values, int index);
    void printMoney(const int *denom, int *values, int size);
 public:
    Withdrawal();
    void setAmount(int a);
    void updateBalance();
    void calculateBills();
    void calculateCoins();
    void calculateAll();
    void printBills();
    void printCoins();
    void printAll();
    
};

#endif
