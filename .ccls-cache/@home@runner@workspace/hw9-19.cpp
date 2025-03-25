//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <your name> on <current date>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototype
double getPayment(int, double, int);
double getTotal (double monthPay, int months);

int main()
{
    //declare variables
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;
    double totalCreditAmount = 0.0;
    double totalDealerAmount = 0.0;

    cout << "Car price (after any trade-in): " << endl;
    cin >> carPrice;
    cout << "Rebate: " << endl;
    cin >> rebate;
    cout << "Credit union rate: " << endl;
    cin >> creditRate;
    cout << "Dealer rate: " << endl;
    cin >> dealerRate;
    cout << "Term in years: " << endl;
    cin >> term;

    //call function to calculate payments
    creditPayment = getPayment(carPrice - rebate,
        creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, 
        dealerRate / 12, term * 12);    //assign values to calculate payments

// assign values to calculate payments
    totalCreditAmount= getTotal(creditPayment, term * 12);
    totalDealerAmount = getTotal(dealerPayment, term * 12);

    //display payments
    cout << fixed << setprecision(2) << endl; 
    cout << "Credit union payment: $" 
        << creditPayment << endl;
    cout << "Total amount with credit union: $"
        << totalCreditAmount << endl;
    cout << "Dealer payment: $"
        << dealerPayment << endl;
    cout << "Total amount with dealer: $"
        << totalDealerAmount << endl;

    return 0;
}//end of main function    

    //*****function definitions*****
double getPayment(int prin,
                  double monthRate, 
                  int months)
{
    //calculates and returns a monthly payment
    double monthPay = 0.0;

    if(1-pow(monthRate + 1, -months) ==0)
        monthPay = -1;
    else 
    monthPay = prin * monthRate / 
        (1 - pow(monthRate + 1, -months));
    return monthPay;
} //end of getPayment function

//*****function definition*****
    double getTotal(double monthPay, int months)
{
    //calculates and returns the total amount
    cout << fixed << setprecision(2) << endl;
    double roundedPay = 0.0;
    double total = 0.0;
    roundedPay = static_cast<int>((monthPay + .005) * 100) / 100.0;
    total = roundedPay * months;
    return total;
}
