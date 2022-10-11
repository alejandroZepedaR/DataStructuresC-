//Alejandro Zepeda
//CIS269
//10/10/2022

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

enum programOptions {ADD, SUBSTRACT, DIVIDE, MULTIPLY, MENU, EXIT};

void menu()
{
    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXX FRACTION CALCULATOR XXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
    cout<<"This program is used to add, substract, multiply or divide a fraction for you"<<endl;
    cout<<"X                            INSTRUCTIONS:                                  X"<<endl;
    cout<<"X 1. SELECT YOUR OPERATION (+), (x), (/), (-)"<<endl;
    cout<<"X 2. YOU WILL BE PROMPTED TO ENTER THE NUMERATOR AND DENOMINATOR OF THE FIRST FRACTION"<<endl;
    cout<<"X 3. YOU WILL BE PROMPTED TO ENTER THE NUMERATOR AND DENOMINATOR OF THE SECOND FRACTION"<<endl;
    cout<<"X 4. ENTER (e) to exit the program..."<<endl;
    cout<<"5. ENTER (m) to see the menu again."<<endl;
    cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;

}

programOptions chooseOption()
{
    programOptions chosenOption;
    char option;
    bool invalid = false;

    do   
    {
        cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXX FRACTION CALCULATOR XXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
        cout<<"To see the instructions enter (m)"<<endl;
        cout<<"To exit enter (e)"<<endl;
        cout<<"Enter your option (+, -, x, /): ";
        cin>>option;

        switch (option)
        {
        case '+':
            chosenOption = ADD;
            break;

        case '-':
            chosenOption = SUBSTRACT;
            break;

        case 'x':
            chosenOption = MULTIPLY;
            break;
        case '/':
            chosenOption = DIVIDE;
            break;
        case 'm':
            chosenOption = MENU;
            break;
        case 'e':
            chosenOption = EXIT;
            break;

        default:
            cout<<"YOU HAVE ENTERED AN INVALID CHOICE TRY AGAIN..."<<endl;
            invalid = true;
            break;
        }
    }while(invalid == true);

    return chosenOption;
    
}

int * getFractions(char type)
{
    static int fractions[4];
    cout<<"ENTER THE FRACTIONS: ";
    cin>>fractions[0];
    cout<<"/";
    cin>>fractions[1];
    cout<<type<<endl;
    cin>>fractions[2];
    cout<<"/";
    cin>>fractions[3];

    return fractions;

}

int getCommonDenominator(int firstDenominator, int secondDenominator)
{   
    return firstDenominator * secondDenominator;
}

string addFractions(int *fractions)
{   
    string finalFraction;
    int finalNumerator, commonDenominator;
    int firstNumerator = *(fractions + 0);
    int firstDenominator = *(fractions + 1);
    int secondNumerator = *(fractions + 2);
    int secondDenominator = *(fractions + 3);

    commonDenominator = getCommonDenominator(firstDenominator, secondDenominator);

    firstNumerator = firstNumerator * secondDenominator;
    secondNumerator = firstDenominator * secondNumerator;

    finalNumerator = firstNumerator + secondNumerator;
    finalFraction = to_string(finalNumerator)+ "/" + to_string(commonDenominator);

    return finalFraction;

}

string substractFractions(int *fractions)
{
    string finalFraction;
    int finalNumerator, commonDenominator;
    int firstNumerator = *(fractions + 0);
    int firstDenominator = *(fractions + 1);
    int secondNumerator = *(fractions + 2);
    int secondDenominator = *(fractions + 3);

    commonDenominator = getCommonDenominator(firstDenominator, secondDenominator);

    firstNumerator = firstNumerator * secondDenominator;
    secondNumerator = firstDenominator * secondNumerator;

    finalNumerator = firstNumerator - secondNumerator;
    finalFraction = to_string(finalNumerator)+ "/" + to_string(commonDenominator);

    return finalFraction;

}

string multiplyFractions(int *fractions)
{
    string finalFraction;
    int finalNumerator, commonDenominator;
    int firstNumerator = *(fractions + 0);
    int firstDenominator = *(fractions + 1);
    int secondNumerator = *(fractions + 2);
    int secondDenominator = *(fractions + 3);

    commonDenominator = getCommonDenominator(firstDenominator, secondDenominator);
    finalNumerator = firstNumerator * secondNumerator;

    finalFraction = to_string(finalNumerator)+ "/" + to_string(commonDenominator);

    return finalFraction;
}

string divideFractions(int *fractions)
{
    string finalFraction;
    int finalNumerator, finalDenominator;
    int firstNumerator = *(fractions + 0);
    int firstDenominator = *(fractions + 1);
    int secondNumerator = *(fractions + 2);
    int secondDenominator = *(fractions + 3);

    finalNumerator = firstNumerator * secondDenominator;
    finalDenominator = firstDenominator * secondNumerator;

    finalFraction = to_string(finalNumerator)+ "/" + to_string(finalDenominator);

    return finalFraction;
}

void displayResult(int *fractions, char operation, string result)
{
    cout<<"XXXXXXXX Result XXXXXXXXX"<<endl;
    cout<<"   "<<*(fractions + 0)<<"/"<<*(fractions + 1)<<" "<<operation<<" "<<*(fractions + 2)<<"/"<<*(fractions + 3)<<" = "<<result<<endl;
}

int main(){

    programOptions chosenOption;
    bool exit = false;
    int *fractions;
    string result = "";

    while(exit == false)
    {
        chosenOption = chooseOption();

        if(chosenOption == ADD)
        {
            fractions = getFractions('+');
            result = addFractions(fractions);
            displayResult(fractions, '+', result);
        }

        if(chosenOption == SUBSTRACT)
        {
            fractions = getFractions('-');
            result = substractFractions(fractions);
            displayResult(fractions, '-', result);
        }

        if(chosenOption == MULTIPLY)
        {
            fractions = getFractions('x');
            result = multiplyFractions(fractions);
            displayResult(fractions, 'x', result);
        }

        if(chosenOption == DIVIDE)
        {
            fractions = getFractions('/');
            result = divideFractions(fractions);
            displayResult(fractions, '/', result);
        }

        if (chosenOption == MENU)
        {
            menu();
        }
        if (chosenOption == EXIT)
        {
            exit = true;
        }

    }


    return 0;
}