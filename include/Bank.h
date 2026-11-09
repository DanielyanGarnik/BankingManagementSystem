#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <vector>
#include <string>

class Bank {
private:
    std::vector<Account> accounts;
    std::string dataFile;

public:
    Bank(const std::string& fileName);

    void loadAccounts();
    bool saveAccounts() const;

    bool createAccount(int number, const std::string& name, double balance);

    Account* findAccount(int number);

    void displayAllAccounts() const;

    bool depositToAccount(int number, double amount);
    bool withdrawFromAccount(int number, double amount);
};

#endif
