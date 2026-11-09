#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    int accountNumber;
    std::string ownerName;
    double balance;

public:
    Account(int number, const std::string& name, double initialBalance);

    int getAccountNumber() const;
    std::string getOwnerName() const;
    double getBalance() const;

    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif
