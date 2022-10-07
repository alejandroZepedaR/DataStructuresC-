#include<iostream>
#include<string>
using namespace std;

double getDouble(string msg){
    double number;
    cout<<msg<<endl;
    cin>>number;
    return number;
}

int getInt(string msg){
    int number;
    cout<<msg<<endl;
    cin>>number;
    return number;
}

double getRoomsDiscount(int numberOfRooms){
    double discount = 0;
    if(numberOfRooms >= 10){
        discount = 0.10;
    }
    if(numberOfRooms >= 20){
        discount = 0.20;
    }
    if(numberOfRooms >= 30){
        discount = 0.30;
    }
    return discount;
}

double getDaysDiscount(int numberOfDays){
    double discount = 0;
    if(numberOfDays >= 3){
        discount = 0.05;
    }
    return discount;
}



int main()
{
    double costOfNight,  salesTax, subTotal, totalCost;
    int roomsBooked, daysBooked;

    costOfNight = getDouble("Enter the cost per night: ");
    roomsBooked = getInt("Enter the number of rooms booked: ");
    daysBooked = getInt("Enter the number of days you will be staying: ");
    salesTax = getDouble("Enter the Sales Tax: %");

    double roomsDiscount, daysDiscount, costPerOneRoom, roomDiscountAmount, dayDiscountAmount;

    roomsDiscount = getRoomsDiscount(roomsBooked);
    daysDiscount = getDaysDiscount(daysBooked);

    subTotal = roomsBooked * costOfNight;
    subTotal = subTotal * daysBooked;

    if(roomsDiscount > 0){
        roomDiscountAmount = subTotal * roomsDiscount;
        subTotal = subTotal - roomDiscountAmount;
    }

    if(daysDiscount > 0){
        dayDiscountAmount = subTotal * daysDiscount;
        subTotal = subTotal - dayDiscountAmount;
    }

    costPerOneRoom = subTotal/daysBooked;

    if(salesTax > 0){

        salesTax = salesTax/100;
        salesTax = salesTax * subTotal;
        totalCost = subTotal + salesTax;

    }else{
        totalCost = subTotal;
    }

    roomsDiscount = roomsDiscount * 100;
    daysDiscount = daysDiscount * 100;
    cout<<"Cost for room is : $"<<costPerOneRoom<<endl;
    if(roomsDiscount > 0){
        cout<<"The discount on each room is : "<<roomsDiscount<<"%"<<endl;
    }
    if(daysDiscount > 0){
        cout<<"There is an additional "<<daysDiscount<<"% Discount"<<endl;
    }
    cout<<"Days booked : "<<daysBooked<<endl;
    cout<<"Subtotal: $"<<subTotal<<endl;
    cout<<"Sales Tax: $"<<salesTax<<endl;
    cout<<"Total: $"<<totalCost<<endl;

    return 0;
}