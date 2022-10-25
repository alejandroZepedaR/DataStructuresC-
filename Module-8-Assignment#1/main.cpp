#include <iostream>
#include <string>
#include "doctorType.h"
#include "patientType.h"
#include "personType.h"
#include "dateType.h"
#include "billType.h"
using namespace std;

int main()
{

    doctorType doctor("Joaquin", "Zepeda", "Cardiologist");
    dateType patientBirth(9,9,1999);
    dateType discharge(5,3,2022);
    dateType admission(4,30,2022);

    patientType myPatient("Maria", "Romo",24576849, doctor, patientBirth, admission, discharge);

    myPatient.print();

    billType myBill(myPatient, 250, 500, 1500);
    myBill.print();

    return 0;
}