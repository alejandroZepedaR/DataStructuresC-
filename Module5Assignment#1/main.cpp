//Alejandro Zepeda
//CIS269
//10/3/2022

#include <iostream>
#include <iomanip>
using namespace std;

//Named constants
const double COST_OF_SMALL_CUP_ = 1.75;
const double COST_OF_MEDIUM_CUP = 1.90;
const double COST_OF_LARGE_CUP = 2.00;
const int SIZE_OF_SMALL_CUP = 9;
const int SIZE_OF_MEDIUM_CUP = 12;
const int SIZE_OF_LARGE_CUP = 15;

//Function declarations
void printMenu();
void sellCoffe(int &smallSold, int &mediumSold, int &largeSold, int &coffeSold, double &moneyMade);
void cupsSold(int small, int medium, int large);
void coffeSold(int amountCoffe);
void moneyMade(double money);

int main()
{
    int choice;
    int smallSold = 0, mediumSold = 0, largeSold = 0;
    int coffe = 0;
    double money = 0;
    bool doExit = false;
    cout << "**Welcome to the coffe shop**" << endl;

    //Menu
    while (!doExit)
    {       
        //Display the menu
        printMenu();

        //Prompt the user to enter the choice
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                //Sell the coffe
                sellCoffe(smallSold,mediumSold,largeSold,coffe,money);
                break;
            case 2:
                //print number of cups of each size sold
                cupsSold(smallSold, mediumSold, largeSold);
                break;
            case 3:
                //print the amount of coffe sold
                coffeSold(coffe);
                break;
            case 4:
                //print the money made
                moneyMade(money);
                break;
            case 5:
                //Set the boolean value to true, to exit
                doExit = true;
                break;
            default: cout << "**Wrong choice" << endl;

        }

    }
    system("pause");
    return 0;
}

//Prints the menu that shows the user how to use the program
void printMenu()
{
    cout << "*****Menu*****" << endl;
    cout << "1. Buy a coffe" << endl;
    cout << "2. Show the totoal number of cups sold" << endl;
    cout << "3. Show the total amound of coffe sold" << endl;
    cout << "4. Show the total money made." << endl;
    cout << "5. Leave the menu" << endl;
}
//Sells coffee
void sellCoffe(int &smallSold,int &mediumSold, int &largeSold,int &coffeSold,double &moneyMade)
{
    int size = 0,cups=0;
    while (true)
    {
        cout << "1. Samll coffe cup(9oz) " << endl;
        cout << "2. Medium coffe cup(12oz) " << endl;
        cout << "3. Large coffe cup(15oz) " << endl;
        cout << "4. Order finished " << endl;
        cout << "Enter your choice of coffe cup: ";
        cin >> size;

        if (size == 4)
        {
            break;
        }
        cout << "Enter the number of cups: ";
        cin >> cups;

        if (size == 1)
        {
            smallSold = smallSold + cups;
            coffeSold = coffeSold + cups * 9;
            moneyMade = moneyMade + (cups*1.75);
        }
        else if (size == 2)
        {
            mediumSold = mediumSold + cups;
            coffeSold = coffeSold + cups * 12;
            moneyMade = moneyMade + (cups*1.90);
        }
        else if (size == 3)
        {
            largeSold = largeSold + cups;
            coffeSold = coffeSold + cups * 15;
            moneyMade = moneyMade + (cups * 2);
        }
        else
            cout << "Sorry! wrong choices. try again!" << endl;
        }
}   
//Prints the number of cups of each size sold
void cupsSold(int small,int medium,int large)
{
    cout << setprecision(0) << fixed << "Total number of small cups sold: " << small << endl;
    cout << "Total number of medium cups sold: " << medium << endl;
    cout << "Total number of large cups sold: " << large << endl;
}

//Prints the total amount of coffee sold
void coffeSold(int amountCoffe)
{

    cout << setprecision(0) << fixed << "Total amount of coffe sold: " << amountCoffe << " oz" << endl;

}

//Prints the total money made
void moneyMade(double money)
{
    cout << setprecision(2) << fixed << "Total money made: $" << money << endl;

}