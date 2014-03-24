#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <string>
#include "deposit.h"
#include "withdrawal.h"
#include "userbalance.h"

class UserInterface: public Deposit, public Withdrawal, public UserBalance {
 private:
    const std::string menu = "[H]ome [D]eposit [B]alance [W]ithdrawal [E]xit";
    const std::string triesMsg = "You exceeded the number of tries";
    const std::string enterMsg = "Enter the amount to deposit";
    const std::string maxMsg = "You exceeded the allowed limit: ";
    const std::string withdrawMsg = "Enter the amount to withdraw: ";
    enum {HOME='H', DEPOSIT='D', BALANCE='B', WITHDRAWAL='W', EXIT='E'};
    char userOption;
    int amount;

 public:
    // Clears screen and prints main menu
    void showMenu();
    // Reads user input and validates it
    void readSelection();
    void readDepositAmount();
    void readWithdrawalAmount();
};

#endif
