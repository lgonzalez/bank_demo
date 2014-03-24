#ifndef USERBANK_H
#define USERBANK_H

class UserBank {
protected:
    static const int MAX_LIMIT = 10000;
    static const int MAX_TRIES = 3;
    static int userBalance;

public:
    void setBalance(int i);
};

#endif
