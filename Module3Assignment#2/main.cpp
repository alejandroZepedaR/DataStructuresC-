#include <iostream>
using namespace std;

int main() {
    int num_flats = 0, n = 0, numVacant = 0;
    double rent_amount, rent_increment, maintenance_cost, max_profit = 0, profit;
    cout<<"Enter the total Number of units";
    cin>>num_flats;
    cout << "Enter rent when all units are occupied: ";
    cin >> rent_amount;
    cout << "Enter how much rent is increased: ";
    cin >> rent_increment;
    cout << "Enter amount to maintain a rented unit: ";
    cin >> maintenance_cost;
    while ((num_flats - numVacant) > 0) {
        profit = (num_flats - numVacant) * (rent_amount - maintenance_cost);
        if (profit > max_profit) {
            max_profit = profit;
            n = (num_flats - numVacant);
        }
        numVacant++;
        rent_amount += rent_increment;
    }
    cout << n << " units must be rented to maximize the profit" << endl;
    return 0;
}