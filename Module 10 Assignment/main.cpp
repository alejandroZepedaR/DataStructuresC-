//What is the output of the following code? 

#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int main()
{
    list<int> intList;
    int i;

    for (i=0; i < 5; i++)
        intList.push_back(i *(i+1));

    for (auto p: intList)
        cout<<p<<" ";
    cout<<endl;
    return 0;
}