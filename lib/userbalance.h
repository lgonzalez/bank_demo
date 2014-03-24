#ifndef USERBALANCE_H
#define USERBALANCE_H
#include <string>
#include "userbank.h"

class UserBalance: public UserBank {
 private:
    const std::string balanceMsg = "Your current account balance is: ";

 public:
    int getBalance();
    void printBalance();
};

#endif
