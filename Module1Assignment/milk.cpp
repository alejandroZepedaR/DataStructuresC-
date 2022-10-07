//Alejandro Zepeda
//CIS 269
//Module 1 Assignment #1
//This program calculates the cost, profit and cartons of milk produced.

#include<iostream>
#include <cmath>
using namespace std;

int main (){
    //Declare Variables
    float litersPerCarton, totalProduced, cartonsProduced, costPerLiter, profit, totalProfit, totalCost;

    //Set Constants
    costPerLiter = 0.38;
    litersPerCarton = 3.78;
    profit = 0.27;

    //Prompts user for Input
    cout<<"Enter the amount of milk produced in the morning: (in Liters)"<<endl;
    cin >> totalProduced;
    
    //Performs operations over the data
    cartonsProduced = totalProduced / litersPerCarton;
    totalCost = totalProduced * costPerLiter;
    totalProfit = round(cartonsProduced) * 0.27;
    
    //Displays Information to the user
    cout<<"Number Of Cartons: "<<round(cartonsProduced)<<endl;
    cout<<"Cost of producing milk: $"<<totalCost<<endl;
    cout<<"Profit from production: $"<<totalProfit<<endl;

    return 0;
}