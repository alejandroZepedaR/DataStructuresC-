#include <iostream>
#include <iomanip>
#include <string>
#include "BankAccount.h"
using namespace std;

class savingsAccount: public bankAccount
{
    public:
        savingsAccount(int aNum, string name, double initialBalance):bankAccount(aNum, name, initialBalance)
        {
            interestRate= 3.99;
        }
        ~savingsAccount(void){}

        void withdraw(double amount)
        {
            if(balance-amount<0)
            {
                cout<<"Declined: Insufficient funds remain to withdraw that amount"<<endl;
                return;
            }
            balance -= amount;
        }

        void printSummary()
        {
            bankAccount::printSummary();
            cout << setw(25) << "Interest rate: " << interestRate << "%" << endl << endl;
            cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
        }
        void printStatement()
        {
            printSummary();
            cout << "A full implementation would also print a Savings Account Statement here." << endl;
        }
    protected:
        double interestRate;
};