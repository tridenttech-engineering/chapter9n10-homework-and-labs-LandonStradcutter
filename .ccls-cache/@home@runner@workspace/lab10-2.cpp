#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void displayOptions ();
void getRegular(int windows, double price, double &total);
void getBoGo(int windows, double price, double &total);
int main ()
{
     int option = 0;
        int quantity = 0;
        double price = 0.0;
        double total = 0.0;
        cout << fixed << setprecision(2);
        displayOptions();
        cout << " If windows are on a discount enter 1, else enter 2: " << endl;
        cin >> option;

        if (option == 1 || option == 2)
        {
            cout << "Enter the number of windows: " << endl;
            cin >> quantity;
            cout << "Enter the price per window: " << endl;
            cin >> price;
            if (option == 1)
            {
                getBoGo(quantity, price, total);
                cout << "Total Price: $" <<
                    total << endl;
            }
            else
        {
            getRegular (quantity, price, total);
            cout << "Total Price: $" <<
                total << endl;
        }
    }
        else
        {
            cout << "Invalid option" << endl;
        }    


        return 0;
    } 
    void displayOptions()
    {
        cout << "Pricing Options" << endl;
        cout << "1 BoGo Windows" << endl;
        cout << "2 Regular Windows" << endl;
    }
    void getBoGo(int quantity, double price, double &total)
    {
        total = (price * quantity);
    }
    void getRegular(int quantity, double price, double &total)
    {
        total = (quantity / 2 + quantity % 2) * price;
}