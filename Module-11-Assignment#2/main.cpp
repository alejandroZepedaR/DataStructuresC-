#include<iostream>
using namespace std;

int sumDigits(int num)
{
    if(num==0)
    {
        return 0;
    }
    else
    {
        return num%10 + sumDigits(num/10);
    }
}
int main()
{
    int num = 0;
    int sum = 0;

    cout<<"Enter a number to sum the digits: "<<endl;
    cin>>num;

    sum = sumDigits(num);


    cout<<"The sum of the digits of "<<num<<" is: "<<sum<<endl;
    return 0;
}