#include <iostream>
#include <string>
#include "savingsAccount.h"
#include "checingAccount.h"
using namespace std;

int main()
{
    int id = 1738801;
    string name = "Alejandro Zepda";
    double initialBalance = 1500;

    double withdrawSavings;
    double withdrawCheking;

    savingsAccount mySavingsAccount(id, name, initialBalance, 0.5);
    checkingAccount myCheckingAccount(id, name, initialBalance, 0.05, 1000, 50);

    mySavingsAccount.printSummary();
    cout<<"How much money would you like to withdraw :"<<endl;
    cin>>withdrawSavings;

    mySavingsAccount.withdraw(withdrawSavings);
    mySavingsAccount.printSummary();

    myCheckingAccount.printSummary();
    cout<<"How much money would you like to withdraw :"<<endl;
    cin>>withdrawCheking;

    myCheckingAccount.withdraw(withdrawCheking);
    myCheckingAccount.printSummary();

    return 0;
}