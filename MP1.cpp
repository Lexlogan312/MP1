/*
* File: MP1.cpp
* Author: Alex Randall
* Date: 10/03/2024
*
* Description: Calculates the cost of donuts and apple fritters, including tax, and calculates the change owed to the customer.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
    const double regular = 0.75;
    const double fancy = 0.85;
    const double regularDozen = 7.99;
    const double fancyDozen = 8.49;
    const double fritter = 1.50;

    int numRegular = 0;
    int numFancy = 0;
    int numFritter = 0;
    int numRegularDozen = 0;
    int numFancyDozen = 0;

    double cost = 0;
    const double tax = 1.075;
    double total = 0;
    double payment = 0;
    double change = 0;

    cout << "Number of regular donuts ordered: ";
    cin >> numRegular;
    cout << "Number of fancy donuts ordered: ";
    cin >> numFancy;
    cout << "Number of apple fritters ordered: ";
    cin >> numFritter;

    numRegularDozen = numRegular / 12;
    numRegular = numRegular % 12;
    numFancyDozen = numFancy / 12;
    numFancy = numFancy % 12;

    cost = (numRegularDozen * regularDozen) + (numFancyDozen * fancyDozen) + (numRegular * regular) + (numFancy * fancy) + (numFritter * fritter);
    total = cost * tax;
    total = (int)(total * 100 + .5);
    total /= 100;

    cout << "Customer owes $" << total << endl;
    cout << "Customer pays $";
    cin >> payment;
    change = (int)((payment*100) - (total*100));
    if(change != 0){
        cout << "Change owed is $" << change/100 << " - ";
    }
    else{
        cout << "Exact payment recieved - ";
    }
    int moduloChange = change;
    double changeLeft = change;
    int dollars = (int) (changeLeft / 100);
    changeLeft = changeLeft - (dollars * 100);
    int quarters = (int) (changeLeft / 25);
    changeLeft = changeLeft - (quarters * 25);
    int dimes = (int) (changeLeft / 10);
    changeLeft = changeLeft - (dimes * 10);
    int nickels = (int) (changeLeft / 5);
    changeLeft = changeLeft - (nickels * 5);
    int pennies = changeLeft;

    if(dollars > 1){
        cout << dollars << " dollars";
    }
    else if(dollars == 1){
        cout << "1 dollar";
    }
    if(dollars != 0 && moduloChange % 100 != 0){
        moduloChange = moduloChange % 100;
        cout << ", ";
    }

    if(quarters > 1){
        cout << quarters << " quarters";
    }
    else if(quarters == 1){
        cout << "1 quarter";
    }
    if(quarters != 0 && moduloChange % 25 != 0){
        moduloChange = moduloChange % 25;
        cout << ", ";
    }

    if(dimes > 1){
        cout << dimes << " dimes";
    }
    else if(dimes == 1){
        cout << "1 dime";
    }
    if(dimes != 0 && moduloChange % 10 != 0){
        moduloChange = moduloChange % 10;
        cout << ", ";
    }

    if(nickels > 1){
        cout << nickels << " nickels";
    }
    else if(nickels == 1){
        cout << "1 nickel";
    }
    if(nickels != 0 && moduloChange % 5 != 0){
        cout << ", ";
    }

    if(pennies > 1){
        cout << pennies << " pennies";
    }
    else if(pennies == 1){
        cout << "1 penny";
    }
    if(change == 0){
        cout << "no change owed";
    }
    cout << ".";
    return 0;
}
