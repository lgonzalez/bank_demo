#ifndef DEPOSIT_H
#define DEPOSIT_H
#include <iostream>
#include "userbank.h"

class Deposit: public UserBank {
 public:
    void addAmount(int amount);
};

#endif
