#include <iostream>
#include <iomanip>
#include <string>
#include "noServiceChargeChecking.h"
using namespace std;

class highInterestChecking: public noServiceChargeChecking
{
    public:
        highInterestChecking(int aNum, string name, double initialBalance):noServiceChargeChecking(aNum, name, initialBalance)
        {
            interestRate = 5;//high interestRate
            checksRemaining = -1;
            minimumBalance = 1500;
        }
        ~highInterestChecking(void){}
        
};