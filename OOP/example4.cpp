#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Abstract Base Class
class Account
{
protected:
    int accountNumber;
    double balance;

public:
    Account(int accNo, double bal) : accountNumber(accNo), balance(bal) {}

    virtual void deposit(double amount)
    {
        balance += amount;
    }

    virtual void withdraw(double amount) = 0; // Pure virtual

    virtual void display() const
    {
        cout << "Account No: " << accountNumber
             << " | Balance: " << balance << endl;
    }

    virtual ~Account() {}
};

// Interface-like class
class Interest
{
public:
    virtual double calculateInterest() const = 0;
};

// Savings Account
class SavingsAccount : public Account, public Interest
{
private:
    double interestRate;

public:
    SavingsAccount(int accNo, double bal, double rate)
        : Account(accNo, bal), interestRate(rate) {}

    void withdraw(double amount) override
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient funds in Savings Account\n";
        }
    }

    double calculateInterest() const override
    {
        return balance * interestRate / 100;
    }

    void display() const override
    {
        cout << "[Savings] ";
        Account::display();
    }
};

// Current Account
class CurrentAccount : public Account
{
private:
    double overdraftLimit;

public:
    CurrentAccount(int accNo, double bal, double limit)
        : Account(accNo, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override
    {
        if (amount <= balance + overdraftLimit)
        {
            balance -= amount;
        }
        else
        {
            cout << "Overdraft limit exceeded\n";
        }
    }

    void display() const override
    {
        cout << "[Current] ";
        Account::display();
    }
};

// Operator Overloading
class Transaction
{
private:
    double amount;

public:
    Transaction(double amt) : amount(amt) {}

    Transaction operator+(const Transaction &t)
    {
        return Transaction(amount + t.amount);
    }

    void show() const
    {
        cout << "Transaction Amount: " << amount << endl;
    }
};

// Bank class (Aggregation)
class Bank
{
private:
    vector<shared_ptr<Account>> accounts;

public:
    void addAccount(shared_ptr<Account> acc)
    {
        accounts.push_back(acc);
    }

    void showAllAccounts() const
    {
        for (const auto &acc : accounts)
        {
            acc->display();
        }
    }

    void applyInterest()
    {
        for (const auto &acc : accounts)
        {
            Interest *i = dynamic_cast<Interest *>(acc.get());
            if (i)
            {
                cout << "Interest: " << i->calculateInterest() << endl;
            }
        }
    }
};

// Main
int main()
{
    Bank bank;

    shared_ptr<Account> acc1 = make_shared<SavingsAccount>(101, 5000, 5);
    shared_ptr<Account> acc2 = make_shared<CurrentAccount>(102, 3000, 2000);

    bank.addAccount(acc1);
    bank.addAccount(acc2);

    acc1->deposit(1000);
    acc2->withdraw(4000);

    bank.showAllAccounts();

    cout << "\nApplying Interest: \n";
    bank.applyInterest();

    // Operator Overloading Demo
    Transaction t1(100), t2(200);
    Transaction t3 = t1 + t2;
    t3.show();

    return 0;
}