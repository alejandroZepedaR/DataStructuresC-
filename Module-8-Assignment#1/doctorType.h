#ifndef doctorType_h
#define doctorType_h
#include <iostream>
#include <string>
#include "personType.h"
using namespace std;

class doctorType: public personType
{
    public:
        doctorType(string fName, string lName, string spec) : personType(fName, lName)
        {
            specialty = spec;
        }
        doctorType()
        {
            personType::setName(" ", " ");
            specialty = " ";

        }
        void setSpecialty(string spec)
        {
            specialty = spec;
        }
        void print()
        {
            personType::print();
            cout << " specialty: " << specialty << endl;
        }

    protected:
        string specialty;
};
#endif
