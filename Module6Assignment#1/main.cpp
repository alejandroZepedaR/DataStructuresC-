//Alejandro Zepeda
//CIS 269
//10/9/2022

#include <iostream>
using namespace std;

enum maritalOptions {MARRIED, SINGLE};
float data[4];

void getData(){
    maritalOptions maritalStatus;
    char maritalChoice;
    bool invalid = true;
    float numberOfChildren;
    float grossIncome;
    float pensionFund;
    

    while(invalid == true){
        cout<<"Enter your Marrital Status: (m: married/ s: single): "<<endl;
        cin>>maritalChoice;
        switch (maritalChoice)
        {
        case 'm':
            maritalStatus = MARRIED;
            invalid = false;
            break;

        case 's':
            maritalStatus = SINGLE;
            invalid = false;
            break;

        default:
            cout<<"You have entered an invalid choice!"<<endl;
            break;
        }
    }
    
    data[0] = maritalStatus;

    if(maritalStatus == MARRIED)
    {
        cout<<"Enter the number of children under the age 14: "<<endl;
        cin>>numberOfChildren;
    }else{
        numberOfChildren = 0;
    }

    data[1] = numberOfChildren;

    cout<<"Enter your combined gross income: "<<endl;
    cin>>grossIncome;

    data[2] = grossIncome;

    cout<<"Enter the percentage of gross income contributed to a pension fund: "<<endl;
    cin>>pensionFund;

    data[3] = pensionFund;
    
}

float taxAmount(){
    float grossIncome = data[2];
    int numberOfPeople = 0;
    float standardExemption = 0;
    float taxPercentage = 0;
    float taxAddition = 0;
    float taxOwed = 0;

    float pensionFund = 0;

    if(data[3] > 0){
        pensionFund = data[3]/100;
        pensionFund = pensionFund * grossIncome;
    }else{
        pensionFund = 0;
    }
    
    
    if (data[0] == 0){
        standardExemption = 7000;
        numberOfPeople = 2 + data[1];
    }else{
        standardExemption = 4000;
        numberOfPeople = 1;
    }

    if(data[2] <= 15000)
    {
        taxPercentage = 0.15;
    }

    if(data[2] > 15000 && data[2] <= 40000)
    {
        taxPercentage = 0.25;
        taxAddition = 2250;
    }

    if(data[2] > 40000)
    {
        taxAddition = 8460;
        taxPercentage = 0.35;
    }

    grossIncome = grossIncome - pensionFund;
    taxOwed = (taxPercentage * grossIncome) + taxAddition;
    taxOwed = taxOwed - standardExemption;
    taxOwed = taxOwed - (numberOfPeople * 1500);

    return taxOwed;

}

int main(){
    float tax;

    getData();

    tax = taxAmount();
    
    if(tax < 0){
        cout<<"You are owed: $"<<tax*-1<<endl;
    }else{
        cout<<"You Owe: $"<<tax<<" in taxes."<<endl; 
    }

    return 0;
}