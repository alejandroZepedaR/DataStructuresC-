#include <iostream>
#include <iomanip>
#include <string>
#include "BankAccount.h"
using namespace std;

class certificateOfDeposit: public bankAccount
{
    public:
    //Constructor
    certificateOfDeposit(int acctNum, string name, double initialBalance, int matMon):bankAccount(acctNum, name, initialBalance)
    {
        maturityMonths = matMon;
        currentMonth = 1;
        interestRate = 4.75;
    }

    //destructor
    ~certificateOfDeposit(void){}

    void withdraw(double amount)
    {
        if (balance - amount < 0)
        {
            cout<<"Declined: Insufficient funds remain to withdraw that amount" << endl;
            return;
        }
        balance-=amount;
    }
    void printSummary()
    {
        bankAccount::printSummary();
        cout << setw(25) << "Interest rate: " << interestRate << "%" << endl ;
        cout << setw(25) << "Maturity Months: " << maturityMonths << endl ;
        cout << setw(25) << "Current Month: " << currentMonth << endl;
        cout << endl << setw(60) << setfill('-') << "" << setfill(' ') << endl;
    }

    void printStatement()
    {
        printSummary();
        cout<<"Here goes the Certificate of Deposit..."<<endl;
    }

    private:
        int maturityMonths;
        int currentMonth;
        double interestRate;
};