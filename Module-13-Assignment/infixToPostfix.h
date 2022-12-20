#include <string>
#include <iostream>
using namespace std;

class infixToPostfix
{
    string infix;
    string postfix;

public:
    void showPostFix();
    bool isOperator(const char c);
    int precedence(const char op1, const char op2);
    void getInfix(string infixString)
    {
        infix = infix.substr(0, infixString.length() - 1);
    }
    void showInfix()
    {
        cout << "\nThe infix expression is : "<<infix;
    }
};

bool infixToPostfix::isOperator(const char c)
{
    if((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^') || (c == '%'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int infixToPostfix::precedence(const char op1, const char op2)
{
    int pre1, pre2;

    if ((op1 == '^') || (op2 == '^'))
    {
        cout << "Exponentiation was not considered"
        << "for precedence. \n\tThe program may"
        << "result in abnormal output of Postfix exp.";
    }
    if ((op1 == '+') || (op1 == '-'))
    {
        //low precedence
        pre1 = 0;
    }
    else
    {
        if ((op1 == '*') || (op1 == '/') || (op1 == '%'))
        pre1 = 1; // high precedence
    }

    if ((op2 == '+') || (op2 == '-')) //low precedence
    {
        pre2 = 0;
    }

    else
    {
        if ((op2 == '*') || (op2 == '/') || (op2 == '%'))
        {
            pre2 = 1;
        }
    }

    if (pre1 == pre2)
    {
        // equal precedence of op1 & op2
        return 0;
    }
    else
    {
        if (pre1 > pre2) //higher precedence of op1 over op2
        {
        return 1;
        }
    else
        {
        // lower precedence of op1 over op2
        return -1;
        }
    }
}

void infixToPostfix::showPostFix()
{
    myStack< char > myStack;
    string pfx = "";

    //append a right parenthesis ')' to the end of infix
    infix.append(")");

    // push the left parenthesis onto the stack
    myStack.push('(');
    unsigned int i = 0;

    do
    {
        // when the current element in infix is an operator
        if (isOperator(infix[i]))
        {
            // when the top of the stack is an operator
            if (isOperator(myStack.top()))
            {
                if (precedence(infix[i], myStack.top()) == 0)
                {
                    pfx = pfx + myStack.top();
                    myStack.pop();
                }
                else
                    if (precedence(infix[i],
                    myStack.top()) == 1)
                    {
                    myStack.push(infix[i]);
                    i++;
                    }
                else
                    {
                    pfx = pfx + myStack.top();
                    myStack.pop();
                    }
            }
            else
            {
            myStack.push(infix[i]);
            i++;
            }
        }
        else
        {
            if (infix[i] == ')')
            {
                while (myStack.top() != '(')
                {
                    pfx = pfx + myStack.top();
                    myStack.pop();
                }
                myStack.pop();
                i++;
            }
            else
                if (infix[i] == '(')
                {
                    myStack.push(infix[i]);
                    i++;
                }
                else
                {
                    pfx = pfx + infix[i];
                    i++;
            }
        }
    }while (i < infix.length());
    cout << "\nThe postfix expression is : " << pfx;
}

