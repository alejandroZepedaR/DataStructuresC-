//Alejandro Zepeda
//CIS 269
//9/12/2022
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//Function to get a float input from the user
float getFloat(string msg){
    float num;
    cout<<msg<<endl;
    cin>>num;
    return num;
}

int main(){

    //Declare variables
    float areaOfYard, treeRadius, spaceBetweenTrees, treeArea, totalTreeArea, treeSpaceArea;
    int totalTrees;

    //Prompts the user for yard and tree data
    areaOfYard = getFloat("Enter the area of the yard (m^2): ");
    treeRadius = getFloat("Enter the radius of a fully grown tree (m): ");
    spaceBetweenTrees = getFloat("Enter the requiered space between trees (m^2): ");

    //Calculates the Total trees that can be planted and how much they will ocuppy
    treeArea = 3.1416 * pow(treeRadius,2);
    treeSpaceArea = treeArea + spaceBetweenTrees;
    totalTrees = round(areaOfYard/treeSpaceArea);
    totalTreeArea = totalTrees * treeArea;

    cout<<"Number of trees that can be planted: "<<totalTrees<<endl;
    cout<<"Total space that will be ocuppied: "<<totalTreeArea<<"m^2"<<endl;

    
    return 0;
}

