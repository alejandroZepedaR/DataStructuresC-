#ifndef patientType_h
#define patientType_h
#include "personType.h"
#include "doctorType.h"
#include "dateType.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class patientType: public personType
{
    public:
        patientType(string fName, string lName, int id, doctorType aPhisician, dateType dBirth, dateType aDate, dateType disDate) : personType(fName, lName)
        {
            attendingPhysician = aPhisician;
            dateOfBirth = dBirth;
            admitDate = aDate;
            dischargeDate = disDate;
            patientID = id;
        }
        patientType()
        {
            personType::setName(" ", " ");
            attendingPhysician = doctorType();
            dateOfBirth = dateType();
            dischargeDate = dateType();
            admitDate = dateType();

        }

        string getAttending()
        {
            string name = attendingPhysician.getFirstName() + attendingPhysician.getLastName();
            return name;
        }
        int getPatientID()
        {
            return patientID;
        }
        void printDateOfBirth()
        {
            dateOfBirth.getDate();
        }
        void printDischargeDate()
        {
            dischargeDate.getDate();
        }
        void printAdmitDate()
        {
            admitDate.getDate();
        }

        void print()
        {
            cout<<endl<<setw(25)<<""<<"Patient Summary"<<endl<<endl;
            cout<<setw(25)<<"Patient ID: "<<patientID<<endl;
            cout<<setw(25)<<"Name: "<<personType::getFirstName()<<" "<<personType::getLastName()<<endl;
            cout<<setw(25)<<"Date of Birth: ";
            dateOfBirth.getDate();
            cout<<setw(25)<<"Admission Date: ";
            admitDate.getDate();
            cout<<setw(25)<<"Discharge Date: ";
            dischargeDate.getDate();
        }

    private:
        int patientID;
        doctorType attendingPhysician;
        dateType dateOfBirth;
        dateType admitDate;
        dateType dischargeDate;

};





#endif
