#ifndef checkingAccount_h
#define checkingAccount_h
#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;

class checkingAccount: public bankAccount
{
    public:
        checkingAccount(int aNumber, string name, double initialBalance, double iRate, double mBalance, double sCharge):bankAccount(aNumber, name, initialBalance)
        {
            minimumBalance = mBalance;
            interest = iRate;
            serviceCharge = sCharge;
        }
        checkingAccount()
        {
            minimumBalance = 0;
            interest = 0;
            serviceCharge = 0;
            accountNumber = 0;
            ownerName = " ";
            balance = 0;
        }

        void setInteresetRate(double iRate)
        {
            interest = iRate;
        }
        void setMinimumBalance(double mBalance)
        {
            minimumBalance = mBalance;
        }
        void setServiceCharge(double sCharge)
        {
            serviceCharge = sCharge;
        }

        double getInterestRate()
        {
            return interest;
        }
        double getMinimumBalance()
        {
            return minimumBalance;
        }
        double getServiceCharge()
        {
            return serviceCharge;
        }
        void withdraw(double amount)
        {
            if(balance - amount < 0)
            {
                cout<<"Declined: Insufficient funds remain to withdraw the amount"<<endl;
                return;
            }
            if(balance - amount < minimumBalance)
            {
                cout<<"WARNING: You are below your minimum Balance"<<endl;
                balance = balance - serviceCharge;
            }
            balance -= amount;
        }
        void verifyBalance()
        {
            if(balance < minimumBalance)
            {
                cout<<"You are below your minimum balance"<<endl;

            }else{
                cout<<"You are above your minimum balance"<<endl;
            }
        }

        void printSummary()
        {
            print();
            cout<<setw(25)<<"Minimum Balance: $"<<minimumBalance<<endl;
            cout<<setw(25)<<"Interest Rate: "<<interest<<"%"<<endl;
            cout<<setw(25)<<"Service Charge: $"<<serviceCharge<<endl;
        }
    private:
        double minimumBalance;
        double interest;
        double serviceCharge;

};
#endif