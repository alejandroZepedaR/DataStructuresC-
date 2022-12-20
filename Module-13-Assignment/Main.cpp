#include<fstream>
#include "myStack.h"
#include "infixToPostfix.h"
using namespace std;

int main()
{
    infixToPostfix InfixExp;
    string infix;
    ifstream infile;

    infile.open("infixData.txt", ios::in);
    if(!infile)
    {
        cout<<"Cannot open input fle."<<endl;
        return 1;
    }
    getline(infile, infix);

    while(infile)
    {
        InfixExp.getInfix(infix);
        InfixExp.showInfix();
        InfixExp.showPostFix();
        cout<<endl;
        getline(infile, infix);
    }
    infile.close();
    return 0;
}