#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum ticketType{ECONOMY, BUISNESS, FIRST_CLASS};

void displaySeatingTable(char arr[13][6])
{
    cout<<setw(9)<<"A"<<setw(4)<<"B"<<setw(4)<<"C"<<setw(4)<<"D"<<setw(4)<<"E"<<setw(4)<<"F"<<endl;
    for (int i = 0; i < 13; i++)
    {
        cout<<"Row "<<(i+1);
        for (int j = 0; j < 6; j++)
        {
            cout<<setw(4)<<arr[i][j];
            if(j == 5)
            {
                cout<<" "<<endl;
            }
        }
    }
}

ticketType getTicketType()
{
    char choice;
    bool valid = false;
    cout<<"Enter the desired ticket type"<<"(e)conomy, (b)uisness, (f)irst Class"<<endl;
    cin>>choice;

    while(valid == false){
        switch (choice)
        {
            case 'b':
                cout<<"You chose BUISNESS CLASS"<<endl;
                cout<<"rows 8 through 13"<<endl;
                return ECONOMY;
                valid = true;
                break;
            
            case 'e':
                cout<<"You chose ECONOMY CLASS"<<endl;
                cout<<"rows 3 through 7 are business class"<<endl;
                return ECONOMY;
                valid = true;
                break;
            
            case 'f':
                cout<<"You chose FIRST CLASS"<<endl;
                cout<<"Rows 1 and 2 are first class"<<endl;
                valid = true;
                return FIRST_CLASS;
                break;
            
            default:
                cout<<"You chose an invalid option. Try Again..."<<endl;
                cout<<"Enter the desired ticket type"<<"(e)conomy, (b)uisness, (f)irst Class"<<endl;
                cin>>choice;
                break;
        }
    }  
}

void buyTicket(char arr[13][6])
{
    ticketType chosenType;
    
    cout<<"The following table shows the available seats."<<endl;
    displaySeatingTable(arr);
    cout<<"Here, * indicates that the seat is available; X indicates that the seat is occupied."<<endl;
    chosenType = getTicketType();

}


int main()
{
    char airplaneSeats[13][6];

    for (int i = 0; i < 13; i++){

        for (int j = 0; j < 6; j++)
        {
            airplaneSeats[i][j] = '*';
        }
    }

    buyTicket(airplaneSeats);

    return 0;
}

