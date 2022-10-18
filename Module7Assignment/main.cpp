//Alejandro Zepeda
//CIS269
//10/17/2022
#include <iostream>
#include "BankAccount.h"
#include "savingsAccount.h"
#include "serviceChargeChecking.h"
#include <string>
using namespace std;

void testBankAccount(int accountNumber, string name, double balance)
{
    bankAccount bank(accountNumber, name, balance);
    cout<<"Print summary function test of bank account class: "<<endl;
    bank.printSummary();
}

void testSavings(int aNum, string name, double balance)
{
    double wAmount, dAmount;
    savingsAccount savings(aNum, name, balance);
    cout<<"Testing for savings account class"<<endl;
    cout<<"Enter a withdrawal amount to test for withdrawal"<<endl;
    cin>>wAmount;
    savings.withdraw(wAmount);
    cout<<"Enter a deposit amount to test for deposit function"<<endl;
    cin>>dAmount;
    savings.deposit(dAmount);
    savings.printSummary();
}

void testCheckings(int aNum, string name, double balance)
{
    double wAmount, dAmount, cAmount;
    serviceChargeChecking checking(aNum, name, balance);
    cout<<"Testing for no service charge checking account class"<<endl;
    cout<<"Enter a withdrawal amount to test for withdrawal"<<endl;
    cin>>wAmount;
    checking.withdraw(wAmount);
    cout<<"Enter a deposit amount to test for deposit function"<<endl;
    cin>>dAmount;
    checking.deposit(dAmount);
    cout<<"Enter an amount to write a check: "<<endl;
    cin>>cAmount;
    checking.writeCheck(cAmount);
    checking.printSummary();

}
int main()
{
    int accountNumber;
    double balance;
    string name;

    cout<<"Enter the following data to test all classes derieved from bankAccount: "<<endl;
    cout<<"Enter the Account Number: "<<endl;
    cin>>accountNumber;
    cout<<"Enter the initial Balance: "<<endl;
    cin>>balance;
    cout<<"Enter the owner Name: "<<endl;
    cin>>name;

    testBankAccount(accountNumber, name, balance);

    testSavings(accountNumber, name, balance);

    testCheckings(accountNumber, name, balance);
    


    return 0;
}