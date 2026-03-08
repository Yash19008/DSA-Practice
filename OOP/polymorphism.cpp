#include <iostream>

using namespace std;

class BankAccount
{
protected:
    string holderName;
    double balance;

public:
    BankAccount(string name, double bal) : holderName(name), balance(bal) {}
    virtual void displayAccDetails()
    {
        cout << "Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual void displayIntRate()
    {
        cout << "No Interest Rate is specified!";
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount
{
protected:
    double interestRate;

public:
    SavingsAccount(string name, double initialBalance, double intRate) : BankAccount(name, initialBalance), interestRate(intRate) {}

    void displayAccDetails() override
    {
        cout << "Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }

    void displayIntRate() override
    {
        double interest = balance * (interestRate / 100);
        cout << "Savings Account Interest: " << interest << endl;
    }
};

class BankingOperations
{
public:
    void deposit(double amt, double &balance)
    {
        balance += amt;
        cout << amt << " Deposited! New Balance: " << balance << endl;
    }

    void deposit(double amt, double &balance, double bonus)
    {
        balance += (amt += bonus);
        cout << amt << " Deposited including Bounus Amt! New Balance: " << balance << endl;
    }

    void withdraw(double amt, double &balance)
    {
        balance -= amt;
        cout << amt << " Withdrawal! New Balance: " << balance << endl;
    }
};

int main()
{
    double balance = 5000.00;

    BankingOperations bo;
    bo.deposit(500.00, balance);
    bo.deposit(500.00, balance, 50);
    bo.withdraw(250.00, balance);
    cout << endl;

    SavingsAccount *acc1 = new SavingsAccount("Test", balance, 5.0);
    SavingsAccount *acc2 = new SavingsAccount("Test2", balance, 10.0);

    acc1->displayAccDetails();
    cout << endl;
    acc2->displayAccDetails();
}