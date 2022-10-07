#include<fstream>
#include<iostream>
#include<string>
using namespace std;


int main(){

    fstream employeeData;
    employeeData.open("Ch3_Ex5Data.txt", ios::in);

    fstream outputData;
    outputData.open("Ch3_Ex5Output.dat", ios::out);

    if(employeeData.is_open()){

        string line;
        string employeeInfo[4];

        while(getline(employeeData,line)){
            string word = "";
            int counter = 0;
            
            for(auto x: line){
                
                if(x==' '){
                    employeeInfo[counter] = word;
                    counter = counter + 1;
                    word = "";
                    if (counter == 4){
                        float baseSalary, finalSalary, increment;
                        baseSalary = std::stof(employeeInfo[2]);
                        increment = std::stof(employeeInfo[3]);
                        increment = increment/100;
                        finalSalary = baseSalary * increment;
                        finalSalary = baseSalary + finalSalary;
                        outputData<<"Name: "+employeeInfo[1]+" ";
                        outputData<<employeeInfo[0]+" Previous Salary: $";
                        outputData<<employeeInfo[2]+" New Salary: $";
                        outputData<<finalSalary;
                        outputData<<"\n";
                    }
                }else{
                    word = word+x;
                }
                
            }
        }
        employeeData.close();
        outputData.close();
        cout<<"New File was successfully created!"<<endl;
    }
    
    return 0;
}
