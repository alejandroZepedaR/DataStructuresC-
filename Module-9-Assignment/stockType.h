#ifndef stockType_h
#define stockType_h
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class stockType
{
    friend ostream& operator<<(ostream&, stockType&);
    friend istream& operator>>(istream&, stockType&);

    public:
        stockType();

        string getSymbol();
        double getTotalValue();
        int getNumOfShares();
        double getOpeningPrice();
        double getClosingPrice();
        double getHighPrice();
        double getLowPrice();
        double getPreviousPrice();
        double getPercentGainLoss();

        void setSymbol(string);
        void setNumOfShares(int);
        void setOpeningPrice(double);
        void setClosingPrice(double);
        void setHighPrice(double);
        void setLowPrice(double);
        void setPerviousPrice(double);

        bool operator== (stockType&);
        bool operator!= (stockType&);
        bool operator<= (stockType&);
        bool operator< (stockType&);
        bool operator>= (stockType&);
        bool operator> (stockType&);
        
    private:
        string symbol;
        double totalValue;
        int numOfShares;
        double openingPrice;
        double closingPrice;
        double highPrice;
        double lowPrice;
        double previousPrice;
        double percentGainLoss;
};
#endif
