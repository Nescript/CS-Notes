#include <iostream>
using namespace std;

class BankAccount
{
private:
    string Account;
    double balance;
public:
    BankAccount(string acc, double bal) : Account(acc), balance(bal) {}
    ~BankAccount() 
    {
        cout << "Account closed" << endl;
    }
    void deposit(double amount)
    {
        balance += amount;
    }
    bool withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            return 1;
        }
        else return 0;
    }
    double getBalance()
    {
        return balance;
    }
    void display()
    {
        cout << "Account is " << Account << endl;
        cout << "Balance is " << balance << endl;
    }
};