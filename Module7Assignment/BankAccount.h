#ifndef BankAccount_h
#define BankAccount_h
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class bankAccount
{
    public:
        //Constuctor
        bankAccount(int aNumber, string name, double intialBalance)
        {
            accountNumber = aNumber;
            ownerName = name;
            balance = intialBalance;
        }

        //Destructor
        ~bankAccount(void){}

        //Accessors
        string getName()
        {
            return ownerName;
        }
        int getAccountNumber()
        {
            return accountNumber;
        }
        double getBalance()
        {
            return balance;
        }

        void deposit(double amount)
        {
            balance += amount;
            cout<<"$"<<amount<<" Has been deposited into your account"<<endl;
        }

        virtual void printSummary()
        {
            cout<<setw(60)<<setfill('-')<<""<<setfill(' ')<<endl;
            cout<<endl<<setw(25)<<""<<"Account Summary"<<endl<<endl;
            cout<<setw(25)<<"Name: "<<ownerName<<endl;
            cout<<setw(25)<<"Account Number: "<<accountNumber<<endl;
            cout<<setw(25)<<"Current balance: "<<balance<<endl;
        }
    protected:
        int accountNumber;
        string ownerName;
        double balance;
};

#endif