#include "Bank.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

Bank::Bank(const std::string& fileName) {
    dataFile = fileName;
    loadAccounts();
}

void Bank::loadAccounts() {
    accounts.clear();

    std::ifstream file(dataFile);

    int number;
    std::string name;
    double balance;

    while (file >> number >> std::quoted(name) >> balance) {
        accounts.emplace_back(number, name, balance);
    }

    file.close();
}

bool Bank::saveAccounts() const {
    std::ofstream file(dataFile);

    if (!file.is_open()) {
        return false;
    }

    for (const Account& account : accounts) {
        file << account.getAccountNumber() << " "
             << std::quoted(account.getOwnerName()) << " "
             << account.getBalance() << "\n";
    }

    file.close();
    return true;
}

bool Bank::createAccount(int number, const std::string& name, double balance) {
    if (number <= 0 || name.empty() || balance < 0 || findAccount(number) != nullptr) {
        return false;
    }

    accounts.emplace_back(number, name, balance);
    return saveAccounts();
}

Account* Bank::findAccount(int number) {
    for (Account& account : accounts) {
        if (account.getAccountNumber() == number) {
            return &account;
        }
    }

    return nullptr;
}

void Bank::displayAllAccounts() const {
    if (accounts.empty()) {
        std::cout << "No accounts found.\n";
        return;
    }

    for (const Account& account : accounts) {
        std::cout << "\nAccount Number: " << account.getAccountNumber()
                  << "\nOwner: " << account.getOwnerName()
                  << "\nBalance: " << account.getBalance()
                  << "\n----------------------\n";
    }
}

bool Bank::depositToAccount(int number, double amount) {
    Account* account = findAccount(number);

    if (account == nullptr || !account->deposit(amount)) {
        return false;
    }

    return saveAccounts();
}

bool Bank::withdrawFromAccount(int number, double amount) {
    Account* account = findAccount(number);

    if (account == nullptr || !account->withdraw(amount)) {
        return false;
    }

    return saveAccounts();
}
