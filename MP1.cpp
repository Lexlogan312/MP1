/*
* File: MP1.cpp
* Author: Alex Randall
* Date: 10/03/2024
*
* Description: Calculates the cost of donuts and apple fritters with tax and calculates the change owed.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
    // Constants for item prices
    const double regular = 0.75;
    const double fancy = 0.85;
    const double regularDozen = 7.99;
    const double fancyDozen = 8.49;
    const double fritter = 1.50;

    // Variables to store the number of each item ordered
    int numRegular = 0;
    int numFancy = 0;
    int numFritter = 0;
    int numRegularDozen = 0;
    int numFancyDozen = 0;

    // Variables for calculating cost and change
    double cost = 0;
    const double tax = 1.075;
    double total = 0;
    double payment = 0;
    double change = 0;

    // Input and stores the number of each item ordered
    cout << "Number of regular donuts ordered: ";
    cin >> numRegular;
    cout << "Number of fancy donuts ordered: ";
    cin >> numFancy;
    cout << "Number of apple fritters ordered: ";
    cin >> numFritter;

    // Calculates the number of dozens and remaining items
    numRegularDozen = numRegular / 12;
    numRegular = numRegular % 12;
    numFancyDozen = numFancy / 12;
    numFancy = numFancy % 12;

    // Calculates the total cost with tax
    cost = (numRegularDozen * regularDozen) + (numFancyDozen * fancyDozen) + (numRegular * regular) + (numFancy * fancy) + (numFritter * fritter);
    total = cost * tax;

    // Converts to two decimal places
    total = (int)(total * 100 + .5);
    total /= 100;

    // Output the total amount owed and inputs the amount paid
    cout << "Customer owes $" << total << endl;
    cout << "Customer pays $";
    cin >> payment;

    // Calculate the change owed
    change = (int)((payment*100) - (total*100));
    if(change != 0){
        cout << "Change owed is $" << change/100 << " - ";
    }
    else{
        cout << "Exact payment recieved - ";
    }

    // Calculate the change into dollars, quarters, dimes, nickels, and pennies
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

    // Outputs the change owed
    // Dollars
    if(dollars > 1){
        cout << dollars << " dollars";
    }
    else if(dollars == 1){
        cout << "1 dollar";
    }
    // If there is more change left, add a comma
    if(dollars != 0 && moduloChange % 100 != 0){
        moduloChange = moduloChange % 100;
        cout << ", ";
    }

    // Quarters
    if(quarters > 1){
        cout << quarters << " quarters";
    }
    else if(quarters == 1){
        cout << "1 quarter";
    }
    // If there is more change left, add a comma
    if(quarters != 0 && moduloChange % 25 != 0){
        moduloChange = moduloChange % 25;
        cout << ", ";
    }

    // Dimes
    if(dimes > 1){
        cout << dimes << " dimes";
    }
    else if(dimes == 1){
        cout << "1 dime";
    }
    // If there is more change left, add a comma
    if(dimes != 0 && moduloChange % 10 != 0){
        moduloChange = moduloChange % 10;
        cout << ", ";
    }

    // Nickels
    if(nickels > 1){
        cout << nickels << " nickels";
    }
    else if(nickels == 1){
        cout << "1 nickel";
    }
    // If there is more change left, add a comma
    if(nickels != 0 && moduloChange % 5 != 0){
        cout << ", ";
    }

    // Pennies
    if(pennies > 1){
        cout << pennies << " pennies";
    }
    else if(pennies == 1){
        cout << "1 penny";
    }

    // Output if there is no change owed
    if(change == 0){
        cout << "no change owed";
    }

    cout << ".";

    return 0;
}
