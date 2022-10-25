#ifndef personType_h
#define personType_h
#include <iostream>
#include <string>
using namespace std;

class personType
{
public:
    void print() const;
    void setName(string first, string last);
    string getFirstName() const;
    string getLastName() const;
    personType(string first = "", string last = "");

private:
    string firstName;
    string lastName;
};

void personType::print() const
{
    cout << firstName << " " << lastName;
}
void personType::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}
string personType::getFirstName() const
{
    return firstName;
}
string personType::getLastName() const
{
    return lastName;
}
personType::personType(string first, string last)
{
    firstName = first;
    lastName = last;
}
#endif