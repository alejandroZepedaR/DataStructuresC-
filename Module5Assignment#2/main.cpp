#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

// defining the structure to hold a single item
struct menuItemType{
    string menuItem;
    double menuPrice;
    int count;
};

// creating a type of struct
typedef struct menuItemType menuItemType;

// defining the constants
const int MAX_ITEMS = 100;
const int MAX_ORDERS = 10;
const double TAX_PERC = 5.0;

// function declaration
// function to read te file
int getData(menuItemType[], ifstream&);
// function to show menu to user and
// collect the orders and proceed to checkout
int showMenu(menuItemType[], int count);
// extra function to simulate the order taking
int getOrder(menuItemType[], int, menuItemType[]);
// function to print the bill
void printCheck(menuItemType[], int);

int main()
{
    // file reader object
    ifstream infile;
    // to store number of menu items
    // read in from file
    int numItems = 0;
    // to store number of orders
    int numOrders = 0; 
    // to store the filename
    string filename;
    // struct menuItemType array to hold
    // the items from the file
    menuItemType menuList[MAX_ITEMS];
    // array to hold the ordered item
    menuItemType order[MAX_ORDERS];
    // inputting the filename
    cout << "Please enter the filename which contains the menu items: ";
    getline(cin>>ws, filename);
    cout << endl;
    // opening the file
    infile.open(filename.c_str());
    // checking whether the file was opened successfuly or not
    if(!infile)
    {
        cout << "Error! The requested file '" << filename << "' was not found!" << endl;
        return -1;
    }
    // reading the file
    numItems = getData(menuList, infile);
    infile.close();
    cout << endl;
    // getting orders
    numOrders = getOrder(menuList, numItems, order);
    cout << endl;
    system("cls");
    cout << "**** Your Bill is ****" << endl << endl;
    // printing the bill
    printCheck(order, numOrders);
    cin.get();
}

// function to read the file and populate the menu item array
int getData(menuItemType menuList[], ifstream &infile)
{
    string line;
    int count = 0;
    string item;

    while( getline(infile, line, '$') != NULL)
    {
        // getting the position of new line char
        size_t indx = line.find('');
        // removing the new line character
        // from the string
        if(indx != string::npos)
        {
            line[indx] = '';
        }
        menuList[count].menuItem = line;
        infile >> menuList[count].menuPrice;
        count++;
        // checking if count equals max number
        // of items then break from the loop
        if(count == MAX_ITEMS)
        {
            break;
        }
    }
    return count;
}

// function to print the menu to user and get the selected item
// and return it
int showMenu(menuItemType menuList[], int count)
{
    int choice;
    // print the header
    cout << "WELCOME TO JOHNNY's RESTAURANT" << endl;
    cout << "------------------------------" << endl << endl;
    cout << "********** M E N U ***********" << endl << endl;
    cout << fixed << right << setprecision(2);

    do
    {
        // print the list of menu items
        for(int i = 0; i < count; i++)
        {
            cout << "[" << (i+1) << "] ";
            cout << setw(15)<< menuList[i].menuItem 
            << setw(5) << "$" << menuList[i].menuPrice << endl;
        }
        cout << "[0] Checkout" << endl;
        cout << "------------------------------" << endl;
        cout << "Please choose an item number: ";
        cin >> choice;
        if(choice < 0 || choice > count)
        {
            cout << "Invalid Choice! Choice must be in range 0 to " << count << endl;
        }
    }
    while(choice < 0 || choice > count);
    return choice;
}

// function to succesfuly get an order from customer and store the
// ordered items and quantity to order array
// and return number of orders
int getOrder(menuItemType menuList[], int count, menuItemType order[])
{
    int choice;
    int numOrders = 0;
    do
    {
        choice = showMenu(menuList, count);
        // checking whether choice was not 0
        if(choice != 0)
        {
            int qty;
            cout << "Enter the quantity: ";
            cin >> qty;
            order[numOrders] =  menuList[choice - 1];
            order[numOrders].count = qty;
            numOrders++;
            // checking if number of orders equals max orders
            // then break from the loop
            system("pause");
            system("cls");
            if(numOrders == MAX_ORDERS)
            {
                break;
            }
        }
        cout << endl;
    }
    while(choice != 0);
    return numOrders;
}

// function to generate and print the bill
void printCheck(menuItemType order[], int numOrders)
{
    double sumTotal = 0;
    double tax;
    double netAmt;
    if(numOrders == 0)
    {
        cout << "You didn't ordered any items." << endl;
        cout << "Exiting..." << endl;
        return;

    }
    cout << fixed << left << setprecision(2);
    cout << setw(15) << "ITEMS" << setw(10) << "QUANTITY"
     <<setw(15)<< "PRICE/UNIT" <<setw(10)<< "TOTAL PRICE" << endl;
     cout << "-------------------------------------------------" << endl;
     // looping for all the ordered items
     for(int i = 0; i < numOrders; i++)
     {
        // simulatenously calculating the total price for
        // each item
        double totPrice = order[i].count * order[i].menuPrice;
        // calculating the running total for all items
        sumTotal += totPrice;
        cout << setw(15) << order[i].menuItem << setw(10) << 
         order[i].count << setw(15)<< order[i].menuPrice << setw(10) << totPrice << endl;
     }
     // clculating tax
     tax = TAX_PERC * sumTotal / 100;
     // calculating the net payable amount
     netAmt = sumTotal + tax;
     cout << "==================================================" << endl;
     cout << "Amount total:	" <<"$" << sumTotal << endl;
     cout << "Tax @" << TAX_PERC << "% is:	"<<"$"<< tax << endl;
     cout << "Amount Due:	" << "$"<< netAmt << endl;
}