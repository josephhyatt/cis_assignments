#include <iostream>

using namespace std;

int main()
{
    double amount_due;
    double amount_received;
    double change_due;
    int change_due_cents;
    int quotient;
    cout << "Amount due:";
    cin >> amount_due;
    cout << "Amount received:";
    cin >> amount_received;

    change_due = amount_received - amount_due;
    cout << "\nChange due:" << change_due;

    //Dollars
    quotient = change_due;
    cout << "\n\nDollars: "<< quotient;

    //Converting to cents
    change_due_cents = (change_due - quotient + .001) * 100;

    //Quarters
    quotient = change_due_cents / 25;
    cout <<"\nQuarters: " << quotient;

    //Dimes
    change_due_cents = change_due_cents - (quotient * 25);
    quotient = change_due_cents / 10;
    cout << "\nDimes: "<< quotient;

    //Nickles
    change_due_cents = change_due_cents - (quotient * 10);
    quotient = change_due_cents / 5;
    cout << "\nNickles: "<< quotient;

    //Pennies
    change_due_cents = change_due_cents - (quotient * 5);
    quotient = change_due_cents;
    cout<<"\nPennies: "<< quotient;
}