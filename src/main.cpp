#include <iostream>
#include "Bank.h"

int main() {

    Bank bank("data/accounts.txt");

    int choice;

    do {
        std::cout << "\n===== BANKING MANAGEMENT SYSTEM =====\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Display All Accounts\n";
        std::cout << "3. Search Account\n";
        std::cout << "4. Deposit\n";
        std::cout << "5. Withdraw\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose: ";

        std::cin >> choice;

        switch (choice) {

        case 1: {
            int number;
            std::string name;
            double balance;

            std::cout << "Account Number: ";
            std::cin >> number;

            std::cout << "Owner Name: ";
            std::getline(std::cin >> std::ws, name);

            std::cout << "Initial Balance: ";
            std::cin >> balance;

            if (bank.createAccount(number, name, balance)) {
                std::cout << "Account created successfully!\n";
            } else {
                std::cout << "Account creation failed!\n";
            }
            break;
        }

        case 2:
            bank.displayAllAccounts();
            break;

        case 3: {
            int number;

            std::cout << "Enter Account Number: ";
            std::cin >> number;

            Account* account = bank.findAccount(number);

            if (account != nullptr) {
                std::cout << "Owner: " << account->getOwnerName() << "\n";
                std::cout << "Balance: " << account->getBalance() << "\n";
            } else {
                std::cout << "Account not found!\n";
            }
            break;
        }

        case 4: {
            int number;
            double amount;

            std::cout << "Account Number: ";
            std::cin >> number;

            std::cout << "Deposit Amount: ";
            std::cin >> amount;

            if (bank.depositToAccount(number, amount)) {
                std::cout << "Deposit successful!\n";
            } else {
                std::cout << "Deposit failed!\n";
            }
            break;
        }

        case 5: {
            int number;
            double amount;

            std::cout << "Account Number: ";
            std::cin >> number;

            std::cout << "Withdrawal Amount: ";
            std::cin >> amount;

            if (bank.withdrawFromAccount(number, amount)) {
                std::cout << "Withdrawal successful!\n";
            } else {
                std::cout << "Withdrawal failed!\n";
            }
            break;
        }

        case 0:
            bank.saveAccounts();
            std::cout << "Thank you for using our banking system!\n";
            break;

        default:
            std::cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
