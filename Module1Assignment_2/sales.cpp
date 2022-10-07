//Alejandro Zepeda
//CIS 269
//9/4/2022

#include<iostream>
using namespace std;

main(){

    //Declare variables
    float fixedComission, percentageComission, purchasingCost, minimumAmount, maximumAmount;
    float minimumSellingPrice, maximumSellingPrice, salesCommisionMinimum, salesCommisionMaximum;

    //Prompts user for data
    cout<<"Enter the fixed comission: "<<endl;
    cin>>fixedComission;
    cout<<"Enter the percentage of the commission: "<<endl;
    cin>>percentageComission;
    cout<<"Enter the the purchasing cost of the car: "<<endl;
    cin>>purchasingCost;
    cout<<"Enter the minimum amount to add: "<<endl;
    cin>>minimumAmount;
    cout<<"Enter the maximum amount to add: "<<endl;
    cin>>maximumAmount;

    //Operations
    percentageComission = percentageComission/100;
    minimumSellingPrice = purchasingCost + minimumAmount;
    maximumSellingPrice = purchasingCost + maximumAmount;
    salesCommisionMinimum = (percentageComission * minimumAmount) + fixedComission;
    salesCommisionMaximum = (percentageComission * maximumAmount) + fixedComission;

    //Outputs information
    cout<<"Minimum Selling Price: $"<<minimumSellingPrice<<endl;
    cout<<"Maximum Selling Price: $"<<maximumSellingPrice<<endl;
    cout<<"Sales Comission range: $"<<salesCommisionMinimum<<" - $"<<salesCommisionMaximum<<endl; 

    return 0;
}