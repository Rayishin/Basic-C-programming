#include <iostream>
#include <string>

struct bankAccount
{
    int accountNumber{};
    std::string name{};
    double amountMoney{};
};

void changedAccount(bankAccount& bankAccount, double newAmount)
{
    bankAccount.amountMoney = newAmount;
}

int main()
{
    bankAccount b;

    std::cout << "Enter the account number: ";
    std::cin >> b.accountNumber;

    std::cout << "Enter the name account: ";
    std::cin >> b.name;

    std::cout << "Enter the amount of money: ";
    std::cin >> b.amountMoney;

    double newBalance;
    std::cout << "Enter the new amount of money: ";
    std::cin >> newBalance;

    changedAccount(b, newBalance);

    std::cout << "Your account: " << b.name << ", " << b.accountNumber << ", " << b.amountMoney << std::endl;

    return EXIT_SUCCESS;
}