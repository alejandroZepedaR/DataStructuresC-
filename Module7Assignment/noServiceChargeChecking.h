#include <iostream>
#include <iomanip>
#include <string>
#include "checkingAccount.h" 
using namespace std;

class noServiceChargeChecking : public checkingAccount
{
    public:
        noServiceChargeChecking(int aNum, string name, double initialBalance):checkingAccount(aNum, name, initialBalance)
        {
            interestRate = 0.25;//Any interest rate
            checksRemaining = -1; //A negative number indicates no limit
            minimumBalance = 1000;//Any Balance
        }
        ~noServiceChargeChecking(void){}
        void writeCheck(double amount)
        {
            if(balance - amount < 0)
            {
                cout<<"Declined: You have insufficient funds"<<endl;
                return;
            }
            balance-=amount;
        }
        void printSummary()
        {
            bankAccount::printSummary();
            cout << setw(25) << "Interest rate: " << interestRate << "%" << endl;
            cout << setw(25) << "Minimum Balance: $" << minimumBalance << endl;
            cout << setw(25) << "Unlimited checks " << endl;
            cout << setw(25) << "No monthly service fee "<< endl;
            cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
        }
};