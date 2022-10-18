#include <iostream>
#include <iomanip>
#include <string>
#include "checkingAccount.h"
using namespace std;

const int MAX_CHECKS = 10;
const double SVC_CHARGE=10.01;

class serviceChargeChecking: public checkingAccount
{
    public:
        serviceChargeChecking(int aNum, string name, double initialBalance):checkingAccount(aNum, name, initialBalance)
        {
            interestRate = 0;
            checksRemaining = MAX_CHECKS;
            minimumBalance = 0;
        }
        ~serviceChargeChecking(void){}

        void writeCheck(double amount)
        {
            if (checksRemaining == 0)
            {
                cout << "Declined: No more checks remaining this month" << endl;
                return;
            }
            if (balance - amount < 0)
            {
                cout << "Declined: Insufficient funds remain to withdraw that amount" << endl;
                return;
            }
            checksRemaining--;
            balance -=amount;
        }

        void printSummary()
        {
            bankAccount::printSummary();
            cout << setw(25) << "Checks remaining: " << checksRemaining << endl;
            cout << setw(25) << "Monthly service fee: $" << SVC_CHARGE << endl;
            cout << setw(25) << "No interest " << endl;
            cout << setw(25) << "No Minimum Balance " << endl;
            cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
        }
};