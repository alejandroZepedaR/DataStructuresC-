#include <string>
#include <iostream>
using namespace std;

class personType
{
    friend istream& operator>>(istream&, personType&);
    friend ostream& operator<<(ostream& const personType&);

    public:
        void setName(string first, string last);
        string getFirstName() const;
        string getLastName() const;
        personType(string first = "", string last = "");

        bool operator==(const personType& right) const;
        bool operator!=(const personType& right) const;
        bool operator<=(const personType& right) const;
        bool operator>=(const personType& right) const;
        bool operator>(const personType& right) const;
        bool operator<(const personType& right) const;

    protected:
    string firstName;
    string lastName;


};

string personType::getFirstName() const
{
    return firstName;
}

string personType::getLastName()const
{
    return lastName;
}

bool personType::operator==(const personType& right) const
{
    return(firstName == right.firstName && lastName == right.lastName);
}

bool personType::operator!=(const personType& right) const
{
    return(firstName != right.firstName || lastName != right.lastName);
}

bool personType::operator<=(const personType& right) const
{
    return(lastName <= right.lastName || (lastName == right.lastName && firstName <= right.firstName));
}

bool personType::operator<(const personType& right) const
{
    return(lastName < right.lastName || (lastName == right.lastName && firstName < right.firstName));
}
bool personType::operator>=(const personType& right) const
{
    return (lastName >= right.lastName || (lastName == right.lastName && firstName >= right.firstName));

}
bool personType::operator>(const personType& right) const
{
    return(lastName > right.lastName || (lastName == right.lastName && firstName > right.firstName));
}

istream& operator>>(istream& isObject, personType& pName)
{
    isObject >> pName.firstName >> pName.lastName;
    return isObject;
}

ostream& operator<<(ostream& osObject, const personType& pName)
{
    osObject << pName.firstName<<" "<<pName.lastName;
    return osObject;
}