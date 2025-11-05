#include <iostream>
using namespace std;

class BankAccount
{
private:
    const string accountNumber;
    string ownerName;
    double balance;
    static int totalAccounts;
    mutable int queryCount;
public:
    BankAccount(string number, string name, double money) : accountNumber(number), ownerName(name), 
                                              balance(money), queryCount(0) {++totalAccounts;}
    ~BankAccount()
    {
        totalAccounts--;
        cout << "Account closed" << endl;
    }
    string getAccountNumber() const
    {
        return accountNumber;
        //queryCount++;
    }
    string getOwnerName() const
    {
        return ownerName;
        //queryCount++;
    }
    double getBalance() const
    {
        queryCount++;
        return balance;
    }
    int getQueryCount() const
    {
        return queryCount;
    }
    void setOwnerName(const string& name)
    {
        ownerName = name;
    }
    BankAccount& deposit(double amount)
    {
        if(amount > 0) balance += amount;
        else cout << "illegle amount! Operation had been canceled" << endl;
        return *this;
    }
    BankAccount& withdraw(double amount)
    {
        if(balance >= amount) balance -= amount;
        else cout << "balance not enough! Operation had been canceled" << endl;
        return *this;
    }
    void display() const
    {
        cout << "Account number is " << accountNumber << endl;
        cout << "Owner is " << ownerName << endl;
        cout << "Balance is " << balance << endl;
    }
    static int getTotalAccounts()
    {
        return totalAccounts;
    }
};
int BankAccount::totalAccounts = 0;
int main()
{
    cout << "Total accounts: " << BankAccount::getTotalAccounts() << endl;
    BankAccount acc1("001", "Alice", 1000.0);
    BankAccount acc2("002", "Bob", 2000.0);
    
    cout << "Total accounts: " << BankAccount::getTotalAccounts() << endl;
    
    // 链式调用
    acc1.deposit(500).withdraw(200).deposit(100);
    
    acc1.display();
    
    // 测试 const 和 mutable
    const BankAccount acc3("003", "Charlie", 5000.0);
    cout << "Charlie's balance: " << acc3.getBalance() << endl;
    cout << "Query count: " << acc3.getQueryCount() << endl;
    
    return 0;
}