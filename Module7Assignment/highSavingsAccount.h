#include <iostream>
#include <iomanip>
#include <string>
#include "savingsAccount.h" 
using namespace std;

class highSavingsAccount: public savingsAccount
{
    public:
       highSavingsAccount(int aNum, string name, double initialBalance):savingsAccount(aNum, name, initialBalance)
       {
            minimumBalance = 5000;
       }
       ~highSavingsAccount(void){}

       void withdraw(double amount)
       {
            if(balance - amount < 0)
            {
                cout << "Declined: Insufficient funds remain to withdraw that amount" << endl;
                return;
            }
            if(balance - amount < minimumBalance)
            {
                cout << "Declined: Minimum balance requirement prohibits this withdrawal" << endl;
                return;
            }
            balance -= amount;
        }
        void printSummary()
        {
            bankAccount::printSummary();
            cout << setw(25) << "Interest rate: " << interestRate << "%" << endl;
            cout << setw(25) << "Minimum Balance: $" << minimumBalance << endl << endl;
            cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
        }
    protected:
        double minimumBalance;
};