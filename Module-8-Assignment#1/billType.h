#ifndef billType_h
#define billType_h
#include "patientType.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class billType
{
    public: 
        billType(patientType id, double dFee, double pCharge, double rChanges)
        {
            patient = id;
            doctorFee = dFee;
            roomChanges = rChanges;
            pharmacyCharge = pCharge;
            hospitalCharges = doctorFee + roomChanges + pharmacyCharge;
        }

        int getID()
        {
            return patient.getPatientID();
        }
        double getHospitalCharges()
        {
            return hospitalCharges;
        }
        double getDoctorFee()
        {
            return doctorFee;
        }
        double getPharmacyCharges()
        {
            return pharmacyCharge;
        }
        double getRoomChanges()
        {
            return roomChanges;
        }
        void setDoctorFee(double dFee)
        {
            doctorFee = dFee;
        }
        void setRoomChanges(double rChanges)
        {
            roomChanges = rChanges;
        }
        void setPharmacyCharge(double pCharge)
        {
            pharmacyCharge = pCharge;
        }

        void print()
        {
            cout<<setw(60)<<setfill('-')<<""<<setfill(' ')<<endl;
            cout<<endl<<setw(25)<<""<<"Bill Summary"<<endl<<endl;
            cout<<setw(25)<<"Patient ID: "<<patient.getPatientID()<<endl;
            cout<<setw(25)<<"Doctor Fee: $"<<doctorFee<<endl;
            cout<<setw(25)<<"Pharmacy Charges: $"<<pharmacyCharge<<endl;
            cout<<setw(25)<<"Room Changes: $"<<roomChanges<<endl;
            cout<<setw(25)<<"Total Hospital Charges: $"<<hospitalCharges<<endl;
        }

    private:
        patientType patient;
        double hospitalCharges;
        double doctorFee;
        double pharmacyCharge;
        double roomChanges;

};

#endif