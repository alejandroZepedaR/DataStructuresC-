#ifndef checkingAccount_h
#define checkingAccount_h
#include <iostream>
#include <iomanip>
#include <string>
#include "BankAccount.h"
using namespace std;

class checkingAccount: public bankAccount
{
    public:
        checkingAccount(int aNumber, string name, double initialBalance):bankAccount(aNumber, name, initialBalance){}
        ~checkingAccount(void){}

        virtual void writeCheck(double amount) = 0;

        void withdraw(double amount)
        {
            if(balance - amount < 0)
            {
                cout<<"Declined: Insufficient funds remain to withdraw the amount"<<endl;
                return;
            }
            if(balance - amount < minimumBalance)
            {
                cout<<"Declined: Minimum balance requierment prohibits this withdrawal"<<endl;
                return;
            }
            balance -= amount;
        }
        
        void printStatement()
        {
            printSummary();
            cout<<endl<<"Here goes the details of the checking account"<<endl;
        }

    protected:
        double interestRate;
        double minimumBalance;
        int checksRemaining;
};


#endif