#ifndef savingsAccount_h
#define savingsAccount_h
#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;

class savingsAccount: public bankAccount
{
    public:
        savingsAccount(int aNumber, string customer, double initialBalance, double iRate):bankAccount(aNumber, customer, initialBalance)
        {
            interestRate = iRate;
        }   
        void setInterest(double iRate)
        {   
            interestRate = iRate;
        }
        double getInterestRate()
        {
            return interestRate;
        }

        void printSummary()
        {
            print();
            cout<<setw(25)<<"Interest Rate: "<<interestRate<<"%"<<endl;

        }
    private:
        double interestRate;


};
#endif